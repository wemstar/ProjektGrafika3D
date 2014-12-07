#include "scene.hpp"


#include <GL/glu.h>
#include "navigation.hpp"
#include <stdio.h>
void initOpenGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);



    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    glEnable(GL_LIGHT0);
    GLfloat light0_specular [4] = { 1.0,1.0,1.0,1 };
    GLfloat light0_diffuse [4] = { 0.5,0.5,0.5,1 };
    glLightfv(GL_LIGHT0,GL_SPECULAR,light0_specular);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light0_diffuse);

    glEnable(GL_LIGHT1);
    GLfloat light1_ambient [4] = { 0.0,0.0,0.0,1 };
    GLfloat light1_specular [4] = { 0.0,0.0,0.0,1 };
    GLfloat light1_diffuse [4] = { 0.5,0.5,0.5,1 };
    glLightfv(GL_LIGHT1,GL_AMBIENT,light1_ambient);
    glLightfv(GL_LIGHT1,GL_SPECULAR,light1_specular);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,light1_diffuse);


    GLfloat light_ambient_global [4] = { 2.0,2.0,2.0,1 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,light_ambient_global);
     

}




void drawScene()
{

    handleKeys();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glEnable(GL_FOG);

    float FogCol[3]={0.8f,0.8f,0.8f}; // Define a nice light grey
    glFogfv(GL_FOG_COLOR,FogCol);
    glFogi(GL_FOG_MODE, GL_LINEAR); // Note the 'i' after glFog - the GL_LINEAR constant is an integer.
    glFogf(GL_FOG_START, 2.0*player_z);
    glFogf(GL_FOG_END, 3.0*player_z);



    gluLookAt(player_x, player_y, player_z,
            player_x+80.0*cos(camera_theta)*cos(camera_fi), player_y+80.0*cos(camera_theta)*sin(camera_fi),player_z-80.0+80.0*sin(camera_theta),
            0.0, 0.0, 1.0);
    drawFlor();

    GLfloat mShininess[] = {50};

    GLfloat DiffuseMaterial[3]={1.0, 0.0, 0.0};
    if(water)
    {
        DiffuseMaterial[0]=0.0;
        DiffuseMaterial[1]=1.0;
    }

    GLfloat AmbientMaterial[] = {0.0, 0.0, 0.0};
    GLfloat SpecularMaterial[] = {1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DiffuseMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AmbientMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SpecularMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
    /*if(water)glUseProgram(p);
    else glUseProgram(w);*/
    glBegin(GL_TRIANGLES);
    for (int i = 0; i<map_width; i++)
    {

       
        glPushMatrix();
        glScalef(1.0, 1.0, water?world_map[i][2]:world_map[i][3]);
        glTranslatef((GLfloat)world_map[i][0]*block_size, (GLfloat)world_map[i][1]*block_size, 0.0/*(GLfloat)world_map[i][2]*0.5* block_size*/);
        //printf("%f %f\n",world_map[i][0],world_map[i][1]);
        
        glutSolidCube(block_size);
    
       
        

        glPopMatrix();
        

    }
    glEnd();






    glutSwapBuffers();
    glutPostRedisplay();
    glUseProgram(0);
}

void drawFlor()
{
    glBegin(GL_QUADS);
    // Lower left vertex
    glVertex3f(-2048.0f, -2048.0f, 0.0f);
    // Lower right vertex
    glVertex3f( -2048.0f, 1048576.0f, 0.0f);
    // Upper vertex
    glVertex3f( 1048576.0f,  1048576.0f, 0.0f);

    glVertex3f( 1048576.0f,  -2048.0f, 0.0f);
    /*for(int i=-2048;i<2048;i+=10)
        for(int j=-2048;j<2048;j+=10)
        {
            glVertex3f( (GLfloat)i, (GLfloat)j, -64.0f);
            glVertex3f( (GLfloat)i+10.0, (GLfloat)j, -64.0f);
            glVertex3f( (GLfloat)i, (GLfloat)j+10.0, -64.0f);
            glVertex3f( (GLfloat)i+10.0, (GLfloat)j+1.0, -64.0f);
        }*/

    glEnd();

}
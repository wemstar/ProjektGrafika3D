#include "scene.hpp"


#include <GL/glu.h>

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


    /*gluLookAt(//player_x,player_y,0.0,
            player_x+camera_distance*cos(camera_theta)*cos(camera_fi),
            player_y+camera_distance*sin(camera_theta),
            camera_distance*cos(camera_theta)*sin(camera_fi),

            camera_distance*cos(camera_theta+0.1)*cos(camera_fi),
            camera_distance*sin(camera_theta+0.1),
            camera_distance*cos(camera_theta+0.1)*sin(camera_fi),
            0.0,0.0,1.0);*/
    gluLookAt(player_x, player_y, 80.0,
            player_x+80.0*cos(camera_theta)*cos(camera_fi), player_y+80.0*cos(camera_theta)*sin(camera_fi),80.0*sin(camera_theta),
            0.0, 0.0, 1.0);
    drawFlor();

   /* GLfloat mShininess[] = {50};

    GLfloat DiffuseMaterial[] = {1.0, 0.0, 0.0};
    GLfloat AmbientMaterial[] = {0.0, 0.0, 0.0};
    GLfloat SpecularMaterial[] = {1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DiffuseMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AmbientMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SpecularMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);*/
    for (int i = 0; i<map_width; i++)
    {


        glPushMatrix();
        //glScalef(1.0, 1.0, world_map[i][2]);
        glTranslatef((GLfloat)world_map[i][0]*block_size, (GLfloat)world_map[i][1]*block_size, 0.0/*(GLfloat)world_map[i][2]*0.5* block_size*/);
        //printf("%f %f\n",world_map[i][0],world_map[i][1]);
        glutSolidCube(block_size);

        glPopMatrix();

    }




    glutSwapBuffers();
    glutPostRedisplay();
}

void drawFlor()
{
    glBegin(GL_QUADS);
    // Lower left vertex
    glVertex3f(-2048.0f, -2048.0f, -64.0f);
    // Lower right vertex
    glVertex3f( -2048.0f, 2048.0f, -64.0f);
    // Upper vertex
    glVertex3f( 2048.0f,  2048.0f, -64.0f);

    glVertex3f( 2048.0f,  -2048.0f, -64.0f);
    glEnd();

}
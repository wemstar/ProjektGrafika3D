#include "scene.hpp"

void initOpenGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);

    /*GLfloat fogColor[4] = {1.0f,1.0f,1.0f,1.0f};

    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogf(GL_FOG_START, 500.8f); // Fog Start Depth
    glFogf(GL_FOG_END, 6000.8f); // Fog End Depth
    glEnable(GL_FOG);*/

    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    glEnable(GL_LIGHT0);
    GLfloat light0_specular [4] = { 0.1,0.1,0.1,0.1 };
    GLfloat light0_diffuse [4] = { 0.1,0.1,0.1,0.1};
    glLightfv(GL_LIGHT0,GL_SPECULAR,light0_specular);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light0_diffuse);

    /*glEnable(GL_LIGHT1);
    GLfloat light1_ambient [4] = { 0.0,0.0,0.0,1 };
    GLfloat light1_specular [4] = { 0.0,0.0,0.0,1 };
    GLfloat light1_diffuse [4] = { 0.5,0.5,0.5,1 };
    glLightfv(GL_LIGHT1,GL_AMBIENT,light1_ambient);
    glLightfv(GL_LIGHT1,GL_SPECULAR,light1_specular);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,light1_diffuse);*/


    /*GLfloat light_ambient_global [4] = { 2.0,2.0,2.0,1 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,light_ambient_global);*/
}

void drawScene()
{

    handleKeys();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    gluLookAt(player_x+camera_distance*cos(camera_theta)*cos(camera_fi),
            player_y+camera_distance*sin(camera_theta),
            camera_distance*cos(camera_theta)*sin(camera_fi),
            player_x,player_y,0.0,
            camera_distance*cos(camera_theta+0.1)*cos(camera_fi),
            camera_distance*sin(camera_theta+0.1),
            camera_distance*cos(camera_theta+0.1)*sin(camera_fi));

    for (int i = 0; i<map_width; i++)
    {

        glPushMatrix();
        glScalef(1.0, 1.0, world_map[i][2]);
        glTranslatef((GLfloat)world_map[i][0]*block_size, (GLfloat)world_map[i][1]*block_size, world_map[i][2]);

        glutSolidCube(block_size);

        glPopMatrix();

    }




    glutSwapBuffers();
    glutPostRedisplay();
}
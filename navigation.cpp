#include "navigation.hpp"


#include <stdio.h>
void handleKeys()
{
    if (keys[27]) exit(0);
    if(keys['w'])
    {
        player_z+=10.0;
    }
    if(keys['s'])
    {
        player_z-=10.0;
    }
    if(keys['e'])
    {
        water=1;
    }
    if(keys['r'])
    {
        water=0;
    }
    if (specialkeys[GLUT_KEY_UP])
    {
        player_x += 80.0*cos(camera_theta)*cos(camera_fi);
        player_y+=80.0*cos(camera_theta)*sin(camera_fi);


    }
    if (specialkeys[GLUT_KEY_DOWN]){
        player_x -= 80.0*cos(camera_theta)*cos(camera_fi);
        player_y-=80.0*cos(camera_theta)*sin(camera_fi);


    }
    if (specialkeys[GLUT_KEY_LEFT])
    {
        player_y -= 80.0*cos(camera_theta)*cos(camera_fi);
        player_x-=80.0*cos(camera_theta)*sin(camera_fi);
    }

    if (specialkeys[GLUT_KEY_RIGHT]){
        player_y += 80.0*cos(camera_theta)*cos(camera_fi);
        player_x+=80.0*cos(camera_theta)*sin(camera_fi);
    }





}


void reshapeScreen(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 1600000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyDown(unsigned char key, int x, int y)
{
    keys[key] = true;
}
void keyUp(unsigned char key, int x, int y)
{
    keys[key] = false;
}
void specialKeyDown(int key, int x, int y)
{
    specialkeys[key] = true;
}
void specialKeyUp(int key, int x, int y)
{
    specialkeys[key] = false;
}
void mouseButton (int button,int state,int x,int y)
{
    mouse_button=-1;
    if (button==GLUT_LEFT_BUTTON)
    {
        mouse_button=button;
        if (state==GLUT_DOWN)
        {
            mouse_x=x;
            mouse_y=y;
        }
    }
}

void mouseMotion (int x,int y)
{
    if (mouse_button==GLUT_LEFT_BUTTON)
    {
        camera_fi+=2.0/glutGet(GLUT_WINDOW_WIDTH)*(x-mouse_x);
        camera_theta-=2.0/glutGet(GLUT_WINDOW_HEIGHT)*(mouse_y-y);
        mouse_x=x;
        mouse_y=y;
        glutPostRedisplay ();

    }
}
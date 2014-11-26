#pragma once
#include <GL/freeglut.h>
#include <math.h>
extern bool keys[256], specialkeys[256];


extern int mouse_button,mouse_x,mouse_y;





extern GLfloat player_x ;
extern GLfloat player_y;
extern GLfloat player_z;
extern int water;
extern float camera_distance,camera_theta,camera_fi;
extern float fov;
void handleKeys();
void reshapeScreen(int w, int h);
void keyDown(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);
void specialKeyDown(int key, int x, int y);
void specialKeyUp(int key, int x, int y);
void mouseButton (int button,int state,int x,int y);
void mouseMotion (int x,int y);
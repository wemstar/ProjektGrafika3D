#pragma once
#define block_size 64.0
#include "glew.h"
#include <GL/freeglut.h>

#define map_width 16384
#define map_height 4
extern GLuint v,f,p,w;
extern GLfloat world_map[map_width][map_height];
extern int water;
void initOpenGL();
void drawScene();
void drawFlor();
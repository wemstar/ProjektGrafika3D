#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glew.h"
#include <GL/freeglut.h>
void loadScene();


#define map_width 16384
#define map_height 4
extern GLfloat world_map[map_width][map_height];
float* loadRow(char* line, int num);
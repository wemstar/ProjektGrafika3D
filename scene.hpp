#pragma once
#define block_size 64.0
#include "glew.h"
#include <GL/freeglut.h>
#include "navigation.hpp"
#define map_width 22
#define map_height 3

extern GLfloat world_map[map_width][map_height];

void initOpenGL();
void drawScene();
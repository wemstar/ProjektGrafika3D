#pragma once
#include "glew.h"
#include <GL/freeglut.h>
#include <vector>
#include "SOIL.h"
extern GLuint v,f,p,w,pv,pf;
void setShaders();
void check_error(GLuint  shader);
GLuint loadBMP(const char * filename);
#pragma once
#include "glew.h"
#include <GL/freeglut.h>
#include <vector>
extern GLuint v,f,p,w,pv,pf;
void setShaders();
void check_error(GLuint  shader);
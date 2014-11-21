

#include <stdlib.h>
#include "glew.h"
#include <GL/freeglut.h>
#include "varibles.h"
#include "textfile.h"
#include "scene.hpp"
GLuint v,f,p;










void setShaders() {

    char *vs = NULL,*fs = NULL;

    v = glCreateShader(GL_VERTEX_SHADER);
    f = glCreateShader(GL_FRAGMENT_SHADER);

    vs = textFileRead("noise.vert");
    fs = textFileRead("noise.frag");

    const char * vv = vs;
    const char * ff = fs;

    glShaderSource(v, 1, &vv,NULL);
    glShaderSource(f, 1, &ff,NULL);

    free(vs);free(fs);

    glCompileShader(v);
    glCompileShader(f);

    p = glCreateProgram();
    glAttachShader(p,v);
    glAttachShader(p,f);

    glLinkProgram(p);
    glUseProgram(p);
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("GIS data visualization");

    initOpenGL();
    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshapeScreen);

    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);
    glutSpecialFunc(specialKeyDown);
    glutSpecialUpFunc(specialKeyUp);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);
    glewInit();
    setShaders();
    glutMainLoop();
    return 0;
}

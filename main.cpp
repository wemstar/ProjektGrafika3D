

#include <stdlib.h>
#include "glew.h"
#include <GL/freeglut.h>
#include "varibles.h"
#include "loadScene.hpp"
#include "scene.hpp"
#include "shadersLoaders.hpp"
#include "navigation.hpp"












int main(int argc, char** argv)
{
    loadScene();

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
    world_map[100][0]=1.0;
    world_map[100][1]=2.0;
    glutMainLoop();
    return 0;
}

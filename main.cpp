#include <math.h>

#include <stdlib.h>
#include "glew.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "textfile.h"
GLuint v,f,p;
bool keys[256], specialkeys[256];


int mouse_button,mouse_x,mouse_y;

#define block_size 64.0



GLfloat player_x = 80.0, player_y = 80.0;

float camera_distance=3.0,camera_theta=-90.0,camera_fi=180.0;
float fov=45.0;


#define map_width 22
#define map_height 3

GLfloat world_map[map_width][map_height]=
        {
                {1.0,1.0,1.0},
                {1.0,2.0,2.0},
                {1.0,3.0,3.0},
                {1.0,4.0,2.0},
                {1.0,5.0,2.0},
                {1.0,6.0,2.0},
                {1.0,7.0,2.0},
                {1.0,8.0,2.0},
                {1.0,9.0,2.0},
                {1.0,10.0,2.0},
                {1.0,11.0,2.0},
                {1.0,12.0,2.0},
                {3.0,1.0,2.0},
                {3.0,2.0,2.0},
                {3.0,3.0,2.0},
                {3.0,4.0,2.0},
                {3.0,5.0,2.0},
                {3.0,6.0,2.0},
                {3.0,7.0,2.0},
                {3.0,8.0,2.0},
                {3.0,9.0,2.0},
                {3.0,10.0,2.0},





        };



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

void handleKeys()
{
    if (keys[27]) exit(0);
    if (specialkeys[102]) player_x += 5.0;
    if (specialkeys[100]) player_x -= 5.0;
    if (specialkeys[101])
            player_y  -= 5.0;

    if (specialkeys[103])
        player_y +=5.0;




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

void reshapeScreen(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 1600.0f);
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

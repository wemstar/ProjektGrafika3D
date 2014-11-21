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

bool keys[256],specialkeys[256];

float a=0.0;
GLuint v,f,p;
float lpos[4] = {1,0.5,1,0};

void handleKeys()
{
    if(keys[27]) exit(0);
}

void initOpenGL()
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glEnable(GL_DEPTH_TEST);
   
   //dla s6 - toon shader
   
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    glEnable(GL_LIGHT0);
    GLfloat light0_specular [4] = { 1.0,1.0,1.0,1 };
    GLfloat light0_diffuse [4] = { 0.5,0.5,0.5,1 };
    glLightfv(GL_LIGHT0,GL_SPECULAR,light0_specular);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light0_diffuse);

    glEnable(GL_LIGHT1);
    GLfloat light1_ambient [4] = { 0.0,0.0,0.0,1 };
    GLfloat light1_specular [4] = { 0.0,0.0,0.0,1 };
    GLfloat light1_diffuse [4] = { 0.5,0.5,0.5,1 };
    glLightfv(GL_LIGHT1,GL_AMBIENT,light1_ambient);
    glLightfv(GL_LIGHT1,GL_SPECULAR,light1_specular);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,light1_diffuse);


    GLfloat light_ambient_global [4] = { 2.0,2.0,2.0,1 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,light_ambient_global);


}

void drawScene()
{
    handleKeys();    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    gluLookAt(0.0,0.0,5.0, 0.0,0.0,-1.0,0.0f,1.0f,0.0f);
    
    //begin uniform - dla s2
    /*
    GLint loc;
    GLfloat scale=2.0+0.5*sin(a/10.0);
    loc = glGetUniformLocation(p,"Scale");
	glUniform1f(loc,scale);
	*/
	//end uniform
	
	//begin - dla s3
	/*
    GLint loc;
    loc = glGetUniformLocation(p,"color");
	glUniform3f(loc,0.8,1.0+0.5*sin(a/10.0),0.4);	
    */	
    //end dla s3
    
    //begin uniform - dla s5
/*
    GLint loc;
    loc = glGetUniformLocation(p,"alfa");
	glUniform1f(loc,a/10.0);
*/
	//end uniform
	
    
    glRotatef(a,0,1,0);
    glutSolidTeapot(1);
    a=a+0.01;
    
    glutSwapBuffers();
    glutPostRedisplay();
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

void keyDown(unsigned char key, int x,int y)
{
    keys[key]=true; 
}

void keyUp(unsigned char key, int x,int y)
{
    keys[key]=false; 
}
        
void specialKeyDown(int key, int x, int y)
{
    specialkeys[key]=true;
}
    
void specialKeyUp(int key, int x, int y)
{
    specialkeys[key]=false;
}

void reshapeScreen(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
        
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("OpenGL - Szablon ...");
    initOpenGL();
   
    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshapeScreen);
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);
    glutSpecialFunc(specialKeyDown);
    glutSpecialUpFunc(specialKeyUp);
glewInit();
    setShaders(); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!    
    glutMainLoop();
    return 0;
}

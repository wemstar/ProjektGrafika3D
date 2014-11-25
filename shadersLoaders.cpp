#include "shadersLoaders.hpp"
#include "textfile.h"
void setShaders() {

    char *vs = NULL,*fs = NULL;

    v = glCreateShader(GL_VERTEX_SHADER);
    f = glCreateShader(GL_FRAGMENT_SHADER);

    vs = textFileRead("s7.vert");
    fs = textFileRead("s7.frag");

    const char * vv = vs;
    const char * ff = fs;

    glShaderSource(v, 1, &vv,NULL);
    glShaderSource(f, 1, &ff,NULL);

    free(vs);free(fs);

    glCompileShader(v);
    glCompileShader(f);
    GLint isCompiled = 0;
    glGetShaderiv(v, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled)
    {
        printf("Shader compile sucesfully\n");
    }
    glGetShaderiv(f, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled)
    {
        printf("Shader compile sucesfully\n");
    }
    p = glCreateProgram();
    glAttachShader(p,v);
    glAttachShader(p,f);

    glLinkProgram(p);
    glUseProgram(p);
}
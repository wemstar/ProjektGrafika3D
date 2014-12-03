#include "shadersLoaders.hpp"
#include "textfile.h"
void setShaders() {

    char *vs = NULL,*fs = NULL, *vp = NULL,*fp = NULL;

    v = glCreateShader(GL_VERTEX_SHADER);
    f = glCreateShader(GL_FRAGMENT_SHADER);

    pv = glCreateShader(GL_VERTEX_SHADER);
    pf = glCreateShader(GL_FRAGMENT_SHADER);

    vs = textFileRead("water.vert");
    fs = textFileRead("water.frag");

    vp = textFileRead("power.vert");
    fp = textFileRead("power.frag");

    const char * vv = vs;
    const char * ff = fs;

    const char * vx = vp;
    const char * fx = fp;

    glShaderSource(v, 1, &vv,NULL);
    glShaderSource(f, 1, &ff,NULL);

    glShaderSource(pv, 1, &vx,NULL);
    glShaderSource(pf, 1, &fx,NULL);

    free(vs);free(fs);

    glCompileShader(v);
    glCompileShader(f);
    glCompileShader(pv);
    glCompileShader(pf);
    GLint isCompiled = 0;
    glGetShaderiv(v, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled)
    {
        printf("Shader compile sucesfully\n");
    }else check_error(v);
    glGetShaderiv(f, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled)
    {
        printf("Shader compile sucesfully\n");
    }else check_error(f);
    glGetShaderiv(pv, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled)
    {
        printf("Shader compile sucesfully\n");
    }else check_error(pv);
    glGetShaderiv(pf, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled)
    {
        printf("Shader compile sucesfully\n");
    }
    else check_error(pf);
    w = glCreateProgram();
    glAttachShader(w,pv);
    glAttachShader(w,pf);
    p = glCreateProgram();
    glAttachShader(p,v);
    glAttachShader(p,f);

    glLinkProgram(p);
    glLinkProgram(w);

}

void check_error(GLuint  shader)
{
    GLint n;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &n);
    if( n == GL_FALSE ) {
        GLchar *info_log;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &n);
        info_log = (char*)malloc(n);
        glGetShaderInfoLog(shader, n, &n, info_log);
        fprintf(stderr, "Shader compilation failed: %*s\n", n, info_log);
        free(info_log);
    }
}
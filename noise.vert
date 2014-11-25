uniform float time;

void main(void)
{
vec4 a=gl_Vertex;
a.z=a.z*sin(time);
gl_Position=gl_ModelViewProjectionMatrix * a;
}
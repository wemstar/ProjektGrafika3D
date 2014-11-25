uniform float time;

void main()
{
	vec4 pos = gl_Vertex;
	pos.z=pos.z*sin(time);
	gl_Position = gl_ModelViewProjectionMatrix * pos;
}
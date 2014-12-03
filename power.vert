varying float intensity;
varying float z;
void main()
{
	vec3 lightDir = normalize(vec3(gl_LightSource[0].position));
	intensity = dot(lightDir,gl_Normal);
	z=1.0;
	gl_Position = ftransform();
}

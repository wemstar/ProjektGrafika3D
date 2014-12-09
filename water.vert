varying float intensity;
varying vec2 vTexCoord;
void main()
{
	vTexCoord = gl_MultiTexCoord0.rg;
	vec3 lightDir = normalize(vec3(gl_LightSource[0].position));
	intensity = dot(lightDir,gl_Normal);
	gl_Position = ftransform();
}
varying float intensity;
uniform sampler2D myTexture;
varying vec2 vTexCoord;
void main()
{

  vec4 color = vec4(0.0,0.0,0.1,1.0);
  color=color*(intensity+0.1);


  gl_FragColor = texture2D(myTexture, vTexCoord)+color;

}
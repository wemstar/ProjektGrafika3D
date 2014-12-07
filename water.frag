varying float intensity;


void main()
{
  
  vec4 color = vec4(0.0,0.0,1.0,1.0);
  color=color*(intensity+0.1);
  gl_FragColor = color;

}
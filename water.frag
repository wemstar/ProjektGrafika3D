varying float intensity;


void main()
{
  vec4 color;
  if (intensity > 0.95)

    color = vec4(0.0,0.0,0.5,0.5);
  else if (intensity > 0.5)
    color = vec4(0.0,0.0,0.3,0.3);
  else if (intensity > 0.25)
    color = vec4(0.0,0.0,0.2,0.1);
  else
    color = vec4(0.0,0.0,0.1,0.1);
  gl_FragColor = color;

}
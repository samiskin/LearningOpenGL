#version 120
//varying: shared between shader
varying vec2 texCoord0;

// uniform: variable both CPU and GPU has access to
uniform sampler2D diffuse;

void main()
{
//  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
//OpenGL does coordinates from 0 to 1, bottom left to top right

  gl_FragColor = texture2D(diffuse, texCoord0);
}

#version 120
//varying: shared between shader
varying vec2 texCoord0;
varying vec3 normal0;

// uniform: variable both CPU and GPU has access to
uniform sampler2D sampler;

void main()
{
//  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
//OpenGL does coordinates from 0 to 1, bottom left to top right

  gl_FragColor = texture2D(sampler, texCoord0) *
    clamp(dot(-vec3(0, 0, 1), normal0), 0.0, 1.0); // lambersion lighting, vec is the light direction
}

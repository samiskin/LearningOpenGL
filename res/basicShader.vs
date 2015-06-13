#version 120

attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;

varying vec2 texCoord0;
varying vec3 normal0;

// uniform: can be set by the CPU
uniform mat4 transform;

void main()
{
  // the 1.0 would change how much the matrix affects the position
  gl_Position = transform * vec4(position, 1.0);
  texCoord0 = texCoord;
  normal0 = (transform * vec4(normal, 0.0)).xyz; // no translation on normal
}


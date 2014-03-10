#version 150

uniform float time;
uniform mat4 modelViewProjectionMatrix;

in vec4 position;
//in vec4 normal;
in vec4 texcoord;
in vec4 color;
out vec4 colorOut;


void main( void ) {
    colorOut = vec4(texcoord.xy,
                    .5 * (1. + sin(time +  texcoord.x + texcoord.y)),
                    color.a);
    gl_Position = modelViewProjectionMatrix *
                vec4(position.xy,
                     position.z + 400. * .5 * (1. + sin(time + texcoord.x + texcoord.y )) ,
                     1.);
}
#version 150

uniform float time;
uniform mat4 modelViewProjectionMatrix;
uniform float modelDepth;
uniform float amtModifyPosition;

in vec4 position;
in vec4 texcoord;
in vec4 color;
out vec4 colorOut;


void main( void ) {
    float shift = .5 * (1. + sin(time +  texcoord.x + texcoord.y));
    vec2 v = vec2(0.,modelDepth * shift);
    colorOut = vec4(texcoord.xy, shift, color.a);
    vec4 targetPosition = position + mix(v.xx, v, amtModifyPosition).xxyx;
    gl_Position = modelViewProjectionMatrix * targetPosition;
    
}
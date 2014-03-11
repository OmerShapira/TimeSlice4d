/* Clip Shader */

#version 150

uniform vec2 range;

uniform mat4 modelViewProjectionMatrix;
uniform float modelDepth;
uniform float amtModifyPosition;

in vec4 position;
in vec4 texcoord;
in vec4 color;
out vec4 colorOut;


/*
 * For now, the shift is simple between left and right
 * inPoint ------> outPoint
 *       0 ------> 1
 */

void main( void ) {
    float shift = mix(range.x, range.y, texcoord.x);
    colorOut = vec4(texcoord.xy, shift, color.a);
    vec4 targetPosition = mix(position,
                              position + vec2(0.,modelDepth * shift).xxyx,
                              amtModifyPosition);
    gl_Position = modelViewProjectionMatrix * targetPosition;
    
}
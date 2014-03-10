#version 150

uniform float time;
uniform sampler3D tex;

in vec4 colorOut;
out vec4 fragColor;

void main( void ) {
    vec4 col = texture(tex, colorOut.rgb);
    fragColor = vec4(col.xyz, colorOut.a);
}
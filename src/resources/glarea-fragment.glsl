#version 330 core
out vec4 color;
void main(){
  vec2 circCoord = 2.0 * gl_PointCoord - 1.0;
  // if (dot(circCoord, circCoord) > 1.0) {
  //     discard;
  // }else{
    color = mix(vec4(1.0, 1.0, 1.0, 1.0), vec4(0.9, 0.9, 0.9, 0.0), smoothstep(0.68, 1.0, dot(circCoord, circCoord)));
  // }
}
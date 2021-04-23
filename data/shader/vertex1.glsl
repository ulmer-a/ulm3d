#version 330 core
layout (location = 0) in vec3 pos;

uniform mat4 u_MVP;

out vec3 fragPos;
out vec3 fragNormal;

void main()
{
    gl_Position = u_MVP * vec4(pos, 1.0);
    fragPos = pos;
    fragNormal = vec3(0.0f, 1.0f, 0.0f);
}

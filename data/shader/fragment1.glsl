#version 330 core

in vec3 fragPos;
in vec3 fragNormal;
out vec4 fragColor;

void main()
{
    vec4 objColor = vec4(0.5f, 0.5f, 0.5f, 1.0f);
    vec3 lightPos = vec3(0.0f, 1.5f, 0.0f);

    vec3 l = normalize(lightPos - fragPos);
    float cosTheta = dot(l, fragNormal);
    fragColor = objColor * max(cosTheta, 0.0f);
}

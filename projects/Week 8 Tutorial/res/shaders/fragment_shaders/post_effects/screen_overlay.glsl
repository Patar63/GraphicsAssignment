#version 430

layout(location = 0) in vec2 inUV;
layout(location = 0) out vec3 outColor;

uniform layout(binding = 0) sampler2D s_Image;
uniform layout(binding = 1) sampler2D t_Image;

void main()
{
	vec3 BaseColor = texture(s_Image, inUV).rgb;
	vec3 TopColor = texture(t_Image, inUV).rgb;

	outColor = vec3(1.0) - (vec3(1.0) - BaseColor) * (vec3(1.0) - TopColor);
}
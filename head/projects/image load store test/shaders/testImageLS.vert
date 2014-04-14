#version 430

uniform mat4 PVM;
uniform mat3 NormalMatrix;

uniform vec4 lightDirection;

in vec4 position;
in vec4 normal;
in vec4 texCoord0;

out vec3 Normal;

void main()
{
	Normal = normalize(NormalMatrix * vec3(normal));
	gl_Position = PVM * position;
}
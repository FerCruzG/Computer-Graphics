#version 330

in vec3 VertexPosition;
in vec3 VertexColor;
in vec3 VertexNormal;
in vec2 VertexTexCoord;

out vec3 InterpolatedColor;
out vec3 pposition;
out mat3 NormalMatrix;
out vec3 normal;
out vec2 InterpolatedTexCoord;
out vec4 PixelPositionLightSpace;

uniform mat4 mvpMatrix;
uniform mat4 LightVPMatrix;

void main(){
	NormalMatrix = transpose(inverse(mat3(mvpMatrix)));
	pposition = vec3(mvpMatrix * vec4(VertexPosition, 1.0f));
	InterpolatedColor = VertexColor;
	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
	normal = VertexNormal;
	InterpolatedTexCoord = VertexTexCoord;
	PixelPositionLightSpace = LightVPMatrix * vec4(pposition, 1.0);
}

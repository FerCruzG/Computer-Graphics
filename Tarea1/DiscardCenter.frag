#version 330

in vec3 InterpolatedColor;

out vec4 FragColor;


void main(){
	FragColor = vec4(InterpolatedColor, 0.0f);
	vec2 pixelPositionInWindow = gl_FragCoord.xy;
	int resol = 650;
	int centro = resol/2;

	if (centro < 175) {
		discard;
	}
	}

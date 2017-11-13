#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include <IL/il.h>


class Depthbuffer {
public:
	Depthbuffer();
	~Depthbuffer();
	void Create(int resolution);
	void Bind();
	void Unbind();
	void BindDepthMap();
	void UnbindDepthMap();

private:
	GLuint _framebuffer =0;	//id del framebuffer
	GLuint _depthmap = 0;	//id de la textura
	GLsizei _resolution = 0;//resolucion de la textura
};
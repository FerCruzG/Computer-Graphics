#include "Depthbuffer.h"

Depthbuffer::Depthbuffer(){
	_framebuffer = 0;	//id del framebuffer	GLuint
	_depthmap = 0;		//id de la textura		GLuint
	_resolution = 0;	//resolucion
}

Depthbuffer::~Depthbuffer(){
}

void Depthbuffer::Create(int resolution){
	_resolution = resolution;
	glGenFramebuffers(1, &_framebuffer);
	// Activan el framebuffer.

	// Configurarlo para no utilizar un buffer de color

	// Crean una textura _depthmap
	glGenTextures(1, &_depthmap);
	// activar la textura
	// configurar la textura -> filtro / wrap
	// datos de la textura
	//glTexImage2D(

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, _depthmap, 0);
}

void Depthbuffer::Bind(){
	glBindFramebuffer(GL_FRAMEBUFFER, _framebuffer);	
}

void Depthbuffer::Unbind(){
	glDeleteFramebuffers(_resolution, &_framebuffer);
}

void Depthbuffer::BindDepthMap(){
}

void Depthbuffer::UnbindDepthMap(){
}

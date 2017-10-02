/*********************************************
Materia: Gr�ficas Computacionales
Fecha: 02 de Octubre del 2017
Autor: A01373179 Maria Fernanda Cruz Gonzalez
**********************************************/
#pragma once
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

class ShaderProgram {
public:
	//Constructores 
	ShaderProgram();
	void CreateProgram();
	void AttachShader(std::string path, GLenum type);
	void LinkProgram();
	void Activate();
	void Deactivate();
	void SetAttribute(GLuint locationIndex, std::string name);
	void SetUniformf(std::string name, float value);
	void SetUniformf(std::string name, float x, float y);
	void SetUniformf(std::string name, float x, float y, float z);
	void SetUniformf(std::string name, float x, float y, float z, float w);


private:		//variables
	GLuint _programHandle = 0;

	//std::vector<std::unique_ptr<Shader>> _attachedShaders;
	void DeleteAndDetachShaders();
	void DeleteProgram();
};

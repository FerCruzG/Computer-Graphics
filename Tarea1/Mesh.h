/*********************************************
Materia: Gráficas Computacionales
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

class Mesh {	//declaracion de la clase Circle
public:
	//Constructores 
	Mesh();
	~Mesh();
	void CreateMesh(GLint vertexCount);
	void Draw(GLenum primitive);

	void SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex);
	void SetPositionAttribute(std::vector<glm::vec3> positions, GLenum usage, GLuint locationIndex);
	void SetColorAttribute(std::vector<glm::vec3>colors, GLenum usage, GLuint locationIndex);
	void SetColorAttribute(std::vector<glm::vec4>colors, GLenum usage, GLuint locationIndex);
	

private:		//variables
	GLuint _vertexArrayObject = 0;
	GLuint _positionsVertexBufferObject = 0;
	GLuint _colorsVertexBufferObject = 0;
	GLint _vertexCount = 0;

	void SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void* data, GLenum usage,
		GLuint locationIndex, const GLint components);
};

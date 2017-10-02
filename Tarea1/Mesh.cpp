/*********************************************
Materia: Gráficas Computacionales
Fecha: 02 de Octubre del 2017
Autor: A01373179 Maria Fernanda Cruz Gonzalez
**********************************************/
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "Mesh.h"

Mesh::Mesh()
{
}

void Mesh::CreateMesh(GLint vertexCount)
{
}

void Mesh::Draw(GLenum primitive)
{
}

void Mesh::SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex)
{
}

void Mesh::SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex)
{
}

void Mesh::SetAttributeData(GLuint & buffer, const GLsizeiptr size, const void * data, GLenum usage, GLuint locationIndex, const GLint components)
{
}

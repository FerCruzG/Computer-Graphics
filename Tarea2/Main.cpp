/*********************************************
Materia: Gráficas Computacionales
Fecha: 20 de Agosto del 2017
Autor: A01373179 Maria Fernanda Cruz Gonzalez
**********************************************/

#include "InputFile.h"
#include <iostream>

//Clase main creada por el profesor para ejecutar pruebas
int main(int argc, char* argv[]) {
	std::string filename = "Prueba.txt";
	InputFile myFile;
	myFile.Read(filename);
	std::string contents = myFile.GetContents();

	std::cout << "Contents: " << contents << std::endl;
	std::cin.get();
}
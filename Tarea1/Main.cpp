/*********************************************
	Materia:	Graficas Computacionales
	Fecha:		Agosto 13, 2017
	Autor:		Maria Fernanda Cruz Gonzalez
**********************************************/
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Employee.h"
#include "InputFile.h"
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

//identificador del manager
GLuint vao;

//identificador del manager de los shaders (ShaderProgram)
GLuint shaderProgram;

//float vertsPerFrame = 0.0f;
//float delta = 0.40f;

//PROBLEMA 1
int PerimetroRectangulo(int base, int altura) {
	int total;
	total = (base*2) + (altura*2);
	return total;
	}

//PROBLEMA 2
float AreaTriangulo(float base, float altura) {
	float total;
	total = (base*altura) / 2.0f;
	return total;
}

//PROBLEMA 3
int Mayor(int a, int b, int c) {
	if (a > b && a > c) {
		return a;
	}
	else if (b > a && b > c) {
		return b;
	}
	else {
		return c;
	}
}

//PROBLEMA 4
int Menor(int a, int b, int c) {
	if (a < b && a < c) {
		return a;
	}
	else if (b < a && b < c) {
		return b;
	}
	else {
		return c;
	}
}

//PROBLEMA 5
void FilaEstrellas(int n) {
	while (n > 0) {
		std::cout << "*";
		n--;
	}
	std::cout << std::endl;
}

//PROBLEMA 6
void MatrizEstrellas(int n) {
	int x = n;
	while (n > 0) {
		FilaEstrellas(x);
		n--;
	}
}

//PROBLEMA 7
void PiramideEstrellas(int n) {
	int x = 1;
	int y = n + 1;
	while (x < y) {
		FilaEstrellas(x);
		x++;
	}
}

//PROBLEMA 8
void FlechaEstrellas(int n) {
	PiramideEstrellas(n);
	while (n > 0) {
		FilaEstrellas(n-1);
		n--;
	}
}

//PROBLEMA 9
void Fibonacci(int n) {
	int x = 1;
	int y = 1;
	int z = x + y;

	for (int i = 1; i <= n; i++) {
		std::cout << " " << x;
		x = y;
		y = z;
		z = x + y;
	}
	std::cout << std::endl;
}

//PROBLEMA 10
bool EsPrimo(int n) {
	for (int i = 2; i < n;i++) {
		if (n%i == 0) {
			return false;
		}
		else {
			return true;
		}
	}
}

void Initialize(){//solo se llama una vez; crea toda la memoria que el prgrama va a utilizar
	//lista de elemntos
	std::vector<glm::vec2> positions;
	std::vector<glm::vec3>colors;
	//claramente en el CPU y RAM , no tarjeta de video
	//inserta un elemento al final de la lista

	/*float angle = 0;	
	//positions.push_back(glm::vec2(0.0f, 0.0f));
	float radio = 1.0f;
	float radio2 = 0.5f;
	float R = 0.0f;
	float G = 0.0f;
	float B = 0.0f;

	positions.push_back(glm::vec2(0.0, 1.0));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));

	for (int i = 0; i <= 361; i++) {
		float j = i;

		float x = radio * cos(i);
		float y = radio * sin(i);	
		
		positions.push_back(glm::vec2(x, y));
		colors.push_back(glm::vec3(x,y,	x*y));

		//std::cout << "For = " << x << " " <<y <<std::endl;
		angle++;
	}	*/
	//positions.push_back(glm::vec2(x,y));	//1
	/*positions.push_back(glm::vec2(.95f, 0.2f)); //2
	
	//lista ligadallamada 'colors'
	
	/*	colors.push_back(glm::vec3(0.0f, 0.0f, 0.0f));*/

	positions.push_back(glm::vec2(0.6f,-0.8f));		//1
	positions.push_back(glm::vec2(0.95f, 0.3f));	//2		
	positions.push_back(glm::vec2(0.45f, 0.15f));	//3
	positions.push_back(glm::vec2(0.0f, 1.0f));		//4
	positions.push_back(glm::vec2(0.0f, 0.5f));		//5
	positions.push_back(glm::vec2(-0.95f, 0.3f));	//6
	positions.push_back(glm::vec2(-0.45f, 0.15f));	//7
	positions.push_back(glm::vec2(-0.6f, -0.8f));	//8
	positions.push_back(glm::vec2(-0.3f, -0.4f));	//9
	positions.push_back(glm::vec2(0.6f, -0.8f));	//1
	positions.push_back(glm::vec2(0.3f, -0.4f));	//11
	positions.push_back(glm::vec2(0.45f, 0.15f));	//3

	colors.push_back(glm::vec3(0.0f, 0.749f, 1.0f));
	colors.push_back(glm::vec3(0.196f, 0.804f, 0.196f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.271f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.078f, 0.576f));
	colors.push_back(glm::vec3(0.545f, 0.0f, 0.545f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.749f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	glGenVertexArrays(1, &vao);
	//todos los VBOs creados y configurados 
	glBindVertexArray(vao);
	//identificador del VBO de posiciones
	GLuint positionsVBO;
	//creacion del VBO de posiciones
	glGenBuffers(1, &positionsVBO);//pasa ese numero como referencia 
	//Ativar el buffer de posiiones para poder utilizarlo
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	//creamos la memoria y la i nicializamos con los datos del atributo de posicoines
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(), positions.data(), GL_STATIC_DRAW);
	//Activar el atributo en la tarjeta de video
	glEnableVertexAttribArray(0);
	//configuramos los datos del atributo en la tarjeta de video
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	//ya no usaremos este VBO en este momento
	glBindBuffer(GL_ARRAY_BUFFER , 0);

	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);									//eficiente leer muchas veces
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*colors.size(), colors.data(),GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE,0,nullptr);


	//Desactivar manager
	glBindVertexArray(0);

	//crar objeto para leer archivos
	InputFile ifile;

/*--------------------------- V E R T E X  S H A D E R --------------------------------*/

	//cargar el VERTEX SHADER	
	ifile.Read("Default.vert");
	//guardar codigo fuente en un string 
	std::string vertexSource = ifile.GetContents();
	//creacion de shader tipo vertex y guardamos su identificador en una variable
	GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	const GLchar * vertexSource_c = (const GLchar*)vertexSource.c_str();
	//estamos dando el codigo fuente a OpenGl para que s elo asigne al shader
	glShaderSource(vertexShaderHandle, 1, &vertexSource_c, nullptr);
	//compilar shader en busca de errores
	//asumir que no hay ningun error
	glCompileShader(vertexShaderHandle);

/*--------------------------- F R A G M E N T  S H A D E R --------------------------------*/

	ifile.Read("Default.frag");
	std::string fragmentSource = ifile.GetContents();
	GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar *fragmentSource_c = (const GLchar*)fragmentSource.c_str();
	glShaderSource(fragmentShaderHandle, 1, &fragmentSource_c, nullptr);
	glCompileShader(fragmentShaderHandle);

	//cramos el identificador para le manager de los shaders
	shaderProgram = glCreateProgram();
	//adjuntamos el vertex shader al manager (van a trabajar juntos)
	glAttachShader(shaderProgram, vertexShaderHandle);
	//adjuntamos el fragment shader al manager (van a trabajar juntos)
	glAttachShader(shaderProgram, fragmentShaderHandle);
	//asociamos un uffer con inidice 0 (posiciones) a la variable VertexPosition
	glBindAttribLocation(shaderProgram, 0, "VertexPositon");
	//asociamos un uffer con inidice 1 (colores) a la variable VertexColor
	glBindAttribLocation(shaderProgram, 1, "VertexColor");
	//binding de uniforms

	//ejecutamos el proceso de linker (aseguramos que el vertex y fragment son compatibles)
	glLinkProgram(shaderProgram);
	//Manager para usar un uniform
	glUseProgram(shaderProgram);				//del shader	variable
	GLint uniformLocation = glGetUniformLocation(shaderProgram, "Resolution");
	glUniform2f(uniformLocation,650.0f,650.0f);
	glUseProgram(0);
}
void GameLoop() {	//Rendereando todo el semestre
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//limpianod buffers

	//Activamos el vertex shader y el grament shader utilizando el manager
	glUseProgram(shaderProgram);

	//VBOs asociados automaticamente
	glBindVertexArray(vao);//activando el manager
	
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 12);
	//glDrawArrays(GL_TRIANGLE_FAN, 0, 8);
	//glDrawArrays(GL_TRIANGLE_FAN, 0, vertsPerFrame);
	//glDrawArrays(GL_TRIANGLE_FAN, 0, 362);


	//OpenGL viejito, solo para esta clase
	//glBegin(GL_TRIANGLES);

	/*glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f,-1.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -1.0f);
	
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);
*/

//	glEnd();

	glBindVertexArray(0);
/*
	vertsPerFrame += delta;
	if (vertsPerFrame < 0.0f || vertsPerFrame >= 362.0f)
		delta *= -1.0f;*/
	//cuando terminas de renderear, cambias los buffers
	glutSwapBuffers();
}

void Idle() {
	//cuando OpenGL entra en mode de reposo (ahorrar bateria), le decimos que vuelva a dibujar
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height) {

	glViewport(0, 0, width / 2, height /2);
	/*glViewport(0, 0, width, height);
	glUseProgram(shaderProgram);				//del shader	variable
	GLint uniformLocation = glGetUniformLocation(shaderProgram, "Resolution");
	glUniform2f(uniformLocation, width, height);
	glUseProgram(0);*/
}

int main(int argc, char* argv[]) {		//Main de pruebas

	//inicializar freeglut
	//Freeglut se encarga de crear una ventana en donde podemos dibujar
	glutInit(&argc, argv);
	glutInitContextVersion(4, 0);
	
	//configuraion de freeGlut
	//iniciar contexto de opeGL(capaidades de la aplicacion grafica) pipeline clasico
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);		
	//glutInitContextProfile(GLUT_CORE_PROFILE);

	//freeglut nos perite configurar eventos que ocurren en la ventana
	//un evento como cuando cierran la venta= limpiar memoria= terminar el programa
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);	//limpiar memoria

	//Configuramos framebuffer. solicitamos buffer 
	//					true color	profundidad	segundo buffer para renderear
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	//dimensiones de ventana
	glutInitWindowSize(650, 650);
	//titulo de ventana
	glutCreateWindow("Hello World GL");
	
	//asociamos una funcion de render para mandar llamar ara dibujar un frame
	glutDisplayFunc(GameLoop);

	//asociar funcion para el cambio de resolucion de la ventana.
	// Freeglut la va a mandar a llamarcuando se cambie el tamanio de la ventana
	glutReshapeFunc(ReshapeWindow);
	
	//llmar funion cada que OpenGl entre en modo de reposo
	glutIdleFunc(Idle);

	//inicializamos Glew para obtener el API de OpenGL de nuestra tarjeta de video
	glewInit();

	//configurar OpenGL
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);	//color por default 
	//Decirle al buffer de profundidad que se active
	glEnable(GL_DEPTH_TEST);
	//borrado de caras traseras. todo debe ser CCW
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//llamar initializa
	Initialize();

	glutMainLoop();	//iniciar la aplicaicon (main se pausa en esta linea hasta que se cierre la ventana)


	return 0;

	/*int p, mayor, menor,n;
	float a;
	//std::cout << "Hello, World!" << std::endl;
	p= PerimetroRectangulo(3, 5);
	std::cout << "Perimetro de rectangulo = " << p << std::endl;

	a = AreaTriangulo(3.0f, 5.0f);
	std::cout << "Area de triangulo = " << a << std::endl;

	mayor = Mayor(5, 9, 1);
	std::cout << "Mayor = " << mayor << std::endl;

	menor = Menor(5, 9, 1);
	std::cout << "Menor = " << menor << std::endl;
	
	std::cout << " " << std::endl;
	FilaEstrellas(5);
	
	std::cout << " " << std::endl;
	MatrizEstrellas(4);
	
	std::cout << " " << std::endl;
	PiramideEstrellas(6);

	std::cout << " " << std::endl;
	FlechaEstrellas(3);
	
	Fibonacci(9);
	
	std::cout << " " << std::endl;
	bool primo = EsPrimo(79);
	bool prime = EsPrimo(52);
	std::cout << "Primo 79 = " << primo << std::endl;
	std::cout << "Primo 52 = " << prime << std::endl;

	Circle circulo(2.0, "green");
	std::cout << circulo.GetRadius() << std::endl;e

	std::cin.get();

		return 0;

*/
	std::string filename = "Prueba.txt";
	InputFile myFile;
	myFile.Read(filename);
	std::string contents = myFile.GetContents();

	std::cout << "Contents: " << contents << std::endl;
	std::cin.get();





}
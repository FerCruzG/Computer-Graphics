/*********************************************
Materia: Gráficas Computacionales
Fecha: 02 de Octubre del 2017
Autor: A01373179 Maria Fernanda Cruz Gonzalez
		A01373243 Jose Angel Prado Dupont
**********************************************/
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Camera.h"

Mesh _mesh;
ShaderProgram _shaderProgram;
Transform _transform;
Transform _transform2;
Transform _transform3;
Transform _transform4;
Transform _transform5;
Camera _camera; //camera 3D
float contador;

void Initialize()
{
	// Creando toda la memoria que el programa va a utilizar.

	// Creación del atributo de posiciones de los vértices.
	// Lista de vec2
	// Claramente en el CPU y RAM
	std::vector<glm::vec3> positions;
	/*positions.push_back(glm::vec2(glm::cos(glm::radians(90.0f)),glm::sin(glm::radians(90.0f))));
	positions.push_back(glm::vec2(0.5f * glm::cos(glm::radians(18.0f)),	0.5f * glm::sin(glm::radians(18.0f))));
	positions.push_back(glm::vec2(glm::cos(glm::radians(18.0f)),glm::sin(glm::radians(18.0f))));
	positions.push_back(glm::vec2(0.5f * glm::cos(glm::radians(306.0f)),0.5f * glm::sin(glm::radians(306.0f))));
	positions.push_back(glm::vec2(glm::cos(glm::radians(306.0f)),glm::sin(glm::radians(306.0f))));
	positions.push_back(glm::vec2(0.5f * glm::cos(glm::radians(234.0f)),0.5f * glm::sin(glm::radians(234.0f))));
	positions.push_back(glm::vec2(glm::cos(glm::radians(234.0f)),glm::sin(glm::radians(234.0f))));
	positions.push_back(glm::vec2(0.5f * glm::cos(glm::radians(162.0f)),0.5f * glm::sin(glm::radians(162.0f))));
	positions.push_back(glm::vec2(glm::cos(glm::radians(162.0f)),glm::sin(glm::radians(162.0f))));
	positions.push_back(glm::vec2(0.5f * glm::cos(glm::radians(90.0f)),	0.5f * glm::sin(glm::radians(90.0f))));
	positions.push_back(glm::vec2(glm::cos(glm::radians(90.0f)),glm::sin(glm::radians(90.0f))));
	positions.push_back(glm::vec2(0.5f * glm::cos(glm::radians(18.0f)),	0.5f * glm::sin(glm::radians(18.0f))));*/
	//adelante
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	
	//izquierda
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));

	//atras
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));

	//derecha
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));	
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));
	

	//Arriba
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));

	//abajo
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));


	// Arreglo de colores en el cpu
	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));

	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));

	colors.push_back(glm::vec3(1.0f, 0.549f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.549f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.549f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.549f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.549f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.549f, 0.0f));

	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	/*colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));*/


	_mesh.CreateMesh(36);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);

	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.LinkProgram();
	//_camera.SetOrthigraphic(4.0f,4.0f);
	//_camera.MoveForward(30.0f);
	//_transform.SetRotation(0.0f,0.0f, 90.0f);
	_transform2.MoveUp(-5.0f, true);
	_transform2.SetScale(15.0f, 0.5f, 15.0f);
	_transform3.SetPosition(20, 0, -20);
	_transform4.SetPosition(20, 6, -20);
	_transform.SetPosition(-20, 0, -20);
	_transform5.SetPosition(-20, 0, 20);
	contador = 0;
}

void GameLoop()
{
	contador = contador + 0.002;
	float contadorx = sin(contador);
	float contadory = cos(contador);
	float contadorz = contadorx*contadory;
	glClearColor(contadorx, contadory, contadorz, 0.0f);
	// Limpiamos el buffer de color y el buffer de profunidad.
	// Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//_camera.MoveForward(-0.0001f);

	_transform.Rotate(0.01f, 0.0f, 0.0f, false);//a lo largo de los ejes locales
	//_transform2.Rotate(0.01f, 0.01f, 0.01f, true);//a lo largo de los ejes globales
	_transform3.Rotate(0.0f, 0.01f, 0.0f, false);//a lo largo de los ejes locales
	_transform4.Rotate(0.0f, -0.01f, 0.0f, false);//a lo largo de los ejes locales
	_transform5.Rotate(0.0f, 0.00f, 0.01f, false);//a lo largo de los ejes locales
	
	

	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());
//	_shaderProgram.SetUniformMatrix("modelMatrix", _transform.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform2.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform3.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform4.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform5.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	_camera.Rotate(0.0f, 0.01f, 0.0f, true);
	_shaderProgram.Deactivate();

	// Cuando terminamos de renderear, cambiamos los buffers.
	glutSwapBuffers();
}

void Idle()
{
	// Cuando OpenGL entra en modo de reposo 
	// (para guardar bateria, por ejemplo)
	// le decimos que vuelva a dibujar ->
	// Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int argc, char* argv[])
{
	// Inicializar freeglut
	// Freeglut se encarga de crear una ventana
	// en donde podemos dibujar
	glutInit(&argc, argv);
	// Solicitando una versión específica de OpenGL.
	//glutInitContextVersion(4, 4);
	// Iniciar el contexto de OpenGL. El contexto se refiere
	// a las capacidades que va a tener nuestra aplicación
	// gráfica.
	// En este caso estamos trabajando con el pipeline programable.
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear la esscena y terminamos el programa.   
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// true color RGBA, un buffer de profundidad y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Iniciar las dimensiones de la ventana (en pixeles)
	glutInitWindowSize(500, 500);
	// Creamos la ventana y le damos un título.
	glutCreateWindow("Hello World GL");
	// Asociamos una función de render.
	//Esta función se mandará a llamar para dibujar un frame.
	glutDisplayFunc(GameLoop);
	// Asociamos una función para el cambio de resolución
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tamaño de la venta.
	glutReshapeFunc(ReshapeWindow);
	// Asociamos la función que se mandará a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	// Inicializar GLEW. Esta librería se encarga de obtener el API de OpenGL de
	// nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// Configurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	// Ademas de solicitar el buffer de profundidad, tenemos
	// que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
	// Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	// No dibujar las caras traseras de las geometrías.
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	// Configuración inicial de nuestro programa.
	Initialize();

	// Iniciar la aplicación. El main se pausará en esta línea hasta que se cierre
	// la venta de OpenGL.
	glutMainLoop();

	return 0;
}
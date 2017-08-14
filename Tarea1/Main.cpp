/*********************************************
	Materia:	Graficas Computacionales
	Fecha:		Agosto 13, 2017
	Autor:		Maria Fernanda Cruz Gonzalez
**********************************************/
#include <iostream>

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

int main() {		//Main de pruebas
	int p, mayor, menor,n;
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

	std::cin.get();
	return 0;
}
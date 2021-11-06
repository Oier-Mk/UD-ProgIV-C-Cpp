#include "Punto.h"
#include "Circulo.h"
#include "Figura.h"
#include "Poligono.h"
#include <iostream>
using namespace std;

void imprimirDetalleFigura(Figura &f)
{
	// TAREA 4.2: Implementar esta función.
	f.imprimir();
	cout<<"------------------------------"<<endl;
}

float sumarPerimetros(Figura * figuras[], int numFiguras)
{
	// TAREA 4.3: Implementar esta función.
	float j = 0;
	for(int i = 0;i<numFiguras;i++){
		j += figuras[i]->getPerimetro();
	}
	return j;
}

int main(void)
{
	Circulo c1("Circulo1",3, Punto(1,2));
	Circulo *c2 = new Circulo("Circulo2", 4,Punto(2,1));

	Punto vertices[] = {Punto(1,1), Punto(1,2), Punto(2,1)};
	Poligono *p1 = new Poligono("Triangulo", 3, vertices);

	// TAREA 4.1: Imprimir por pantalla el numero de figuras creadas
	cout<<"Cantidad de figuras "<<Figura::getNF()<<endl;
	// TAREA 4.2: Imprime el detalle de cada una de las figuras existentes
	imprimirDetalleFigura(c1);
	imprimirDetalleFigura(*c2);
	imprimirDetalleFigura(*p1);
	// TAREA 4.3: Imprimir por pantalla la suma de los perimetros de las 3 figuras
	Figura* a[] = {&c1,c2,p1};
	cout<<"Suma de perimetros "<<sumarPerimetros(a,3)<<endl;

	return 0;
}

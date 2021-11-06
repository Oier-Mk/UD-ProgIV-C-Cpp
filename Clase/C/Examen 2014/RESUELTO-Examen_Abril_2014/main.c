/*
 * main.c
 *
 *  Created on: 22/04/2014
 *      Author: perallos
 */

#include "punto.h"
#include "poligono.h"
#include <stdio.h>

int main(void){

	Punto p1 = {1,2};
	Punto p2 = {3,4};
	Punto p3 = {5,6};

	imprimirPunto(p1);
	imprimirPunto(p2);

	printf("Distancia entre [%i,%i] y [%i,%i] -> %f\n",p1.x,p1.y,p2.x,p2.y,distancia(p1,p2));
	int x = 2;
	int y = 2;
	printf("Trasladar [%i,%i] y [%i,%i] -> x = %i, y = %i\n",p1.x,p1.y,p2.x,p2.y,x,y);
	trasladarXY(&p1,&p2,x,y);
	imprimirPunto(p1);
	imprimirPunto(p2);

	printf("Introduzca la cantidad de vertices\n");
	Poligono p = inputPoligono(inputNumero(1));
	anadirVertice(&p,&p3);
	imprimirPoligono(p);
	printf("Perimetro: %f\n",perimetro(p));
	Poligono poli2;
	copiarPoligono(p,&poli2);
	imprimirPoligono(p);
	imprimirPoligono(poli2);

	liberar(&p);
	return 0;
}

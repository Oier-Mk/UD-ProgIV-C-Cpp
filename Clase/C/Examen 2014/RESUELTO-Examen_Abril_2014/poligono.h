/*
 * poligono.h
 *
 *  Created on: 21 Apr 2021
 *      Author: mentxaka
 */

#ifndef POLIGONO_H_
#define POLIGONO_H_

typedef struct {
	int numVertices;
	Punto *vertices;
}Poligono;

void imprimirPoligono(Poligono poli);
void liberar(Poligono *poli);
Poligono inputPoligono(int size);
int inputNumero(int size);
float perimetro(Poligono poli);
void anadirVertice(Poligono *poli, Punto *p);
void copiarPoligono(Poligono poli1, Poligono *poli2);

#endif /* POLIGONO_H_ */

/*
 * poligono.c
 *
 *  Created on: 21 Apr 2021
 *      Author: mentxaka
 */

#include "punto.h"
#include "poligono.h"
#include <stdio.h>
#include <stdlib.h>

void imprimirPoligono(Poligono poli){
	for(int i = 0; i<poli.numVertices;i++){
		imprimirPunto(poli.vertices[i]);
	}
}
void liberar(Poligono *poli){
	free(poli->vertices);
}
Poligono inputPoligono(int size){
	Poligono p;
	p.numVertices = size;
	p.vertices = malloc(sizeof(Punto)*size);
	for(int i = 0;i<p.numVertices;i++){
		printf("Introduzca el valor de X\n");
		int x = inputNumero(1);
		printf("Introduzca el valor de Y\n");
		int y = inputNumero(1);
		Punto punto;
		punto.x = x;
		punto.y = y;
		p.vertices[i] = punto;
	}
	return p;
}
float perimetro(Poligono poli){
	float p = 0.0;
	for(int i = 0; i<poli.numVertices-1;i++){
		p += distancia(poli.vertices[i],poli.vertices[i+1]);
	}
	p += distancia(poli.vertices[0],poli.vertices[poli.numVertices - 1]);
	return p;
}
int inputNumero(int size) {
    fflush(stdin);
    int num;
    size++;
    char str[size];
    fgets(str, size, stdin);
    sscanf(str, "%i", &num);
    return num;
}
void anadirVertice(Poligono *poli, Punto *p){
	Punto *temp = malloc(sizeof(Punto)*poli->numVertices+1);
	for(int i = 0; i<poli->numVertices; i++){
		temp[i] = poli->vertices[i];
	}
	poli->vertices[poli->numVertices] = *p;
	poli->numVertices++;
}
void copiarPoligono(Poligono poli1, Poligono *poli2){
	//*poli2 = poli1; TODO NO VALE SOLO PORQUE HAY PUNTEROS, EN CASO DE NO HABERLOS VALDR'IA
	poli2->numVertices = poli1.numVertices;
	poli2->vertices = malloc(sizeof(Poligono)*poli1.numVertices);
	for(int i = 0; i<poli1.numVertices; i++){
		poli2->vertices[i] = poli1.vertices[i];
	}
}

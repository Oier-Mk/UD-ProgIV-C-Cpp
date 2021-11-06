/*
 * Poligono.cpp
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#include "Poligono.h"
#include "string.h"
#include <iostream>
using namespace std;

Poligono::Poligono() : Figura() {
	// TODO Auto-generated constructor stub
	this->numVertices = 0;
	this->vertices = new Punto[0];
}

Poligono::Poligono(char* nombre, int nVertices, Punto* vertices) : Figura(nombre) {
	// TODO Auto-generated constructor stub
	this->numVertices = nVertices;
	this->vertices = new Punto[nVertices];
	for(int i = 0; i<nVertices;i++){
		  this->vertices[i] = Punto(vertices[i]);
	}
}

Poligono::~Poligono()  {
	// TODO Auto-generated destructor stub
	delete[] vertices;
}

Poligono::Poligono(const Poligono &o) {
	// TODO Auto-generated constructor stub
	this->nombre = new char[strlen(o.nombre)+1];
	strcpy(this->nombre,o.nombre);
	this->numVertices = o.numVertices;
	this->vertices = new Punto[o.numVertices];
	for(int i = 0; i<o.numVertices;i++){
		  this->vertices[i] = Punto(vertices[i]);
	}
}

float Poligono::getPerimetro(){
	int cont = 0;
	for(int i = 0; i<this->numVertices-1; i++){
		cont += this->vertices[i].distancia(this->vertices[i+1]);
	}
	cont += this->vertices[0].distancia(this->vertices[this->numVertices-1]);
	return cont;
}

void Poligono::imprimir(){
	cout<<"P - Nombre: "<<this->nombre<<endl;
	cout<<"    numVertices: "<<this->numVertices<<endl;
	for(int i = 0; i<this->numVertices; i++){
		cout<<"    ";
		this->vertices[i].imprimir();
	}

}

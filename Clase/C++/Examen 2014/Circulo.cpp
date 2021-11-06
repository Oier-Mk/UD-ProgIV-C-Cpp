/*
 * Circulo.cpp
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#include "Circulo.h"

#include <string.h>
#include <iostream>
using namespace std;

Circulo::Circulo() : Figura() {
	// TODO Auto-generated constructor stub
}

Circulo::Circulo(char* nombre,float radio, Punto centro) : Figura(nombre) {
	// TODO Auto-generated constructor stub
	this->centro = Punto(centro);
	this->radio = radio;
}
Circulo::~Circulo() {
	// TODO Auto-generated destructor stub
}

Circulo::Circulo(const Circulo &o) {
	// TODO Auto-generated constructor stub
	this->nombre = new char[strlen(o.nombre)+1];
	strcpy(this->nombre,o.nombre);
	this->centro = Punto(o.centro);
	this->radio = o.radio;
}

float Circulo::getPerimetro(){
	return 2*3.141592*this->radio;
}

void Circulo::imprimir(){
	cout<<"C - Nombre: "<<this->nombre<<endl;
	cout<<"    Radio: "<<this->radio<<endl;
	cout<<"    Punto: "; this->centro.imprimir();

}

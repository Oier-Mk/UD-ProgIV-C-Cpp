/*
 * Figura.cpp
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#include "Figura.h"
#include <string.h>

#include <iostream>
using namespace std;

	int Figura::nf = 0;

	int Figura::getNF(){
		return nf;
	}

	Figura::Figura(){
		nf++;
		this->nombre = "Sin nombre";
	}
	Figura::Figura(char* nombre){
		nf++;
		this->nombre = new char[strlen(nombre)+1];
		strcpy(this->nombre,nombre);
	}
	Figura::~Figura(){
		delete[] nombre;
	}
	Figura::Figura(const Figura &o){
		nf++;
		this->nombre = new char[strlen(o.nombre)+1];
		strcpy(this->nombre,o.nombre);
	}
	float Figura::getPerimetro(){
		//metodo abstracto sin implementación
	}
	void Figura::imprimir(){
		cout<<"F - nombre: "<<this->nombre<<endl;
	}

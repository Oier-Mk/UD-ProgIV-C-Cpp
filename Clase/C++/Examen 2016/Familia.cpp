/*
 * Familia.cpp
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#include "Familia.h"
#include <string.h>
#include <iostream>
using namespace std;

	Familia::Familia(){
		this->conyuge1 = NULL;
		this->conyuge2 = NULL;
	}
	Familia::Familia(Miembro* c1, Miembro* c2){
		this->conyuge1 = c1;
		this->conyuge2 = c2;
	}
	Familia::~Familia(){
	}
	Familia::Familia(const Familia &other){
		this->conyuge1 = other.conyuge1;
		this->conyuge2 = other.conyuge2;;
	}
	char* Familia::getNombre(){
	    char* nombre = new char[50];
		char* c1 = strchr(this->conyuge1->getNombre(), ' ');
		char* c2 = strchr(this->conyuge2->getNombre(), ' ');
		strcat(nombre,c1);
		strcat(nombre," -");
		strcat(nombre,c2);
		return nombre;
	}
	void Familia::imprimir(){
		cout<<this->getNombre()<<endl;
		cout<<this->conyuge1->getNombre()<<endl;
		cout<<this->conyuge2->getNombre()<<endl;
	}
    int Familia::contarMenoresEdad(int edad){
	    int cont = 0;
        if(this->conyuge1->getEdad()<edad)cont++;
        if(this->conyuge2->getEdad()<edad)cont++;
	    return cont;
	}
    Miembro* Familia::getC(int i){
        if(i == 1) return this->conyuge1;
        if(i == 2) return this->conyuge2;
	}

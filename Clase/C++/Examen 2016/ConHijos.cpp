/*
 * ConHijos.cpp
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#include "ConHijos.h"
#include <iostream>
using namespace std;

ConHijos::ConHijos():Familia(){
	this->nHijos = 0;
	this->hijos = new Miembro*[0];
}
ConHijos::ConHijos(Miembro* c1, Miembro* c2,int nHijos, Miembro** hijos){
    this->conyuge1 = c1;
    this->conyuge2 = c2;
    this->nHijos = nHijos;
    this->hijos = new Miembro*[this->nHijos];
    for(int i = 0; i<nHijos;i++){
        this->hijos[i] = hijos[i];
    }
}
ConHijos::~ConHijos(){
	delete[] hijos;
}
ConHijos::ConHijos(const ConHijos &o):Familia(){
	this->conyuge1 = o.conyuge1;
	this->conyuge2 = o.conyuge2;
	this->nHijos = nHijos;
	this->hijos = new Miembro*[o.nHijos];
	for(int i = 0; i<o.nHijos;i++){
		this->hijos[i] = o.hijos[i];
	}
}
void ConHijos::imprimir(){
	cout<<this->getNombre()<<endl;
	cout<<this->conyuge1->getNombre()<<endl;
	cout<<this->conyuge2->getNombre()<<endl;
	cout<<"nHijos = "<<this->nHijos<<endl;
	for(int i = 0; i<this->nHijos;i++){
		cout<<this->hijos[i]->getNombre()<<endl;
	}
}
int ConHijos::contarMenoresEdad(int edad){
    int cont = 0;
    if(this->conyuge1->getEdad()<edad)cont++;
    if(this->conyuge2->getEdad()<edad)cont++;
    for(int i = 0; i<this->nHijos;i++){
        if(this->hijos[i]->getEdad()<edad)cont++;
    }
    return cont;
}
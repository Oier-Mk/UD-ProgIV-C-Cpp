/*
 * Hangout.cpp
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */


#include "App.h"
#include "Hangout.h"
#include "string.h"
#include <iostream>
using namespace std;

Hangout::Hangout() {
	// TODO Auto-generated constructor stub
	this->mensajes =  new Mensaje[5];
}

Hangout::Hangout(char* nombre,float version) : App(nombre,version){
	// TODO Auto-generated constructor stub
}

Hangout::~Hangout() {
	// TODO Auto-generated destructor stub
	delete[] mensajes;
}

Hangout::Hangout(const Hangout &o) {
	// TODO Auto-generated constructor stub
	this->nombre = new char(strlen(o.nombre)+1);
	strcpy(this->nombre,o.nombre);
	this->version = o.version;
	this->mensajes = new Mensaje[5];
	for(int i = 0; i < 5 ; i++){
		this->mensajes[i] = o.mensajes[i];
	}
}

void Hangout::info() {
	// TODO Auto-generated destructor stub
	cout<<"H - Nombre:"<<this->nombre<<endl;
	cout<<"    Version:"<<this->version<<endl;
	for(int i = 0; i < 5; i++){
		cout<<"    ";this->mensajes[i].imprimir();
	}
}

void Hangout::chatear(const char* m1, const char* m2){
	if(this->nMensajes == 5){
		Mensaje* temp = new Mensaje[5];
		for(int i = 0;i<4;i++){
			temp[i] = this->mensajes[i+1];
		}
		temp[4] = Mensaje(m1,m2);
		for(int i = 0;i<4;i++){
			this->mensajes[i] = temp[i];
		}
	}else{
		this->nMensajes++;
		this->mensajes[this->nMensajes] = Mensaje(m1,m2);
	}
}


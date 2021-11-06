/*
 * Smartphone.cpp
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#include "string.h"

#include <iostream>
using namespace std;
#include "Smartphone.h"

Smartphone::Smartphone() {
	// TODO Auto-generated constructor stub
	this->nombre = "sin nombre";
	this->espacio = 0;
	this->hangout = Hangout();
	this->nInstaladas = 0;
	this->instaladas = new App[this->espacio];
}

Smartphone::Smartphone(char* nombre, int espacio) {
	// TODO Auto-generated constructor stub
	this->nombre = new char(strlen(nombre)+1);
	strcpy(this->nombre,nombre);
	this->espacio = espacio;
	this->hangout = Hangout();
	this->nInstaladas = 0;
	this->instaladas = new App[this->espacio];
}

Smartphone::~Smartphone() {
	// TODO Auto-generated destructor stub
}

Smartphone::Smartphone(const Smartphone &o) {
	// TODO Auto-generated constructor stub
	this->nombre = new char(strlen(o.nombre)+1);
	strcpy(this->nombre,o.nombre);
	this->espacio = o.espacio;
	this->nInstaladas = o.nInstaladas;
	this->instaladas = new App[this->espacio];
}


void Smartphone::desinstalarApp(char* n){
	int j = 0;
	for(int i = 0; i<this->espacio;i++){
		if(strcmp(this->instaladas[i].getNombre(),n)==0){
			j=i;
		}
	}
	for(int k = j; k<this->espacio-1;k++){
		this->instaladas[k]=this->instaladas[k+1];
	}
	this->instaladas[this->nInstaladas-1] = App();
	this->nInstaladas--;
}

void Smartphone::instalarApp(App a){
	if (this->nInstaladas==this->espacio){
		cout<<"NO HAY ESPACIO SUFICIENTE"<<endl;
	}else{
		this->instaladas[this->nInstaladas-1] = a;
		this->nInstaladas++;
	}
}

void Smartphone::ampliarMemoria(int i){
	App* temp = this->instaladas;
	this->instaladas = new App[i];
	for(int i = 0;i<this->espacio;i++){
		temp[i] = this->instaladas[i];
	}
	this->espacio = i;
}

void Smartphone::setHangout(Hangout h){
	this->hangout = h;
}

void Smartphone::chatear(const char* m1, const char* m2){
	if(strcmp(this->hangout.getNombre(),"sin nombre")==0){
		cout<<"HANGOUT NO DISPONIBLE"<<endl;
	}else{
		this->hangout.chatear(m1, m2);
	}
}

void Smartphone::info(){
	cout<<"P - Nombre:"<<this->nombre<<endl;
	cout<<"    Espacio:"<<this->espacio<<endl;
	for(int i = 0; i < this->espacio;i++){
		cout<<"    ";this->instaladas[i].info();
	}
}

void Smartphone::buscarAppsObsoletas(int * n, App** obsoletas){
	int cont = 0;
	App** temp = new App*[this->espacio];
	for(int i = 0; i < this->espacio;i++){
		if(this->instaladas[i].getVersion()<this->instaladas[i].getObsoleto()){
			temp[cont] = &this->instaladas[i];
			cont++;
		}
	}
	*n=cont;
	obsoletas=temp;
}


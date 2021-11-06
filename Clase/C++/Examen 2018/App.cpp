/*
 * App.cpp
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#include "App.h"
#include "string.h"

#include <iostream>
using namespace std;

float App::obsoleto = 3;


float App::getObsoleto(){
	return App::obsoleto;
}

void App::setObsoleto(float i){
	App::obsoleto = i;
}


App::App() {
	// TODO Auto-generated constructor stub
	this->nombre = "sin nombre";
	this->version = 0.0;
}

App::App(char* nombre,float version){
	// TODO Auto-generated constructor stub
	this->nombre = new char(strlen(nombre)+1);
	strcpy(this->nombre,nombre);
	this->version = version;
}

App::~App() {
	// TODO Auto-generated destructor stub
	delete[] nombre;
}

App::App(const App &o) {
	// TODO Auto-generated constructor stub
	this->nombre = new char(strlen(o.nombre)+1);
	strcpy(this->nombre,o.nombre);
	this->version = o.version;
}

void App::info() {
	// TODO Auto-generated destructor stub
	cout<<"A - Nombre:"<<this->nombre<<endl;
	cout<<"    Version:"<<this->version<<endl;
}

char* App::getNombre() {
	return this->nombre;
}

float App::getVersion(){
	this->version;
}

/*
 * Jugador.cpp
 *
 *  Created on: 7 jun. 2021
 *      Author: oiermentxaka
 */

#include "Jugador.h"
#include "Usuario.h"
#include <string.h>
#include <iostream>
using namespace std;

Jugador::Jugador() {
	this->nombre = "sin nombre";
	this->jugador = new Usuario();
}

Jugador::~Jugador() {
	delete[] nombre;
}

Jugador::Jugador(const Jugador &o) {
	this->nombre = new char[strlen(o.nombre)+1];
	strcpy(this->nombre,o.nombre);
	this->jugador = o.jugador;
}

Jugador::Jugador(char* nombre,Usuario* u){
	this->nombre = new char[strlen(nombre)+1];
	strcpy(this->nombre,nombre);
	this->jugador = u;
}
void Jugador::imprimir(){
	cout<<" Nombre: " << this->jugador->getNombre();
	cout<<" Nick: " << this->nombre<<endl;
}

Usuario* Jugador::getJugador(){
	return this->jugador;
}

char* Jugador::getNombre(){
	return this->nombre;
}




/*
 * Tablero.cpp
 *
 *  Created on: 7 jun. 2021
 *      Author: oiermentxaka
 */

#include "Tablero.h"
#include <iostream>
#include <string.h>

using namespace std;

Tablero::Tablero() : Partida(){
	this->movimientos = new char*[0];
	this->nMov = 0;
}

Tablero::Tablero(char* nombre, char* fecha) : Partida(nombre,fecha){
	this->movimientos = new char*[0];
	this->nMov = 0;
}

Tablero::~Tablero() {
	delete[] movimientos;
}

Tablero::Tablero(const Tablero &o) {
	this->nombre = new char[strlen(o.nombre)+1];
	strcpy(this->nombre,o.nombre);
	this->fecha = new char[strlen(o.fecha)+1];
	strcpy(this->fecha,o.fecha);
	this->nJugadores = o.nJugadores;
	this->jugadores = new Jugador*[o.nJugadores];
	for(int i = 0; i< this->nJugadores; i++){
		this->jugadores[i] = o.jugadores[i];
	}
	this->ganador = o.ganador;
	this->movimientos = new char*[o.nJugadores];
	for(int i = 0;i<o.nMov;i++){
		this->movimientos[i] = o.movimientos[i];
	}
	this->nMov = o.nMov;
}

void Tablero::imprimir(){
	cout<<"-------------------"<<endl;
	cout<<"TABLERO: "<< this->nombre<< " ("<< this->fecha << ")"<<endl;
	for (int i = 0;i<this->nJugadores;i++){
		cout<<"Jugador "<<i<<" ";this->jugadores[i]->imprimir();;
	}
	cout<<"Ganador: "<< this->ganador->getJugador()->getNombre() << " (" << this->ganador->getNombre() <<")"<<endl;
	cout<<"Movimientos:"<<endl;
	for(int j = 0; j<this->nMov;j++){
		cout<<j<<". "<<this->movimientos[j]<<endl;
	}
}

void Tablero::anadirSgteMovimiento(char* m){
	char** temp = new char*[this->nMov+1];
	for(int i = 0; i<this->nMov;i++){
		temp[i] = new char[strlen(this->movimientos[i])+1];
		strcpy(temp[i],this->movimientos[i]);
	}
	temp[this->nMov] = new char[strlen(m)+1];
	strcpy(temp[this->nMov],m);
	this->movimientos = temp;
	this->nMov++;
}

int Tablero::getPuntuacion(){
	return this->nJugadores+this->nMov;
}



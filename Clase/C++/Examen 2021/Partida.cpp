/*
 * Partida.cpp
 *
 *  Created on: 7 jun. 2021
 *      Author: oiermentxaka
 */

#include "Partida.h"
#include <string.h>
#include <iostream>
using namespace std;

Partida::Partida() {
	this->nombre = "sin nombre";
	this->fecha = "dd-mm-aaaa";
	this->jugadores = new Jugador*[4];
	this->nJugadores = 0;
	this->ganador = new Jugador();
}

Partida::~Partida() {
	delete[] nombre;
	delete[] fecha;
	delete[] jugadores;
}

Partida::Partida(char* nombre, char* fecha){
	this->nombre = new char[strlen(nombre)+1];
	strcpy(this->nombre,nombre);
	this->fecha = new char[strlen(fecha)+1];
	strcpy(this->fecha,fecha);
	this->jugadores = new Jugador*[4];
	this->nJugadores = 0;
	this->ganador = new Jugador();
}

Partida::Partida(const Partida &o) {
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
}

void Partida::anadirJugador(Jugador * j){
	if(this->nJugadores<4){
		this->jugadores[this->nJugadores] = j;
		this->nJugadores++;
	}else{
		cout<<"NO PUEDE HABER MAS JUGADORES"<<endl;
	}
}

void Partida::imprimir(){
	cout<<"-------------------"<<endl;
	cout<<"PARTIDA: "<< this->nombre<< " ("<< this->fecha << ")"<<endl;
	for (int i = 0;i<this->nJugadores;i++){
		cout<<"Jugador "<<i<<" ";this->jugadores[i]->imprimir();
	}
	cout<<"Ganador: "<< this->ganador->getJugador()->getNombre() << " (" << this->ganador->getNombre() <<")"<<endl;
}
void Partida::setGanador(Jugador* j){
	this->ganador = j;
}

int Partida::getPuntuacion(){
	return this->nJugadores;
}

Jugador* Partida::getGanador(){
	return this->ganador;
}

char* Partida::getNombre(){
	return this->nombre;
}

char* Partida::getFecha(){
	return this->fecha;
}

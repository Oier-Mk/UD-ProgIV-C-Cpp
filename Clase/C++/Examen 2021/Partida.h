/*
 * Partida.h
 *
 *  Created on: 7 jun. 2021
 *      Author: oiermentxaka
 */

#ifndef PARTIDA_H_
#define PARTIDA_H_

#include "Usuario.h"
#include "Jugador.h"

class Partida {
protected:
	char* nombre;
	char* fecha;
	Jugador ** jugadores;
	int nJugadores;
	Jugador * ganador;
public:
	Partida();
	Partida(char* nombre, char* fecha);
	Partida(const Partida &other);
	virtual ~Partida();
	void anadirJugador(Jugador * j);
	void setGanador(Jugador* j);
	Jugador * getGanador();
	virtual int getPuntuacion();
	char* getNombre();
	char* getFecha();
	virtual void imprimir();
};

#endif /* PARTIDA_H_ */

/*
 * Jugador.h
 *
 *  Created on: 7 jun. 2021
 *      Author: oiermentxaka
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Usuario.h"

class Jugador {
protected:
	char* nombre;
	Usuario * jugador;
public:
	Jugador();
	Jugador(char*nombre,Usuario* u);
	virtual ~Jugador();
	Jugador(const Jugador &other);
	void imprimir();
	Usuario* getJugador();
	char* getNombre();
};

#endif /* JUGADOR_H_ */

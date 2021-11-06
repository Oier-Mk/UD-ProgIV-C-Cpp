/*
 * Tablero.h
 *
 *  Created on: 7 jun. 2021
 *      Author: oiermentxaka
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include "Partida.h"

class Tablero : public Partida {
protected:
	char** movimientos;
	int nMov;
public:
	Tablero();
	Tablero(char* nombre, char* fecha);
	Tablero(const Tablero &other);
	virtual ~Tablero();
	virtual void imprimir();
	void anadirSgteMovimiento(char* m);
	virtual int getPuntuacion();
};

#endif /* TABLERO_H_ */

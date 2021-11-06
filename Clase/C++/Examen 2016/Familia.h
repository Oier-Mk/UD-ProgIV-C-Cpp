/*
 * Familia.h
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#ifndef FAMILIA_H_
#define FAMILIA_H_

#include "miembro.h"

class Familia {
protected:
	Miembro* conyuge1;
	Miembro* conyuge2;
public:
	Familia();
	Familia(Miembro* c1,Miembro* c2);
	virtual ~Familia();
	Familia(const Familia &other);
    char* getNombre();
    Miembro* getC(int i);
	virtual void imprimir();
	virtual int contarMenoresEdad(int edad);
};


#endif /* FAMILIA_H_ */

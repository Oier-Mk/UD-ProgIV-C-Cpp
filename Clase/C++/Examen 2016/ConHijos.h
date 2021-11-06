/*
 * ConHijos.h
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#ifndef CONHIJOS_H_
#define CONHIJOS_H_

#include "Familia.h"

class ConHijos : public Familia {
protected:
	int nHijos;
	Miembro** hijos;
public:
	ConHijos();
	ConHijos(Miembro* c1, Miembro* c2,int nHijos, Miembro** hijos);
	virtual ~ConHijos();
	ConHijos(const ConHijos &other);
	void imprimir();
	int contarMenoresEdad(int edad);
};

#endif /* CONHIJOS_H_ */

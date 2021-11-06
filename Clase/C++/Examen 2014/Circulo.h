/*
 * Circulo.h
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#include "Punto.h"
#include "Figura.h"

#ifndef CIRCULO_H_
#define CIRCULO_H_

class Circulo : public Figura {
protected:
	Punto centro;
	float radio;
public:
	Circulo();
	Circulo(char* nombre, float radio,Punto centro);
	virtual ~Circulo();
	Circulo(const Circulo &other);
	float getPerimetro();
	void imprimir();
};

#endif /* CIRCULO_H_ */

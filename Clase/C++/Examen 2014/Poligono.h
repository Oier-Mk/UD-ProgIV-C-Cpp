/*
 * Poligono.h
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#ifndef POLIGONO_H_
#define POLIGONO_H_

#include "Figura.h"
#include "Punto.h"

class Poligono : public Figura {
protected:
	int numVertices;
	Punto *vertices;
public:
	Poligono();
	Poligono(char* nombre, int nVertices, Punto* vertices);
	virtual ~Poligono();
	Poligono(const Poligono &other);
	float getPerimetro();
	void imprimir();
};

#endif /* POLIGONO_H_ */

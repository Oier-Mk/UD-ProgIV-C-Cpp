/*
 * Figura.h
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#ifndef FIGURA_H_
#define FIGURA_H_

class Figura {
protected:
	static int nf;
	char* nombre;
public:
	Figura();
	Figura(char* nombre);
	virtual ~Figura();
	static int getNF();
	Figura(const Figura &other);
	virtual float getPerimetro();
	virtual void imprimir();
};

#endif /* FIGURA_H_ */

/*
 * Hangout.h
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#ifndef HANGOUT_H_
#define HANGOUT_H_

#include "App.h"
#include "Mensaje.h"

class Hangout : public App {
protected:
	Mensaje* mensajes;
	int nMensajes = 0;
public:
	Hangout();
	Hangout(char*nombre,float version);
	virtual ~Hangout();
	Hangout(const Hangout &other);
	void info();
	void chatear(const char* m1, const char* m2);
	void buscarAppsObsoletas(int * n, App** obsoletas);
};

#endif /* HANGOUT_H_ */

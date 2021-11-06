/*
 * Smartphone.h
 *
 *  Created on: 6 jun. 2021
 *      Author: Tester
 */

#ifndef SMARTPHONE_H_
#define SMARTPHONE_H_

#include "App.h"
#include "Hangout.h"

class Smartphone {
	char* nombre;
	int espacio;
	App* instaladas;
	int nInstaladas;
	Hangout hangout;
public:
	Smartphone();
	Smartphone(char* nombre, int espacio);
	virtual ~Smartphone();
	Smartphone(const Smartphone &other);
	void instalarApp(App);
	void desinstalarApp(char*);
	void ampliarMemoria(int);
	void setHangout(Hangout h);
	void chatear(const char* m1, const char* m2);
	void info();
	void 	buscarAppsObsoletas(int * n, App** obsoletas);
};

#endif /* SMARTPHONE_H_ */

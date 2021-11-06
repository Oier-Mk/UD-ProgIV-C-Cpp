//============================================================================
// Name        : 2019.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Mensaje.h"
#include "Hangout.h"
#include "Smartphone.h"
#include "App.h"

int main() {
	Mensaje men1("Pedro", "!Hola!");
	men1.imprimir();

	Smartphone sm1("Samsung Galaxy S7", 1);
	Hangout ap1("Hangout", 1.7f);
	App ap2("Twiter", 5.1f);
	App * ap3 = new App("Calc", 1.5f);
	App * ap4 = new App("Calendar", 0.4f);

	sm1.instalarApp(ap1);
	sm1.setHangout(ap1);
	sm1.instalarApp(ap2);
	sm1.instalarApp(*ap3);
	sm1.instalarApp(*ap4);

	sm1.ampliarMemoria(5);
	sm1.instalarApp(ap2);
	sm1.instalarApp(*ap3);
	sm1.instalarApp(*ap4);


	sm1.chatear("Pedro", "!Hola!");
	sm1.chatear("Maria", "Que tal?");
	sm1.chatear("Maria", "!Cuanto tiempo!");
	sm1.chatear("Pedro", "!Muy bien!");
	sm1.chatear("Pedro", "Y tu?");
	sm1.chatear("Maria", "Haciendo un examen...");

	sm1.info();

	sm1.desinstalarApp("Calendar");

	sm1.info();

	ap1.setObsoleto(2.1);

	int n = 0;
	App* obsoletas;
	sm1.buscarAppsObsoletas(&n, &obsoletas);

	delete ap3;
	delete ap4;

	return 0;
}

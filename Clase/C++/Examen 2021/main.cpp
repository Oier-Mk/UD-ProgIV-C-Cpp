#include "Usuario.h"
#include "Partida.h"
#include "Jugador.h"
#include "Tablero.h"

#include <string.h>
#include <iostream>
using namespace std;

Partida* mejorPartida(Partida ** p, int n){
	Partida* mejor = new Partida();
	for(int i = 0; i<n;i++){
		if(p[i]->getPuntuacion()>mejor->getPuntuacion()) mejor = p[i];
	}
	return mejor;
}

void historialVictorias(Partida ** p, int n, Usuario *u){
	cout<<"\nVICTORIAS "<<u->getNombre()<<endl;
	for(int i = 0; i<n;i++){
		if(strcmp(p[i]->getGanador()->getJugador()->getNombre(),u->getNombre())==0) cout<<"PARTIDA: "<<p[i]->getNombre()<< " ("<< p[i]->getFecha() << ")"<<endl;
	}
}

int main()
{
	Usuario ana("Ana Perez", 30 /*años*/);
	Usuario marta("Marta Canta", 48);
	Usuario fran("Fran Paz", 22);
	Usuario oneka("Oneka Baila", 10);

	cout<< ana.getNombre() << " os reta a una partida." << endl;

	Partida p1("Mus","28-05-2021");
	Jugador* j1 = new Jugador("A",&ana);
	p1.anadirJugador(j1);
	Jugador* j2 = new Jugador("B",&marta);
	p1.anadirJugador(j2);
	p1.setGanador(j1);

	p1.imprimir();

	Partida p2("Trivial","29-05-2021");
	Jugador* j3 = new Jugador("Rojo",&fran);
	p2.anadirJugador(j3);
	Jugador* j4 = new Jugador("Azul",&marta);
	p2.anadirJugador(j4);
	Jugador* j5 = new Jugador("Verde",&ana);
	p2.anadirJugador(j5);
	p2.setGanador(j4);

	p2.imprimir();

	Tablero p3("Ajedrez","30-05-2021");
	Jugador* j6 = new Jugador("Blancas",&oneka);
	p3.anadirJugador(j6);
	Jugador* j7 = new Jugador("Negras",&ana);
	p3.anadirJugador(j7);
	p3.setGanador(j7);

	p3.anadirSgteMovimiento("mov1");
	p3.anadirSgteMovimiento("mov2");
	p3.anadirSgteMovimiento("mov3");
	p3.anadirSgteMovimiento("mov4");

	p3.imprimir();

	Partida* partidas[] = {&p1,&p2,&p3};

	cout<< "\nLa partida mas valorada es "<<mejorPartida(partidas,3)->getNombre()<<" ("<<mejorPartida(partidas,3)->getFecha()<<")"<<endl;

	historialVictorias(partidas,3,&ana);

	return 0;
}

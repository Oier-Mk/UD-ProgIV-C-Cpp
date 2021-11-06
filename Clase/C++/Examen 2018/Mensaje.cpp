#include "Mensaje.h"
#include <string.h>

#include <iostream>
using namespace std;

Mensaje::Mensaje()
{
	this->emisor = NULL;
	this->texto = NULL;
}

Mensaje::Mensaje(const char * emi, const char * tex)
{
	this->emisor = new char[strlen(emi) + 1];
	strcpy(this->emisor, emi);
	this->texto = new char[strlen(tex) + 1];
	strcpy(this->texto, tex);
}


Mensaje::~Mensaje()
{
//	cout << "Destructor Mensaje" << endl;
	delete [] emisor;
	delete [] texto;
}

const char * Mensaje::getEmisor()
{
	return this->emisor;
}

const char * Mensaje::getMensaje()
{
	return this->texto;
}


void Mensaje::imprimir() {
	cout << "[Emisor: " << this->emisor << ", Texto: " << this->texto << "]" << endl;
}


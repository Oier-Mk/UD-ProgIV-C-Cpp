//
// Created by Tester on 06/06/2021.
//

#include "ArbolFamilias.h"
#include "Miembro.h"
#include <iostream>
using namespace std;

ArbolFamilias::ArbolFamilias(){
    //declarado en h
	this->arbol = new Familia*[5];
}
ArbolFamilias::~ArbolFamilias(){
    delete[] arbol;
}
void ArbolFamilias::anadirFamilia(Familia* f){
    this->arbol[this->actual] = f;
    if(this->actual<5)this->actual++;
}
void ArbolFamilias::imprimir(){
    for(int i = 0; i<5;i++){
        this->arbol[i]->imprimir();
    }
}
int ArbolFamilias::contarMenoresEdad(int edad){
    int cont = 0;
    for(int i = 0; i<this->actual;i++){
        cont += this->arbol[i]->contarMenoresEdad(edad);
    }
    return cont;
}
Miembro** ArbolFamilias::getConyugesInicial(int* n, char inicial){
    Miembro** empiezanPor = new Miembro*[10];
    int cont = 0;
    for(int i = 0; i<this->actual;i++){
        if(this->arbol[i]->getC(1)->getNombre()[0]==inicial){
            empiezanPor[cont] = this->arbol[i]->getC(1);
            cont++;
        }
        if(this->arbol[i]->getC(2)->getNombre()[0]==inicial){
            empiezanPor[cont] = this->arbol[i]->getC(2);
            cont++;
        }
    }
    *n = cont;
    return empiezanPor;
}

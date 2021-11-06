//
// Created by Tester on 06/06/2021.
//

#ifndef INC_2016_ARBOLFAMILIAS_H
#define INC_2016_ARBOLFAMILIAS_H

#include "Familia.h"

class ArbolFamilias {
protected:
    Familia** arbol;
    int actual = 0;
public:
    ArbolFamilias();
    ~ArbolFamilias();
    void anadirFamilia(Familia* f);
    void imprimir();
    int contarMenoresEdad(int edad);
    Miembro** getConyugesInicial(int* n, char inicial);
};


#endif //INC_2016_ARBOLFAMILIAS_H

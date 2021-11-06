#include "Miembro.h"
#include "Familia.h"
#include "ConHijos.h"
#include "ArbolFamilias.h"

#include <iostream>
using namespace std;

int main()
{
	Miembro luis("Luis Diez", 60 /*a�os*/);
	Miembro marta("Marta Sanchez", 58);
	Miembro angel("Angel Diez", 32);
	Miembro laura("Laura Ponte", 30);
	Miembro hodei("Hodei Diez", 2);
	Miembro ana("Ana Diez", 7);
	Miembro pablo("Pablo Diez", 10);
	Miembro jon("Jon Pena", 40);
	Miembro maite("Maite Pazos", 35);

	cout<< luis.toStr() << " os desea suerte en el examen." << endl;

	Familia f1(&jon,&maite);
	f1.imprimir();
    cout<<"---------------------------"<<endl;
	Miembro* h1[] = {&angel};
	ConHijos f2(&luis,&marta,1,h1);
	f2.imprimir();
    cout<<"---------------------------"<<endl;
    Miembro* h2[] = {&hodei,&ana,&pablo};
    ConHijos f3(&angel,&laura,3,h2);
    f3.imprimir();
    cout<<"---------------------------"<<endl;
    ArbolFamilias af = ArbolFamilias();
    af.anadirFamilia(&f1);
    af.anadirFamilia(&f2);
    af.anadirFamilia(&f3);
    cout<<"Menores 35 años: "<<af.contarMenoresEdad(35)<<endl;
    int n = 0;
    Miembro** empiezanPor = af.getConyugesInicial(&n, 'L');
    cout<<"---------------------------"<<endl;
    for(int i = 0; i<n;i++){
        cout<<empiezanPor[i]->getNombre()<<endl;
    }
    return 0;
}

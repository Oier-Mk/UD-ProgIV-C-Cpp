#include "persona.h"
#include "censo.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	Persona personas[5];
	personas[0].nombre="Hodei"; personas[0].edad=6;
	personas[1].nombre="Anita"; personas[1].edad=41;
	personas[2].nombre="Aitor"; personas[2].edad=12;
	personas[3].nombre="Idoia"; personas[3].edad=31;
	personas[4].nombre="Maite"; personas[4].edad=24;

	imprimirPersona(personas[0]);

	///Parte 1
    printf("Introduzca la edad maxima que quiere que tengan los contados:\t"); int edad = inputNumero(2);
	printf("Personas menores de %i anyos = %i\n",edad,cuantasPersonas(personas, 5, edad));
	GrupoPersonas g = recuperarJovenes(personas,5); imprimirGrupo(g);
	printf("La persona mas joven es: "); imprimirPersona(*recuperarYogurin(personas,5));

	///Parte 2
    crearInforme(g,fopen("fichero.txt", "w"));

	///Parte 3
	printf("Nombres con la inicial ‘A’:\t");
	printf("%i\n",cuantosNombres(personas, 5, 'A'));
    imprimirListado(listadoNombres(personas, 5, 'A'), cuantosNombres(personas, 5, 'A'));

        return 0;
}

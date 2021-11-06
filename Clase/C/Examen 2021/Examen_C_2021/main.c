#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vacuna.h"

int main(void)
{
	Vacuna v1; v1.id = 1; strcpy(v1.nombre, "Astro-Ficus");
	Vacuna v2; v2.id = 2; strcpy(v2.nombre, "Antigua");
	Vacuna v3; v3.id = 3; strcpy(v3.nombre, "Rasputin");

	imprimirVacuna(v1);
	printf("\n");
	imprimirVacuna(v2);
	printf("\n");
	imprimirVacuna(v3);
	printf("\n");	
	
	/* PARTE 1 */printf("-----\n");


	/* PARTE 2 */printf("-----\n");

	
	/* PARTE 3 */printf("-----\n");

	
	return 0;
}

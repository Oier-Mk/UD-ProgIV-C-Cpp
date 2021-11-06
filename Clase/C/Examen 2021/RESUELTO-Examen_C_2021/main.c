#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vacuna.h"
#include "grupoVacunacion.h"

void escribirPacientes(char ** dniMal, int nMal,char* fichero);

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

	/* PARTE 1 */printf("--PARTE 1--\n");

	GrupoVacunacion gv1;
	inicializarGrupo(&gv1,0,45,v1);
	imprimirGrupo(gv1);
	GrupoVacunacion gv2;
	inicializarGrupo(&gv2,46,65,v2);
	imprimirGrupo(gv2);
	GrupoVacunacion gv3;
	inicializarGrupo(&gv3,66,100,v3);
	imprimirGrupo(gv3);

	/* PARTE 2 */printf("--PARTE 2--\n");

	Paciente p1;  strcpy(p1.DNI, "11111111A"); p1.edad = 25;
	Paciente grupo1[] = {p1};
	asignarPacientes(&gv1,grupo1,1);
	imprimirPacientes(gv1,1);

	Paciente p2; strcpy(p2.DNI, "22222222B"); p2.edad = 50;
	Paciente p3; strcpy(p3.DNI, "33333333C"); p3.edad = 60;
	Paciente grupo2[] = {p2,p3};
	asignarPacientes(&gv2,grupo2,2);
	imprimirPacientes(gv2,2);

	Paciente p4; strcpy(p4.DNI, "44444444D"); p4.edad = 50;
	Paciente p5; strcpy(p5.DNI, "55555555E"); p5.edad = 52;
	Paciente p6; strcpy(p6.DNI, "66666666F"); p6.edad = 75;
	Paciente grupo3[] = {p4,p5,p6};
	asignarPacientes(&gv3,grupo3,3);
	imprimirPacientes(gv3,3);

	/* PARTE 3 */printf("--PARTE 3--\n");

	int nMalAsignados = 0;
	char** malAsig = obtenerDnisMalAsignados(&gv3,&nMalAsignados);
	printf("Cantidad de pacientes mal asignados en el G3: %i\n",nMalAsignados);
	escribirPacientes(malAsig,nMalAsignados,"malAsignadosGv3.txt");
	
	free(gv1.pacientes);
	free(gv2.pacientes);
	free(gv3.pacientes);

	return 0;
}

void escribirPacientes(char ** dniMal, int nMal,char* fichero){
	FILE* f = fopen(fichero,"w");
	for(int i = 0; i< nMal;i++){
		for(int j = 0; j<9;j++){
			fprintf(f,"%c",dniMal[i][j]);
		}
		fprintf(f,"\n");
	}
	fclose(f);
}

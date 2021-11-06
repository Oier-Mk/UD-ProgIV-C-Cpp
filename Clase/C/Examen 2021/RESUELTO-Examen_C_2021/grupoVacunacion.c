/*
 * grupoVacunacion.c
 *
 *  Created on: 23 abr. 2021
 *      Author: oiermentxaka
 */
#include "grupoVacunacion.h"
#include "vacuna.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inicializarGrupo(GrupoVacunacion *gv, int eMin, int eMax, Vacuna v){
	gv->eMax = eMax;
	gv->eMin = eMin;
	gv->vacuna = v;
}
void imprimirGrupo(GrupoVacunacion v){
	printf("Grupo vacunacion desde %i hasta %i años\nVacuna asignada: %i-%s\n",v.eMin, v.eMax,v.vacuna.id, v.vacuna.nombre );
}


void asignarPacientes(GrupoVacunacion *gv, Paciente *ap, int nPct){
	gv->nPct = nPct;
	gv->pacientes = malloc(sizeof(Paciente)*nPct);
	for(int i = 0; i<nPct; i++){
		gv->pacientes[i] = ap[i];
	}
}
void imprimirPacientes(GrupoVacunacion gv,int num){
	printf("Grupo de vacunacion %i: \n",num);
	for (int i = 0; i < gv.nPct; i++){
		printf("%s - %i años\n",gv.pacientes[i].DNI,gv.pacientes[i].edad);
	}
}


char** obtenerDnisMalAsignados(GrupoVacunacion *gv, int *nMalAsignados){

	int cont = 0;
	int mal = 0;
	for(int i = 0; i<gv->nPct; i++){
		if(gv->pacientes[i].edad < gv->eMin || gv->pacientes[i].edad > gv->eMax)
			mal++;
	}

	char **listado = malloc(sizeof(char*)*cont);
	for(int i = 0; i<mal;i++){
		if(gv->pacientes[i].edad < gv->eMin || gv->pacientes[i].edad > gv->eMax) {
			listado[cont] = gv->pacientes[i].DNI;
			cont++;
		}
	}

	*nMalAsignados = mal;
	return listado;
}


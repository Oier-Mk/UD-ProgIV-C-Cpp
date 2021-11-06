/*
 * grupoVacunacion.h
 *
 *  Created on: 23 abr. 2021
 *      Author: oiermentxaka
 */

#include "vacuna.h"
#ifndef GRUPOVACUNACION_C_
#define GRUPOVACUNACION_C_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int edad;
	char DNI[9];
}Paciente;

typedef struct{
	int eMax;
	int eMin;
	Vacuna vacuna;
	int nPct;
	Paciente *pacientes;
}GrupoVacunacion;



void inicializarGrupo(GrupoVacunacion *gv, int eMin, int eMax, Vacuna v);
void imprimirGrupo(GrupoVacunacion v);

void asignarPacientes(GrupoVacunacion *gv, Paciente *ap, int nPct);
void imprimirPacientes(GrupoVacunacion gv,int num);

char** obtenerDnisMalAsignados(GrupoVacunacion *gv, int *nMalAsignados);

#endif /* DEBUG_GRUPOVACUNACION_C_ */

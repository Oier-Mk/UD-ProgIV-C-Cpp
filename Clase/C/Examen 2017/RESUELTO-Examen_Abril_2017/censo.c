//
// Created by Oier Mentxaka on 16/4/21.
//
#include "persona.h"
#include "censo.h"
#include <stdlib.h>
#include <stdio.h>

int cuantasPersonas(Persona *ap, int tamano, int edad){
    int cont = 0;
    for(int i = 0; i < tamano; i++){
        if(ap[i].edad < edad) cont++;
    }
    return cont;
}

GrupoPersonas recuperarJovenes(Persona *ap, int tamano){
	GrupoPersonas g;
    int edad = 30;
    int cont = 0;
    int media = 0;
    g.n = cuantasPersonas(ap,tamano,edad);
    g.personas = malloc(sizeof(Persona)*g.n);
    for(int i = 0; i < tamano; i++){
        if(ap[i].edad < edad){
            g.personas[cont] = ap[i];
            media += ap[i].edad;
            cont++;
        }
    }
    g.avgEdad = media/g.n;
    return g;
}
Persona* recuperarYogurin(Persona *ap, int tamano){
    Persona *p = malloc(sizeof(Persona));
    p = &ap[0];
    for(int i = 1; i < tamano; i++){
        if(ap[i].edad < p->edad) p = &ap[i];
    }
    return p;
}

void imprimirGrupo(GrupoPersonas g){
	printf("Imprimiendo un grupo de personas...\n");
	for(int i = 0; i<g.n; i++){
		imprimirPersona(g.personas[i]);
	}
}

void crearInforme(GrupoPersonas g, char* f){
    fprintf(f,"CENSO DE JOVENES\n");
    fprintf(f,"----------------\n");
    for(int i = 0; i<g.n; i++){
        fprintf(f,"[Nombre: %s, Edad: %i]\n", g.personas[i].nombre, g.personas[i].edad);
    }
    fprintf(f,"Media: %i\n",g.avgEdad);
}
int inputNumero(int size) { //INTRODUCE UN NUMERO MAYOR QUE 0
    fflush(stdin);
    int num;
    size++;
    char str[size];
    fgets(str, size, stdin);
    sscanf(str, "%i", &num);
    return num;
}

int cuantosNombres(Persona *ap, int tamano, char letra){
    int cont = 0;
    for(int i = 0; i<tamano; i++){
        if(ap[i].nombre[0] == letra) cont++;
    }
    return cont;
}

char** listadoNombres(Persona *ap, int tamano, char letra){ //Devuelve array de punteros a nombres
    char** listado;
    listado = malloc(sizeof(char*)*cuantosNombres(ap,tamano,letra));
    int cont = 0;
    for(int i = 0; i < tamano; i++){
        if(ap[i].nombre[0] == letra) {
            listado[cont] = ap[i].nombre;//TODO
            cont++;
        }
    }
    return listado;
}

void imprimirListado(char** l,int tamano){
    printf("Imprimiendo listado...\n");
    for(int i = 0; i < tamano; i++){
        printf("%s\n",l[i]);
    }
}

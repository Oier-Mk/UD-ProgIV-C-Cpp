//
// Created by Oier Mentxaka on 16/4/21.
//

#ifndef EXAMEN_2017_CENSO_H
#define EXAMEN_2017_CENSO_H

typedef struct{
    int n;
    Persona *personas;
    int avgEdad;
}GrupoPersonas;

int cuantasPersonas(Persona *ap, int tamano, int edad);
GrupoPersonas recuperarJovenes(Persona *ap, int tamano);
Persona* recuperarYogurin(Persona *ap, int tamano);
void imprimirGrupo(GrupoPersonas g);
void crearInforme(GrupoPersonas gp, char* fichero);
int inputNumero(int size);
int cuantosNombres(Persona *ap, int tamanyo, char letra);
char** listadoNombres(Persona *ap, int tamanyo, char letra);
void imprimirListado(char** l, int tamano);

#endif //EXAMEN_2017_CENSO_H

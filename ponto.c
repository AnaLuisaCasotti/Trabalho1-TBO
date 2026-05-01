#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ponto.h"

typedef struct Ponto {
    char *id;
    int indice;
    int qntCoord;
    double *coordenada;
} tPonto;

tPonto* criaPonto(char *id, double *coordenadas, int qntCoord){
    tPonto *p;

    p = (tPonto*) calloc(1, sizeof(tPonto));

    p->id = (char*) calloc(strlen(id)+1, sizeof(char));

    strcpy(p->id, id);

    p->indice = 0;
    
    p->qntCoord = qntCoord;

    p->coordenada = (double*) calloc(qntCoord, sizeof(double));

    for(int i = 0; i < qntCoord; i++){
        p->coordenada[i] = coordenadas[i];
    }

    return p;
}

double distanciaEuclidiana(tPonto *p1, tPonto *p2){
    double dist = 0;

    for(int i = 0; i < p1->qntCoord; i++){
        dist += pow((p2->coordenada[i] - p1->coordenada[i]), 2);
    }

    return sqrt(dist);
}

int getIndice(tPonto *p){
    return p->indice;
}

void setIndice(tPonto *p, int novoIndice){
    p->indice = novoIndice;
}

void imprimePonto(tPonto *p, FILE *fp){
    printf("Ponto: %s, indice: %d\n", p->id, p->indice);

    for(int i = 0; i < p->qntCoord; i++){
        printf("dist %d: %.2f\n", i, p->coordenada[i]);
    }

    //fprintf(fp, "Ponto: %s, x: %f, y: %f\n", p->id, p->x, p->y);
}

void desalocaPonto(tPonto *p){
    free(p->id);
    free(p->coordenada);
    free(p);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ponto.h"


typedef struct Ponto{
    char *id;
    int indice;
    double x;
    double y;
} tPonto;

tPonto* criaPonto(char *id, int indice, double x, double y){
    tPonto *p;

    p = (tPonto*) calloc(1, sizeof(tPonto));

    p->id = (char*) calloc(strlen(id)+1, sizeof(char));

    strcpy(p->id, id);

    p->indice = indice;
    p->x = x;
    p->y = y;

    return p;
}

double distanciaEuclidiana(tPonto *p1, tPonto *p2){
    return sqrt(pow((p2->x - p1->x) , 2) + pow((p2->y - p1->y), 2));
}

int getIndice(tPonto *p){
    return p->indice;
}

void setIndice(tPonto *p, int novoIndice){
    p->indice = novoIndice;
}

void imprimePonto(tPonto *p, FILE *fp){
    printf("Ponto: %s, indice: %d, x: %.2f, y: %.2f\n", p->id, p->indice, p->x, p->y);
    //fprintf(fp, "Ponto: %s, x: %f, y: %f\n", p->id, p->x, p->y);
}

void desalocaPonto(tPonto *p){
    free(p->id);
    free(p);
}
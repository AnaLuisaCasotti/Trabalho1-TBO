#include <stdio.h>
#include <stdlib.h>

#include "aresta.h"

typedef struct Aresta {
    double dist;
    tPonto *v1;
    tPonto *v2;
} tAresta;

tAresta* inicializaAresta(double dist, tPonto *v1, tPonto *v2){

    tAresta *aresta = malloc (sizeof(tAresta));

    aresta->dist = dist;
    aresta->v1 = v1;
    aresta->v2 = v2;

    return aresta;
}

int retornaIndicePonto1(tAresta *aresta){

    return getIndiceOriginal(aresta->v1);
}

int retornaIndicePonto2(tAresta *aresta){

    return getIndiceOriginal(aresta->v2);
}

double retornaDistancia(tAresta *aresta){

    return aresta->dist;
}

void imprimeAresta(tAresta *aresta){
    
    printf("Aresta: v1=%s, v2=%s, dist=%f\n", getIdPonto(aresta->v1), getIdPonto(aresta->v2), aresta->dist);
}

void desalocaAresta(tAresta *aresta){

    free(aresta);
}
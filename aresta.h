#ifndef aresta_h
#define aresta_h

#include "ponto.h"

typedef struct Aresta tAresta;

/*@param: 
    double dist: distância entre dois pontos;
    tPonto *v1, *v2: o ponteiro para os dois pontos;
@return: uma estrutura tAresta alocada na memória*/
tAresta* inicializaAresta(double dist, tPonto *v1, tPonto *v2);

/*@param: tAresta *aresta: o ponteiro para a aresta
@return: um número double que representa a distância correspondente à aresta*/
double retornaDistancia(tAresta *aresta);

/*@param: tPonto *p: o ponteiro para o ponto p que será desalocado;*/
void desalocaAresta(tAresta *aresta);

#endif


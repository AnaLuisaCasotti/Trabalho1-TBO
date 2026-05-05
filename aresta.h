#ifndef aresta_h
#define aresta_h

#include "ponto.h"

typedef struct Aresta tAresta;

tAresta* inicializaAresta(double dist, tPonto *v1, tPonto *v2);
double retornaDistancia(tAresta *aresta);

/*@param: tPonto *p: o ponteiro para o ponto p que será desalocado;*/
void desalocaAresta(tAresta *aresta);

#endif


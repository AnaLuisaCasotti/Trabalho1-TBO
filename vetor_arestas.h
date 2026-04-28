#ifndef vetor_arestas
#define vetor_arestas

#include "aresta.h"

typedef struct VetorArestas tVetorArestas;

tVetorArestas* criaVetorArestas(int numPontos);
void adicionaAresta(tVetorArestas *vetor, tAresta *aresta);
void ordenaArestas(tVetorArestas *vetor);
void imprimeArestas(tVetorArestas *vetor);
void desalocaVetorArestas(tVetorArestas *vetor);

#endif
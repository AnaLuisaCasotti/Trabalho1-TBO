#ifndef vetor_pontos
#define vetor_pontos

#include "ponto.h"
#include "vetor_arestas.h"

typedef struct VetorPontos tVetorPontos;

tVetorPontos* criaVetorPontos();
void adicionaPonto(tVetorPontos *vetor, tPonto *p);
void geraArestas(tVetorPontos *vetorPontos, tVetorArestas *vetorArestas);
int tamVetorPontos(tVetorPontos *vetor);
void desalocaVetorPontos(tVetorPontos *vetor);

#endif
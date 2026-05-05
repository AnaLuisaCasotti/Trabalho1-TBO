#ifndef VETOR_ARESTAS_H
#define VETOR_ARESTAS_H

#include "aresta.h"

typedef struct VetorArestas tVetorArestas;

/*@param:
    int numPontos: inteiro contendo a quantidade de pontos;
@return: cria um vetor de arestas*/
tVetorArestas* criaVetorArestas(int numPontos);

/*@param: 
    tVetorArestas *vetor: ponteiro pro vetor de arestas;
    taresta *aresta: ponteiro pra aresta que será adicionada ao vetor;*/
void adicionaAresta(tVetorArestas *vetor, tAresta *aresta);

/*@param:
    tVetorArestas *vetor: ponteiro pro vetor de arestas;*/
void ordenaArestas(tVetorArestas *vetor);

/*@param:
    tVetorArestas *vetor: ponteiro pro vetor de arestas;*/
void imprimeArestas(tVetorArestas *vetor);

/*@param:
    tVetorArestas *vetor: ponteiro pro vetor de arestas que será desalocado;*/
void desalocaVetorArestas(tVetorArestas *vetor);

#endif

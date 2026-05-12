#ifndef VETOR_ARESTAS_H
#define VETOR_ARESTAS_H

#include "aresta.h"

typedef struct VetorPontos tVetorPontos;

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
    tVetor#include "vetor_pontos.h"
Arestas *vetor: ponteiro pro vetor de arestas;*/
void ordenaArestas(tVetorArestas *vetor);

/*@param:
    tVetorArestas *vetor: ponteiro pro vetor de arestas;*/
void imprimeArestas(tVetorArestas *vetor);

/*@param:
    tVetorArestas *vetor: ponteiro para o vetor de arestas;
    tVetorPontos *vetor: ponteiro para o vetor de pontos;*/
tVetorArestas* unionArestas(tVetorArestas *vetorArestas, tVetorPontos *vetorPontos, int tam);

/*@param:
    tVetorArestas *vetor: ponteiro pro vetor de arestas;
    int indice: indice da aresta a ser excluída;*/
void excluiAresta(tVetorArestas *vetor, int indice);

/*@param:
    tVetorArestas *vetor: ponteiro pro vetor de arestas;
    int n: n - 1 é a qtd de arestas a serem removidas;*/
void removeMaioresArestas(tVetorArestas *vetor, int n);

/*@param:
    tVetorArestas *vetor: ponteiro para o vetor de arestas;
    tVetorPontos *vetor: ponteiro para o vetor de pontos;*/
void clusterizacao(tVetorArestas *vetorArestas, tVetorPontos *vetorPontos);

/*@param:
    tVetorArestas *vetor: ponteiro pro vetor de arestas;*/
tAresta** getVetorAresta(tVetorArestas *vetor);

/*@param:
    tVetorArestas *vetor: ponteiro pro vetor de arestas que será desalocado;*/
void desalocaVetorArestas(tVetorArestas *vetor);

#endif

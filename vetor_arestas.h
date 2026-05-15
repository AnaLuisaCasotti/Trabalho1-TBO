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
    tVetorArestas *vetor: ponteiro pro vetor de arestas;
#### @explicação: ####
    Utiliza propriedades da Estrutura de Dados Heap para ordenar 
    o vetor de arestas, por meio da função heapifyDown*/
void constroiHeap(tVetorArestas *vetor);

/*@param:
    tVetorArestas *vetor: ponteiro pro vetor de arestas;
    int i: índice do elemento que deverá ser reorganizado dentro da heap;
#### @explicação: ####
    Na heap, vai "descendo" o elemento (inicialmente na posição i) até que ele esteja na
    posição correta, mantendo a relação de que cada pai não é maior que os filhos (Min-Heap)*/
void heapifyDown(tVetorArestas *vetor, int i);

/*@param:
    tVetorArestas *vetor: ponteiro para o vetor de arestas;
#### @explicação: ####
    Remove o menor elemento da heap (priemiro elemento do vetor), depois reorganiza a heap.
@return: A menor aresta presente na heap, que acabou de ser retirada do vetor*/
tAresta *removeMin(tVetorArestas *vetor);

/*@param:
    tVetorArestas *vetor: ponteiro para o vetor de arestas;
    tVetorPontos *vetor: ponteiro para o vetor de pontos;*/
void unionArestas(tVetorArestas *vetorArestas, tVetorPontos *vetorPontos, int tam);

/*@param:
    tVetorArestas *vetor: ponteiro pro vetor de arestas que será desalocado;*/
void desalocaVetorArestas(tVetorArestas *vetor);

/*@param:
    tVetorArestas *vetor: ponteiro pro vetor de arestas;*/
void imprimeArestas(tVetorArestas *vetor);

#endif

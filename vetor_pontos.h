#ifndef VETOR_PONTOS_H
#define VETOR_PONTOS_H

#include "ponto.h"
#include "vetor_arestas.h"

typedef struct VetorPontos tVetorPontos;

/*@return: Cria um vetor de pontos vazio*/
tVetorPontos* criaVetorPontos();

/*@param: 
    tVetorPontos *vetor: ponteiro pro vetor de pontos;
    tPonto *p: ponteiro pro ponto que será adicionado ao vetor;*/
void adicionaPonto(tVetorPontos *vetor, tPonto *p);

/*@param:
    tVetorPontos *vetor: ponteiro pro vetor de pontos;
    tVetorArestas *vetorArestas: ponteiro para o vetor de arestas;*/
void geraArestas(tVetorPontos *vetorPontos, tVetorArestas *vetorArestas);

/*@param:
    tVetorPontos *vetor: ponteiro pro vetor de pontos;
@return: um número inteiro referente ao tamanho atual do vetor de pontos*/
int tamVetorPontos(tVetorPontos *vetor);

/*@param:
    tVetorPontos *vetor: ponteiro pro vetor de pontos que será desalocado;*/
void desalocaVetorPontos(tVetorPontos *vetor);

#endif
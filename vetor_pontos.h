#ifndef VETOR_PONTOS_H
#define VETOR_PONTOS_H

#include "ponto.h"
#include "vetor_arestas.h"

typedef struct VetorPontos tVetorPontos;
typedef struct Grupo tGrupo;

/*@return: Cria um vetor de pontos vazio*/
tVetorPontos* criaVetorPontos();

/*@param:
    tVetorPontos *vetor: ponteiro para o vetor de pontos;
    int indice: valor inteiro correspondente ao índice ponto que será encontrado;*/
tPonto* getPonto(tVetorPontos *vetor, int indice);

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
    tVetorPontos *vetor: ponteiro pro vetor de pontos;
    int ind: valor inteiro correspondente ao ponto que será encontrado;
@return: valor do indíce do pai do conjunto;*/
int findPontos(tVetorPontos *vetorPontos, int ind);

/*@param:
    tVetorPontos *vetorPontos: ponteiro pro vetor de pontos;
    int ind1: valor inteiro correspondente ao índice do ponto 1;
    int ind2: valor inteiro correspondente ao índice do ponto 2;
@return: 1 se estiverem conectados, 0 caso contrário*/
int connectedPontos(tVetorPontos *vetorPontos, int ind1, int ind2);

/*@param:
    tVetorPontos *vetor: ponteiro pro vetor de pontos;
    int ind1: valor inteiro correspondente ao índice do ponto 1;
    int ind2: valor inteiro correspondente ao índice do ponto 2;*/
void unionPontos(tVetorPontos *vetorPontos, int ind1, int ind2);

/*@param:
    tVetorPontos *vetor: ponteiro pro vetor de pontos;*/
void resetaPontos(tVetorPontos *vetor);

/*IMPRESSÃO PARA TESTE*/
void imprimeVetorPontos(tVetorPontos *vetorPontos);

/*@param:
    tVetorPontos *vetor: ponteiro pro vetor de pontos;
    int n: número de grupos que serão criados;
@return: um grupo de pontos;*/
tGrupo* retornaGrupo(tVetorPontos *vetor, int n);

/*@param:
    tVetorPontos *vetor: ponteiro pro vetor de pontos;
    int n: número de grupos de pontos;
    FILE *saida: arquivo de saida*/
void imprimeGrupos(tVetorPontos *vetor, int n, FILE *saida);

/*@param:
    tGrupo *grupos: ponteiro para vetor de grupos que será desalocado;
    int n: inteiro correspondente ao número de grupos no vetor*/
void desalocaGrupos(tGrupo *grupos, int n);

/*@param:
    tVetorPontos *vetor: ponteiro pro vetor de pontos que será desalocado;*/
void desalocaVetorPontos(tVetorPontos *vetor);

#endif
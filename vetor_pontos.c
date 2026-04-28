#include <stdio.h>
#include <stdlib.h>
#include "vetor_pontos.h"

typedef struct VetorPontos {
    int tam;
    int cap;
    tPonto **pontos;
} tVetorPontos;

tVetorPontos* criaVetorPontos(){

    tVetorPontos *vetor = malloc (sizeof(tVetorPontos));

    vetor->tam = 0;
    vetor->cap = 1;
    vetor->pontos = malloc (vetor->cap * sizeof(tPonto*));

    return vetor;
}

void adicionaPonto(tVetorPontos *vetor, tPonto *p){

    if(vetor->tam == vetor->cap){

        vetor->cap *= 2;
        vetor->pontos = realloc (vetor->pontos, vetor->cap * sizeof(tPonto*));
    }

    vetor->pontos[vetor->tam] = p;
    vetor->tam++;
}

void geraArestas(tVetorPontos *vetorPontos, tVetorArestas *vetorArestas){

    int i, j, dist;

    for(i = 0; i < vetorPontos->tam; i++){

        for(j = i + 1; j < vetorPontos->tam; j++){

            dist = distanciaEuclidiana(vetorPontos->pontos[i], vetorPontos->pontos[j]);
            tAresta *a = inicializaAresta(dist, vetorPontos->pontos[i], vetorPontos->pontos[j]);
            adicionaAresta(vetorArestas, a);
        }
    }
}

int tamVetorPontos(tVetorPontos *vetor){

    return vetor->tam;
}

void desalocaVetorPontos(tVetorPontos *vetor){

    int i;

    for(i = 0; i < vetor->tam; i++){

        desalocaPonto(vetor->pontos[i]);
    }

    free(vetor->pontos);
    free(vetor);
}
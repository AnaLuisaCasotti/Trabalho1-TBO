#include <stdio.h>
#include <stdlib.h>
#include "vetor_pontos.h"

typedef struct VetorPontos {
    int tam;
    int cap;
    int *sz;
    tPonto **pontos;
} tVetorPontos;

tVetorPontos* criaVetorPontos(){

    tVetorPontos *vetor = malloc (sizeof(tVetorPontos));

    vetor->tam = 0;
    vetor->cap = 1;
    vetor->pontos = malloc (vetor->cap * sizeof(tPonto*));
    vetor->sz = (int*) calloc(1, sizeof(int));

    return vetor;
}

void adicionaPonto(tVetorPontos *vetor, tPonto *p){

    if(vetor->tam == vetor->cap){

        vetor->cap *= 2;
        vetor->pontos = realloc (vetor->pontos, vetor->cap * sizeof(tPonto*));
        vetor->sz = realloc(vetor->sz, vetor->cap * sizeof(int));
    }

    vetor->sz[vetor->tam] = 1;

    vetor->pontos[vetor->tam] = p;
    setIndiceOriginal(p, vetor->tam);
    vetor->tam++;
}

void geraArestas(tVetorPontos *vetorPontos, tVetorArestas *vetorArestas){

    int i, j;
    double dist;

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

int findPontos(tVetorPontos *vetorPontos, int ind){
    while(getIndiceAtual(vetorPontos->pontos[ind]) != ind){
        setIndice(vetorPontos->pontos[ind], getIndiceAtual(vetorPontos->pontos[getIndiceAtual(vetorPontos->pontos[ind])])); // equivale ao id[i] = id[id[i]] so professor
        ind = getIndiceAtual(vetorPontos->pontos[ind]); //buscar o pai até a raiz
    }

    return ind; //profundidade de ind acessos
}

int connectedPontos(tVetorPontos *vetorPontos, int ind1, int ind2){
    int raiz1 = findPontos(vetorPontos, ind1);
    int raiz2 = findPontos(vetorPontos, ind2);

    if (raiz1 == raiz2) return 1;
    else return 0;
}

void unionPontos(tVetorPontos *vetorPontos, int ind1, int ind2){
    int i = findPontos(vetorPontos, ind1);
    int j = findPontos(vetorPontos, ind2);
    
    if(i == j) return;

    if(vetorPontos->sz[i] < vetorPontos->sz[j]){
        setIndice(vetorPontos->pontos[i], j);
        vetorPontos->sz[j] += vetorPontos->sz[i];
    }

    else{
        setIndice(vetorPontos->pontos[j], i);
        vetorPontos->sz[i] += vetorPontos->sz[j];
    }
}

void imprimeVetorPontos(tVetorPontos *vetorPontos){
    for(int i = 0; i < vetorPontos->tam; i++){
        imprimePonto(vetorPontos->pontos[i], NULL);
    }
}


void desalocaVetorPontos(tVetorPontos *vetor){

    int i;

    for(i = 0; i < vetor->tam; i++){

        desalocaPonto(vetor->pontos[i]);
    }

    free(vetor->sz);
    free(vetor->pontos);
    free(vetor);
}
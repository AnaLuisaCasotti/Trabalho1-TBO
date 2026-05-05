#include <stdio.h>
#include <stdlib.h>
#include "vetor_arestas.h"
#include "vetor_pontos.h"

typedef struct VetorArestas {
    int tam;
    int cap;
    tAresta **arestas;
} tVetorArestas;

static int comparaAresta(const void *a, const void *b){

    tAresta *a1 = *(tAresta**) a;
    tAresta *a2 = *(tAresta**) b;

    if(retornaDistancia(a1) < retornaDistancia(a2)){

        return -1;
    }
    else if(retornaDistancia(a1) > retornaDistancia(a2)){

        return 1;
    }
    else{

        return 0;
    }
}

tVetorArestas* criaVetorArestas(int numPontos){

    tVetorArestas *vetor = malloc (sizeof(tVetorArestas));

    vetor->tam = 0;
    vetor->cap = (numPontos * (numPontos - 1)) / 2;
    vetor->arestas = malloc (vetor->cap * sizeof(tAresta*));

    return vetor;
}

void adicionaAresta(tVetorArestas *vetor, tAresta *aresta){

    vetor->arestas[vetor->tam] = aresta;
    vetor->tam++;
}

void ordenaArestas(tVetorArestas *vetor){

    qsort(vetor->arestas, vetor->tam, sizeof(tAresta*), comparaAresta);
}

void imprimeArestas(tVetorArestas *vetor){

    int i;

    printf("\nArestas ordenadas:\n");

    for(i = 0; i < vetor->tam; i++){

        printf("%lf ", retornaDistancia(vetor->arestas[i]));
    }
    printf("\n");
}

void unionArestas(tVetorArestas *vetorArestas, tVetorPontos *vetorPontos){
    int unidos, ind1, ind2;

    for(int i = 0; i < vetorArestas->tam; i++){
        unidos = 0;

        ind1 = retornaIndicePonto1(vetorArestas->arestas[i]);
        ind2 = retornaIndicePonto2(vetorArestas->arestas[i]);

        if(i == 0){
            unionPontos(vetorPontos, ind1, ind2);
            imprimeAresta(vetorArestas->arestas[i]);
        }

        else{
            unidos = connectedPontos(vetorPontos, ind1, ind2);

            if(unidos == 0){
                unionPontos(vetorPontos, ind1, ind2);
                imprimeAresta(vetorArestas->arestas[i]);
            }

            else{
                excluiAresta(vetorArestas, i);
                i--;
            }
        }

    }

    printf("unionArestas() chegou ao fim\n"); // teste
}

void excluiAresta(tVetorArestas *vetor, int indice){

    tAresta *aresta_temp = vetor->arestas[indice];
    
    for(int i = indice; i <  vetor->tam - 1; i++){

        vetor->arestas[i] = vetor->arestas[i+1];
    }

    vetor->tam--;
    vetor->arestas[vetor->tam] = NULL; // Elimina a última posição do vetor que ficou sobrando

    desalocaAresta(aresta_temp);
}

void desalocaVetorArestas(tVetorArestas *vetor){

    int i;

    for(i = 0; i < vetor->tam; i++){

        desalocaAresta(vetor->arestas[i]);
    }

    free(vetor->arestas);
    free(vetor);
}
#include <stdio.h>
#include <stdlib.h>
#include "vetor_arestas.h"
#include "vetor_pontos.h"

typedef struct VetorArestas {
    int tam;
    int cap;
    tAresta **arestas;
} tVetorArestas;

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

void constroiHeap(tVetorArestas *vetor){

    for (int i = vetor->tam/2; i >= 0; i--){
        heapifyDown(vetor, i);
    }
}

// Compara o pai (vetor[i]) com os filhos.
// Se algum filho for menor, troca de posição com ele
void heapifyDown(tVetorArestas *vetor, int i){

    while(1){

        int menor = i;
        int tam = vetor->tam;

        int esq = 2*i + 1; // filho esq
        int dir = 2*i + 2; // filho dir

        if (esq < tam){
            if (retornaDistancia(vetor->arestas[esq]) < retornaDistancia(vetor->arestas[menor])){
                menor = esq;
            }
        }

        if (dir < tam){
            if (retornaDistancia(vetor->arestas[dir]) <  retornaDistancia(vetor->arestas[menor])){
                menor = dir;
            }
        }

        if (menor == i) break; // Para quando a aresta está no seu devido lugar

        trocaArestas(vetor->arestas[i], vetor->arestas[menor]);

        i = menor;
    }
}

tAresta *removeMin(tVetorArestas *vetor){
    tAresta *min = vetor->arestas[0]; // Topo da heap: menor aresta

    vetor->tam--;

    vetor->arestas[0] = vetor->arestas[vetor->tam]; // Joga a última aresta no topo. Remove menor aresta

    heapifyDown(vetor, 0); // Reorganiza a min heap

    return min;
}

void unionArestas(tVetorArestas *vetorArestas, tVetorPontos *vetorPontos, int tam){

    int unidos, ind1, ind2, adicionados = 0;

    int completo = tamVetorPontos(vetorPontos) - tam; // Cálculo da quantidade final de arestas válidas e que serão utilizadas nas uniões 
    // O cálculo já considera a remoção das k-1 maiores arestas que seriam eliminadas depois

    while(completo > adicionados){

        tAresta *a = removeMin(vetorArestas); // Remove aresta no topo da heap (menor aresta)

        ind1 = retornaIndicePonto1(a);
        ind2 = retornaIndicePonto2(a);

        unidos = connectedPontos(vetorPontos, ind1, ind2); // Verifica se os pontos já estão conectados

        if(unidos == 0){
            unionPontos(vetorPontos, ind1, ind2);
            adicionados++;
        }

        desalocaAresta(a);
    }
}

void desalocaVetorArestas(tVetorArestas *vetor){

    int i;
    
    for(i = 0; i < vetor->tam; i++){

        desalocaAresta(vetor->arestas[i]);
    }

    free(vetor->arestas);
    free(vetor);
}

void imprimeArestas(tVetorArestas *vetor){

    int i;

    printf("\nArestas ordenadas:\n");

    for(i = 0; i < vetor->tam; i++){

        printf("%lf ", retornaDistancia(vetor->arestas[i]));
    }
    printf("\n");
}
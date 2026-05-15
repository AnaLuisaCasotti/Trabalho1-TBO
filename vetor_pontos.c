#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor_pontos.h"

typedef struct VetorPontos {
    int tam;
    int cap;
    int *sz;
    tPonto **pontos;
} tVetorPontos;

typedef struct Grupo {
    int tam;
    tPonto **pontos;
} tGrupo;

static int comparaPontos(const void *a, const void *b){
    
    tPonto *p1 = *(tPonto**) a;
    tPonto *p2 = *(tPonto**) b;

    return strcmp(getIdPonto(p1), getIdPonto(p2));
}

static int comparaGrupos(const void *a, const void *b){
    
    tGrupo *g1 = (tGrupo*) a;
    tGrupo *g2 = (tGrupo*) b;

    return strcmp(getIdPonto(g1->pontos[0]), getIdPonto(g2->pontos[0]));
}

tVetorPontos* criaVetorPontos(){

    tVetorPontos *vetor = malloc (sizeof(tVetorPontos));

    vetor->tam = 0;
    vetor->cap = 1;
    vetor->pontos = malloc (vetor->cap * sizeof(tPonto*));
    vetor->sz = (int*) calloc(1, sizeof(int));

    return vetor;
}

tPonto* getPonto(tVetorPontos *vetor, int indice){

    return vetor->pontos[indice];
}

void adicionaPonto(tVetorPontos *vetor, tPonto *p){

    if(vetor->tam == vetor->cap){

        vetor->cap *= 2;
        vetor->pontos = realloc(vetor->pontos, vetor->cap * sizeof(tPonto*));
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

    int val = ind;
    
    while(getIndiceAtual(vetorPontos->pontos[ind]) != ind){

        setIndice(vetorPontos->pontos[ind], getIndiceAtual(vetorPontos->pontos[getIndiceAtual(vetorPontos->pontos[ind])])); // equivale ao id[i] = id[id[i]] do professor
        ind = getIndiceAtual(vetorPontos->pontos[ind]);   // buscar o pai até a raiz
    }

    while(getIndiceAtual(vetorPontos->pontos[val]) != ind){   // segunda passada da compressão de caminho: deixar mais perto de O(1)

        setIndice(vetorPontos->pontos[val], getIndiceAtual(vetorPontos->pontos[getIndiceAtual(vetorPontos->pontos[val])]));   // equivale ao id[i] = id[id[i]] do professor
    }

    return ind;   // profundidade de ind acessos
}

int connectedPontos(tVetorPontos *vetorPontos, int ind1, int ind2){

    return (findPontos(vetorPontos, ind1) == findPontos(vetorPontos, ind2));
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

void resetaPontos(tVetorPontos *vetor){

    int i;

    for(i = 0; i < vetor->tam; i++){

        setIndice(vetor->pontos[i], i);
        vetor->sz[i] = 1;
    }
}

void imprimeVetorPontos(tVetorPontos *vetorPontos){
    
    int i;

    for(i = 0; i < vetorPontos->tam; i++){
        printf("Ponto: %s, indice final: %d\n", getIdPonto(vetorPontos->pontos[i]), getIndiceAtual(vetorPontos->pontos[i]));

        //imprimePonto(vetorPontos->pontos[i], NULL);
    }
}

tGrupo* retornaGrupo(tVetorPontos *vetor, int n){

    int i, raiz, idGrupo = 0, idPonto = 0, tam = vetor->tam, adicionado[n];
    int grupo[tam];

    tGrupo *grupos = malloc(n * sizeof(tGrupo));

    for(i = 0; i < tam; i++){

        if(i < n){
            adicionado[i] = 0;
        }

        grupo[i] = -1;
    }

    for(i = 0; i < tam; i++){

        raiz = findPontos(vetor, i);

        if(grupo[raiz] == -1){

            grupo[raiz] = idGrupo;
            grupos[idGrupo].tam = vetor->sz[raiz];
            grupos[idGrupo].pontos = malloc((vetor->sz[raiz] + 1) * sizeof(tPonto*));
            idGrupo++;
        }

        if(idGrupo >= n) break;
    }

    for(i = 0; i < tam; i++){

        raiz = findPontos(vetor, i);

        idGrupo = grupo[raiz];
        idPonto = adicionado[idGrupo];

        grupos[idGrupo].pontos[idPonto] = vetor->pontos[i];
        adicionado[idGrupo]++;
    }

    for(i = 0; i < n; i++){

        qsort(grupos[i].pontos, grupos[i].tam, sizeof(tPonto*), comparaPontos);
        grupos[i].pontos[grupos[i].tam] = NULL;
    }

    qsort(grupos, n, sizeof(tGrupo), comparaGrupos);

    return grupos;
}

void imprimeGrupos(tVetorPontos *vetor, int n, FILE *saida){
    
    int i, j;

    tGrupo *grupos = retornaGrupo(vetor, n);

    for(i = 0; i < n; i++){
        
        j = 0;

        while(grupos[i].pontos[j] != NULL){

            imprimePonto(grupos[i].pontos[j], saida);
            j++;
        }

        fprintf(saida, "\n");
    }

    desalocaGrupos(grupos, n);
}

void desalocaGrupos(tGrupo *grupos, int n){
    for(int i = 0; i < n; i++){
        free(grupos[i].pontos);
    }

    free(grupos);
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
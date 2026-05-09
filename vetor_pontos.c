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
        ind = getIndiceAtual(vetorPontos->pontos[ind]);      // buscar o pai até a raiz
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

        imprimePonto(vetorPontos->pontos[i], NULL);
    }
}

static int comparaPontos(const void *a, const void *b){
    
    tPonto *p1 = *(tPonto**) a;
    tPonto *p2 = *(tPonto**) b;

    return strcmp(getIdPonto(p1), getIdPonto(p2));
}

static int comparaGrupos(const void *a, const void *b){
    
    tPonto **v1 = *(tPonto***) a;
    tPonto **v2 = *(tPonto***) b;

    return strcmp(getIdPonto(v1[0]), getIdPonto(v2[0]));
}

tPonto*** retornaCluster(tVetorPontos *vetor, int n){

    int tam = vetor->tam;
    tPonto ***grupos;
    int adicionado[n], finds[tam];
    int i, raiz, indx_grupo = 0, indx_ponto = 0;

    for(i = 0; i < n; i++){

        adicionado[i] = 0;
    }

    grupos = (tPonto***) calloc(n, sizeof(tPonto**));

    for(int i = 0; i < tam; i++) finds[i] = -1; //raizes deafault = -1

    for(i = 0; i < tam; i++){
        raiz = findPontos(vetor, i); // acha a raiz do ponto
        //[A: raiz 0, B: raiz 2; C: raiz 2, D: raiz 0]

        if(finds[raiz] == -1){ //se o valor do find dessa raiz == -1, então ela ainda não foi setada
            finds[raiz] = indx_grupo; // setando para todas as raízes um grupo

            adicionado[indx_grupo] = 0; // quantidade de pontos em cada grupo atualmente
            grupos[indx_grupo] = (tPonto**) calloc(vetor->sz[raiz]+1, sizeof(tPonto*)); //aloca o espaço de acordo com o sz do quick-union que a gnt já tinha

            indx_grupo++;
        }
    }

    for(i = 0; i < tam; i++){
        raiz = findPontos(vetor, i);

        indx_grupo = finds[raiz];
        indx_ponto = adicionado[indx_grupo];

        grupos[indx_grupo][indx_ponto] = vetor->pontos[i];

        adicionado[indx_grupo]++;
    }

    for(i = 0; i < n; i++){
        indx_ponto = adicionado[i];
        qsort(grupos[i], indx_ponto, sizeof(tPonto*), comparaPontos);
        grupos[i][indx_ponto] = NULL;
    }

    qsort(grupos, n, sizeof(tPonto**), comparaGrupos);
    
    return grupos;
}

void imprimeClusters(tVetorPontos *vetor, int n, FILE *saida){
    
    int i, j;
    tPonto ***matriz = retornaCluster(vetor, n);

    for(i = 0; i < n; i++){
        
        j = 0;

        while(matriz[i][j] != NULL){

            imprimePonto(matriz[i][j], saida);
            j++;
        }

        fprintf(saida, "\n");
    }

    for(i = 0; i < n; i++){

        free(matriz[i]);
    }
    
    free(matriz);
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
#include <stdio.h>
#include "ponto.h"
#include "vetor_pontos.h"
#include "vetor_arestas.h"

/*  ###IMPORTANTE###
rodar com gcc *.c -o main -lm (usei a biblioteca math.h)*/

int main(){

    /* Teste de criação dos pontos - Clarice */

    tPonto *p1, *p2, *p3;
    char nome1[10], nome2[10], nome3[10];

    scanf("%s %s %s", nome1, nome2, nome3);

    p1 = criaPonto(nome1, 0, 3.0, 7.0);
    p2 = criaPonto(nome2, 1, 10.0, 40.0);
    p3 = criaPonto(nome3, 2, 13.0, 9.0);

    printf("\nDistancia entre p1 e p2: %.2f\n", distanciaEuclidiana(p1, p2));
    printf("Distancia entre p2 e p3: %.2f\n", distanciaEuclidiana(p2, p3));
    printf("Distancia entre p1 e p3: %.2f\n\n", distanciaEuclidiana(p1, p3));

    setIndice(p2, getIndice(p1));

    imprimePonto(p1, NULL);
    imprimePonto(p2, NULL);
    imprimePonto(p3, NULL);

    /* Teste do vetor de pontos e de arestas - Maju */

    tVetorPontos *vetorPontos = criaVetorPontos();
    tVetorArestas *vetorArestas = criaVetorArestas(3);

    adicionaPonto(vetorPontos, p1);
    adicionaPonto(vetorPontos, p2);
    adicionaPonto(vetorPontos, p3);

    geraArestas(vetorPontos, vetorArestas);
    ordenaArestas(vetorArestas);
    imprimeArestas(vetorArestas);

    desalocaVetorPontos(vetorPontos);
    desalocaVetorArestas(vetorArestas);

    return 0;
}
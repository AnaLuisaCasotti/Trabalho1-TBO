#include <stdio.h>

#include "ponto.h"

/*  ###IMPORTANTE###
rodar com gcc *.c -o main -lm (usei a biblioteca math.h)*/

int main(){
    tPonto *p1, *p2;
    char nome1[10], nome2[10];

    scanf("%s %s", nome1, nome2);

    p1 = criaPonto(nome1, 0, 3.0, 7.0);
    p2 = criaPonto(nome2, 1, 10.0, 40.0);

    printf("Distancia entre os dois: %.2f\n\n", distanciaEuclidiana(p1, p2));

    setIndice(p2, getIndice(p1));

    imprimePonto(p1, NULL);
    imprimePonto(p2, NULL);

    desalocaPonto(p1);
    desalocaPonto(p2);

    return 0;
}
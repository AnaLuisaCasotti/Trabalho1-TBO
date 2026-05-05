#include "utils.h"

/*  ###IMPORTANTE###
rodar com gcc *.c -o main -lm (usei a biblioteca math.h)*/

// Linha de comando:
// ./trab1  entrada_teste.txt    3       saida.txt
//  argv[0]    argv[1]         argv[2]    argv[3]

int main(int argc, char *argv[]){

    /*if (argc < 4) {
        printf("Quantidade de argumentos insuficiente\n");
        return 1;
    }*/ // Descomentar quando formos realmente usar a linha de comando completa

    /* Leitura do arquivo de entrada - Ana */

    FILE *entrada = fopen(argv[1], "r");

    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    tVetorPontos *vetorPontos = criaVetorPontos();

    int qtd_pontos = leArquivoEntrada(entrada, vetorPontos); // Função retorna a qtd de pontos lidos no arquivo de entrada

    tVetorArestas *vetorArestas = criaVetorArestas(qtd_pontos);

    geraArestas(vetorPontos, vetorArestas);
    ordenaArestas(vetorArestas);
    imprimeArestas(vetorArestas);

    unionArestas(vetorArestas, vetorPontos);
    imprimeVetorPontos(vetorPontos);

    //excluiAresta(vetorArestas, 0);
    imprimeArestas(vetorArestas);

    desalocaVetorPontos(vetorPontos);
    desalocaVetorArestas(vetorArestas);

    fclose(entrada);
    

    /* Teste de criação dos pontos - Clarice 
    && Teste do vetor de pontos e de arestas - Maju*/
/*
    tPonto *p1, *p2, *p3;
    double coord1[] = {10.8, 9.2, 8.3}, coord2[] = {4.8, 6.6, 9.0}, coord3[] = {9.9, 20.0, 16.0};
    char nome1[10], nome2[10], nome3[10];

    scanf("%s %s %s", nome1, nome2, nome3);

    ///CÁLCULO DO TAMANHO DO VETOR
    int qntCoord = sizeof(coord1) / sizeof(double);

    p1 = criaPonto(nome1, coord1, qntCoord);
    p2 = criaPonto(nome2, coord2, qntCoord);
    p3 = criaPonto(nome3, coord3, qntCoord);

    printf("\nDistancia entre p1 e p2: %.2f\n", distanciaEuclidiana(p1, p2));
    printf("Distancia entre p2 e p3: %.2f\n", distanciaEuclidiana(p2, p3));
    printf("Distancia entre p1 e p3: %.2f\n\n", distanciaEuclidiana(p1, p3));

    setIndice(p2, getIndice(p1));

    imprimePonto(p1, NULL);
    imprimePonto(p2, NULL);
    imprimePonto(p3, NULL);

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
    */

    return 0;
}
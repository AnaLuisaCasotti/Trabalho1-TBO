#include "utils.h"

int main(int argc, char *argv[]){

     if(argc < 4){
        printf("Quantidade de argumentos insuficiente\n");
        return 1;
    } 

    FILE *entrada = fopen(argv[1], "r");
    int n = atoi(argv[2]); // Número de grupos a serem criados

    tVetorPontos *vetorPontos = criaVetorPontos();

    int qtd_pontos = leArquivoEntrada(entrada, vetorPontos); // Função que retorna a qtd de pontos lidos no arquivo de entrada

    tVetorArestas *vetorArestas = criaVetorArestas(qtd_pontos);

    geraArestas(vetorPontos, vetorArestas);
    constroiHeap(vetorArestas); // Vetor transformado em uma Min-Heap usando "constroiHeap(tVetorAresta *vetor)"
    unionArestas(vetorArestas, vetorPontos, n);
    
    FILE *saida = fopen(argv[3], "w");
    
    imprimeGrupos(vetorPontos, n, saida);
    
    desalocaVetorPontos(vetorPontos);
    desalocaVetorArestas(vetorArestas);

    fclose(entrada);
    fclose(saida);

    return 0;
}
#include "utils.h"

// Linha de comando:
// ./trab1  entrada_teste.txt    3       saida.txt
//  argv[0]    argv[1]         argv[2]    argv[3]

int main(int argc, char *argv[]){

    if(argc < 4) {
        printf("Quantidade de argumentos insuficiente\n");
        return 1;
    } // Descomentar quando formos realmente usar a linha de comando completa

    // Leitura do arquivo de entrada - Ana

    FILE *entrada = fopen(argv[1], "r");
    int n = atoi(argv[2]); // Número de grupos a serem criados

    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    tVetorPontos *vetorPontos = criaVetorPontos();

    int qtd_pontos = leArquivoEntrada(entrada, vetorPontos); // Função retorna a qtd de pontos lidos no arquivo de entrada

    tVetorArestas *vetorArestas = criaVetorArestas(qtd_pontos);

    geraArestas(vetorPontos, vetorArestas);
    ordenaArestas(vetorArestas);

    tVetorArestas *novoVetor = unionArestas(vetorArestas, vetorPontos, qtd_pontos);
    removeMaioresArestas(novoVetor, n);
    resetaPontos(vetorPontos);
    clusterizacao(novoVetor, vetorPontos);

    FILE *saida = fopen(argv[3], "w");

    imprimeClusters(vetorPontos, n, saida);
    
    desalocaVetorPontos(vetorPontos);
    desalocaVetorArestas(vetorArestas);
    desalocaVetorArestas(novoVetor);

    fclose(entrada);
    fclose(saida);

    return 0;
}
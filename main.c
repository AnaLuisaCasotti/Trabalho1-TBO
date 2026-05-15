#include "utils.h"

int main(int argc, char *argv[]){

     if(argc < 4){
        printf("Quantidade de argumentos insuficiente\n");
        return 1;
    } 

    FILE *entrada = fopen(argv[1], "r");
    int n = atoi(argv[2]); // Número de grupos a serem criados

    tVetorPontos *vetorPontos = criaVetorPontos();

    clock_t i_leitura = clock();
    int qtd_pontos = leArquivoEntrada(entrada, vetorPontos); // Função que retorna a qtd de pontos lidos no arquivo de entrada
    clock_t f_leitura = clock();
    double t_leitura = ((double)(f_leitura - i_leitura))/ CLOCKS_PER_SEC;
    printf("Tempo de leitura: %f\n", t_leitura);

    tVetorArestas *vetorArestas = criaVetorArestas(qtd_pontos);

    clock_t i_dist = clock();
    geraArestas(vetorPontos, vetorArestas);
    clock_t f_dist = clock();
    double t_dist = ((double)(f_dist - i_dist))/ CLOCKS_PER_SEC;
    printf("Tempo de calculo das distancias: %f\n", t_dist);

    clock_t i_mst = clock();
    constroiHeap(vetorArestas); // Vetor transformado em uma Min-Heap usando "constroiHeap(tVetorAresta *vetor)"
    unionArestas(vetorArestas, vetorPontos, n);
    clock_t f_mst = clock();
    double t_mst = ((double)(f_mst - i_mst))/ CLOCKS_PER_SEC;
    printf("Tempo de ordenação + MST: %f\n", t_mst);
    
    //resetaPontos(vetorPontos);

    FILE *saida = fopen(argv[3], "w");
    
    imprimeGrupos(vetorPontos, n, saida);
    
    desalocaVetorPontos(vetorPontos);
    desalocaVetorArestas(vetorArestas);

    fclose(entrada);
    fclose(saida);

    return 0;
}
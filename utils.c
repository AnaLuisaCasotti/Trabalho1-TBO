#include "utils.h"

int leArquivoEntrada(FILE *entrada, tVetorPontos *vetor_pontos){
    
    char *linha = NULL, *nome_ponto, *token;
    size_t tamanho = 0;
    double *coordenadas = NULL; // Vetor de coordenadas temporário
    int qtd_pontos = 0, qtd_coord;

    while (getline(&linha, &tamanho, entrada) != -1){

        qtd_coord = 0;
        free(coordenadas);
        coordenadas = NULL; // Reinicia o vetor de coordenadas temporário

        nome_ponto = strtok(linha, ","); // Lê o nome do ponto
        printf("Ponto %s", nome_ponto); // teste

        while(1){
            
            token = strtok(NULL, ","); // Lê a próxima coordenada do ponto atual

            if (token == NULL) break; // Linha chegou ao fim

            coordenadas = realloc(coordenadas, (qtd_coord + 1) * sizeof(double)); // Aumenta o tamanho alocado para o vetor
            coordenadas[qtd_coord] = atof(token); // Transforma a string em um double

            qtd_coord++;
        }

        for (int i = 0; i < qtd_coord; i++){
            printf("; %.2f", coordenadas[i]); // teste
        }

        // Passar a função "criaPonto(nome_ponto, coordenadas)" aqui
        tPonto *p = criaPonto(nome_ponto, coordenadas, qtd_coord);
        // Após criado o ponto, inserir no vetor de pontos
        adicionaPonto(vetor_pontos, p);

        qtd_pontos++;
        printf("\n");
    }

    free(coordenadas);
    free(linha);

    printf("qtd pontos = %d\n", qtd_pontos);
    return(qtd_pontos);
}

void escreveArquivoSaida(FILE *saida, tVetorArestas *vetor_arestas);
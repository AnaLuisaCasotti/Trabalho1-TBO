#include "utils.h"

int leArquivoEntrada(FILE *entrada, tVetorPontos *vetor_pontos){
    
    char *linha = NULL, *nome_ponto, *token;
    size_t tamanho = 0;
    double *coordenadas = NULL; // Vetor de coordenadas temporário
    int qtd_pontos = 0, qtd_coord, capacidade;

    while (getline(&linha, &tamanho, entrada) != -1){

        qtd_coord = 0;
        free(coordenadas);
        coordenadas = NULL; // Reinicia o vetor de coordenadas temporário

        capacidade = 2; // Capacidade inicial
        coordenadas = calloc(capacidade, sizeof(double));

        nome_ponto = strtok(linha, ","); // Lê o nome do ponto

        while(1){
            
            token = strtok(NULL, ","); // Lê a próxima coordenada do ponto atual

            if (token == NULL) break; // Linha chegou ao fim

            // Se vetor estiver cheio, dobra a capacidade
            if (qtd_coord == capacidade){
                capacidade *= 2;

                coordenadas = realloc(coordenadas, capacidade * sizeof(double));
            }

            coordenadas[qtd_coord] = atof(token); // Transforma a string em um double

            qtd_coord++;
        }

        tPonto *p = criaPonto(nome_ponto, coordenadas, qtd_coord);
        adicionaPonto(vetor_pontos, p); // Após criado o ponto, ele é inserido no vetor de pontos

        qtd_pontos++;
    }

    free(coordenadas);
    free(linha);
    
    return(qtd_pontos);
}
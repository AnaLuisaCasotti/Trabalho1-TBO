#ifndef UTILS_H
#define UTILS_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

#include "ponto.h"
#include "vetor_pontos.h"
#include "vetor_arestas.h"

/*@param:
    FILE *entrada: arquivo de entrada;
    tVetorPontos *vetor_pontos: vetor de pontos inicializado para ser preenchido
  @return: o número de pontos lidos do arquivo */
int leArquivoEntrada(FILE *entrada, tVetorPontos *vetor_pontos);

#endif
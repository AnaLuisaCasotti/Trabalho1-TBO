#ifndef PONTO_H
#define PONTO_H

typedef struct Ponto tPonto;

/*@param: 
    char *id: com o nome do ponto dado; 
    int indice: com o indice do ponto dentro do vetor;
    double x: localização do x do ponto;
    double y: localização do y do ponto;

@return: uma estrutura tPonto alocada na memória*/
tPonto* criaPonto(char *id, int indice, double x, double y);

/*@param: tPonto *p1, tPonto *p2: o ponteiro para dois pontos
@return: um valor double resultado da distância euclidiana entre p1 e p2*/
double distanciaEuclidiana(tPonto *p1, tPonto *p2);

/*@param: tPonto *p: o ponteiro para o ponto p
@return: um número inteiro que representa seu indice (ou os indices pai/avô dele)*/
int getIndice(tPonto *p);

/*@param: 
    tPonto *p: o ponteiro para o ponto p;
    int novoIndice: o novo índice que deve ser setado no ponto p;*/
void setIndice(tPonto *p, int novoIndice);

/*@param: 
    tPonto *p: o ponteiro para o ponto p;
    FILE *fp: ponteiro para o documento de escrita que já foi aberto*/
void imprimePonto(tPonto *p, FILE *fp);

/*@param: tPonto *p: o ponteiro para o ponto p que será desalocado;*/
void desalocaPonto(tPonto *p);

#endif
#ifndef PONTO_H
#define PONTO_H

typedef struct Ponto tPonto;

/*@param: 
    char *id: com o nome do ponto dado;
    double *coordenadas: vetor de coordenadas do ponto;
    int qntCoord: quantidade de coordenadas de cada ponto;
@return: uma estrutura tPonto alocada na memória (OBS: índice do ponto default é 0)*/
tPonto* criaPonto(char *id, double *coordenadas, int qntCoord);

/*@param: tPonto *p1, tPonto *p2: o ponteiro para dois pontos
@return: um valor double resultado da distância euclidiana entre p1 e p2*/
double distanciaEuclidiana(tPonto *p1, tPonto *p2);

/*@param: tPonto *p: ponteiro para o ponto*/
char *getIdPonto(tPonto *p);

/*@param: tPonto *p: o ponteiro para o ponto p
@return: um número inteiro que representa seu indice atual (ou os indices pai/avô dele)*/
int getIndiceAtual(tPonto *p);

/*@param: tPonto *p: o ponteiro para o ponto p
@return: um número inteiro que representa seu indice original*/
int getIndiceOriginal(tPonto *p);

/*@param: 
    tPonto *p: o ponteiro para o ponto p;
    int novoIndice: o novo índice que deve ser setado no ponto p;*/
void setIndice(tPonto *p, int novoIndice);

/*@param: 
    tPonto *p: o ponteiro para o ponto p;
    int indice: o índice original que deve ser setado no ponto p;*/
void setIndiceOriginal(tPonto *p, int indice);

/*@param: 
    tPonto *p: o ponteiro para o ponto p;
    FILE *fp: ponteiro para o documento de escrita que já foi aberto*/
void imprimePonto(tPonto *p, FILE *fp);

/*@param: tPonto *p: o ponteiro para o ponto p que será desalocado;*/
void desalocaPonto(tPonto *p);

#endif
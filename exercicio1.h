#include <stdio.h>
#include <stdlib.h>

#ifndef EXERCICIO1_H
#define EXERCICIO1_H

//item 1
struct umaEstrutura_st {
    int * vetor;
    int ** matriz; 
};
typedef struct umaEstrutura_st * declarando_pt;
typedef struct umaEstrutura_st   declarando_t;

declarando_pt InicializarVariavel(int x, int y, int l);
void ImprimeMatriz(declarando_pt variavel);
void DestroiEstrutura(declarando_pt variavel);

//item 2
typedef int TipoFuncao(int * x);

// Cria um vetor de ponteiros para funções do tipo 'TipoFuncao'
TipoFuncao *VetorDeFuncoes[3];

void SetCallbackFunc(int indice, TipoFuncao *PonteiroParaUmaFuncao);

int FuncPrimaria(int * x, char * curta, char * longa);

//item 3
typedef char TipoFuncaoChar(char * x);
TipoFuncaoChar *MatrizFuncoes[2][3];

char * FuncaoUm(char * curta, char * longa);
char * FuncaoDois(char * curta, char * longa);
char * FuncaoTres(char * curta, char * longa);
char * FuncaoQuatro(char * curta, char * longa);
char * FuncaoCinco(char * curta, char * longa);
char * FuncaoSeis(char * curta, char * longa);

void SetCallbackFuncDois(int modo, int tipo, TipoFuncaoChar *PonteiroParaUmaFuncao);

#endif
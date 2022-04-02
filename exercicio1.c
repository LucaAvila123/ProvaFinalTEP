#include <stdio.h>
#include <stdlib.h>
#include "exercicio1.h"

//item 1
declarando_pt InicializarVariavel(int x, int y, int l){
    declarando_pt variavel = malloc(sizeof(declarando_t));
    variavel->vetor = (int *) malloc (2 * sizeof(int));
	variavel->vetor[0] = x;
    variavel->vetor[1] = y;

    variavel->matriz = (int **) malloc(sizeof(int *));
    for(int k=0; k<variavel->vetor[0]; k++){
        variavel->matriz[k] = (int *)malloc(variavel->vetor[1]*sizeof(int));
    }
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            variavel->matriz[i][j] = l;
            l++;
        }
    }

    return (variavel);
}

void ImprimeMatriz(declarando_pt variavel){
    for(int i=0; i<variavel->vetor[0]; i++){
        for(int j=0; j<variavel->vetor[1]; j++){
            printf("%d ", variavel->matriz[i][j]);
        }
        printf("\n");
    }
}

void DestroiEstrutura(declarando_pt variavel){
    free(variavel->matriz);
    free(variavel->vetor);
    free(variavel);
}

//item 2
// Cria um vetor de ponteiros para funções do tipo 'TipoFuncao'
TipoFuncao *VetorDeFuncoes[3];

void SetCallbackFunc(int indice, TipoFuncao *PonteiroParaUmaFuncao){
    VetorDeFuncoes[indice] = PonteiroParaUmaFuncao;
}

int FuncPrimaria(int * x, char * curta, char * longa){
    int valor = *x + *curta + *longa;
    return(valor);
}

//item 3
char * FuncaoUm(char * curta, char * longa){
    return(curta);
}
char * FuncaoDois(char * curta, char * longa){
    return(longa);
}
char * FuncaoTres(char * curta, char * longa){
    char *c = *curta + *longa;
    return(c);
}
char * FuncaoQuatro(char * curta, char * longa){
    char *c = *curta - *longa;
    return(c);
}
char * FuncaoCinco(char * curta, char * longa){
    char *c = (*curta) * (*longa);
    return(c);
}
char * FuncaoSeis(char * curta, char * longa){
    char *c = (*curta) / (*longa);
    return(c);
}

void SetCallbackFuncDois(int modo, int tipo, TipoFuncaoChar *PonteiroParaUmaFuncao){
    MatrizFuncoes[modo][tipo] = PonteiroParaUmaFuncao;
}
#include <stdio.h>
#include <stdlib.h>
#include "exercicio1.h"


int main(){
    //item 1
    declarando_pt umaVariavel = InicializarVariavel(3, 4, 1);
    ImprimeMatriz(umaVariavel);
    DestroiEstrutura(umaVariavel);

    //item 2
    SetCallbackFunc(0, FuncPrimaria);
    int retorno;
    int *ptr;
    char *curta;
    char *longa;
    char um = 'a';
    char dois = 'A';
    int a = 99;
    ptr = &a;
    curta = &um;
    longa = &dois;
    retorno = VetorDeFuncoes[0] (ptr);
    retorno = FuncPrimaria(ptr, curta, longa);
    printf("%d\n", retorno);

    //item 3
    return(0);
}
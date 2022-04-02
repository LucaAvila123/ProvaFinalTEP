#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "exercicio3.h"

void ImprimeMatrizStrings(char *** matrizStrings, int linhas, int colunas){
    printf("{");
    for(int i=0; i<linhas; i++){
        ImprimeVetorStrings(matrizStrings[i], colunas);
        if(i < linhas-1) printf(",\n");
    }
    printf("}\n");
}
void ImprimeVetorStrings(char ** vetorStrings, int colunas){
    printf("{");
    for(int i=0; i<colunas; i++){
        printf("“");
        printf("%s", vetorStrings[i]);
        printf("”");
        if(i < colunas-1) printf(",");
    }
    printf("}");
    
}

int CaseSensitive(char * curta, char * longa){
    int lenCurta = sizeof(curta);
    int lenLonga = sizeof(longa);
    int estaContido = 0;
    for(int i=0; i<lenLonga; i++){
        if(curta[0] == longa[i]){
            for(int j=0; i<lenCurta; j++){
                if(!(curta[0] == longa[i+j])){
                    estaContido = 0;
                    break;
                }
                else{
                    estaContido = 1;
                }
            }
        }
        if(estaContido != 0) return(i);
    }
    return(-1);
}

int CaseInsensitive(char * curta, char * longa){
    int lenCurta = sizeof(curta);
    int lenLonga = sizeof(longa);
    int estaContido = 0;
    for(int i=0; i<lenLonga; i++){
        if(toupper(curta[0]) == toupper(longa[i])){
            for(int j=0; i<lenCurta; j++){
                if(!(toupper(curta[0]) == toupper(longa[i+j]))){
                    estaContido = 0;
                    break;
                }
                else{
                    estaContido = 1;
                }
            }
        }
        if(estaContido != 0) return(i);
    }
    return(-1);
}

void EliminaRecursivamente(char *curta, char *longa, int comoFazer){
    int lenLonga = sizeof(longa);
    int lenCurta = sizeof(curta);
    if(comoFazer == 1){
        while(CaseSentitive(curta, longa) != -1){
            for(int i=CaseSensitive(curta, longa); i<lenLonga; i++){
                longa[i] = longa[i + lenCurta];
                if(i == lenLonga - lenCurta){
                    longa[i] = '\0';
                    break;
                }
            }
        }  
    }
    else if(comoFazer == 2){
        while(CaseInsentitive(curta, longa) != -1){
            for(int i=CaseInsensitive(curta, longa); i<lenLonga; i++){
                longa[i] = longa[i + lenCurta];
                if(i == lenLonga - lenCurta){
                    longa[i] = '\0';
                    break;
                }
            }
        }
    }
     
}

void EliminarSimplificadamente(char * curta, char * longa, int comoFazer){
    int lenLonga = sizeof(longa);
    int lenCurta = sizeof(curta);
    if(comoFazer == 1){
        if(CaseSensitive(curta, longa) != -1){
            for(int i=CaseSensitive(curta, longa); i<lenLonga; i++){
                longa[i] = longa[i + lenCurta];
                if(i == lenLonga - lenCurta){
                    longa[i] = '\0';
                    break;
                }
            }
        }
    }
    else if(comoFazer == 2){
        if(CaseInsensitive(curta, longa) != -1){
            for(int i=CaseInsensitive(curta, longa); i<lenLonga; i++){
                longa[i] = longa[i + lenCurta];
                if(i == lenLonga - lenCurta){
                    longa[i] = '\0';
                    break;
                }
            }
        }
    }
}

void SubstituiSimplificadamente(char *curta, char *longa, int comoFazer){
    int lenLonga = sizeof(longa);
    int lenCurta = sizeof(curta);
    if(comoFazer == 1){
        while(CaseSensitive(curta, longa) != -1){
            for(int i=CaseSensitive(curta, longa); i<lenLonga; i++){
                longa[i] = ' ';
                if(i == lenLonga - lenCurta){
                    longa[i] = '\0';
                    break;
                }
            }
        }
    }
    else if(comoFazer == 2){
        while(CaseInsensitive(curta, longa) != -1){
            for(int i=CaseInsensitive(curta, longa); i<lenLonga; i++){
                longa[i] = ' ';
                if(i == lenLonga - lenCurta){
                    longa[i] = '\0';
                    break;
                }
            }
        }
    }   
}
void EscolheOperacao(int operacao, char *** matrizStrings, int comoFazer, int linhas, int colunas, char * curta){
    switch(operacao){
        case 1:
            for(int i=0; i<linhas; i++){
                for(int j=0; j<colunas; j++){
                    SubstituiSimplificadamente(curta, matrizStrings[i][j], comoFazer);
                }
            }
            break;
        case 2:
            for(int i=0; i<linhas; i++){
                for(int j=0; j<colunas; j++){
                    EliminarSimplificadamente(curta, matrizStrings[i][j], comoFazer);
                }
            }
            break;
        case 3:
            for(int i=0; i<linhas; i++){
                for(int j=0; j<colunas; j++){
                    EliminaRecursivamente(curta, matrizStrings[i][j], comoFazer);
                }
            }
            break;
    }
}
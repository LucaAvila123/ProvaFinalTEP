#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "exercicio2.h"

//faz diferença maiúscula e minúscula
int FuncaoI(char * curta, char * longa){
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
//não faz diferença maiúscula e minúscula
int FuncaoII(char * curta, char * longa){
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
//elimina a palavra sem diferenciação de maiúscula e minúscula
//elimina a palavra sem problema com reincidência
void FuncaoIII(char * curta, char * longa){
    int lenLonga = sizeof(longa);
    int lenCurta = sizeof(curta);
    if(FuncaoII(curta, longa) != -1){
        for(int i=FuncaoII(curta, longa); i<lenLonga; i++){
            longa[i] = longa[i + lenCurta];
            if(i == lenLonga - lenCurta){
                longa[i] = '\0';
                break;
            }
        }
    }
}
//elimina a palavra com diferenciação de maiúscula e minúscula
//elimina a palavra sem problema com reincidência
void FuncaoIV(char * curta, char * longa){
    int lenLonga = sizeof(longa);
    int lenCurta = sizeof(curta);
    if(FuncaoI(curta, longa) != -1){
        for(int i=FuncaoI(curta, longa); i<lenLonga; i++){
            longa[i] = longa[i + lenCurta];
            if(i == lenLonga - lenCurta){
                longa[i] = '\0';
                break;
            }
        }
    }
}
//elimina a palavra sem diferenciação de maiúscula e minúscula
//repete o processo no caso de reincidência
void FuncaoV(char * curta, char * longa){
    int lenLonga = sizeof(longa);
    int lenCurta = sizeof(curta);
    while(FuncaoII(curta, longa) != -1){
        for(int i=FuncaoII(curta, longa); i<lenLonga; i++){
            longa[i] = longa[i + lenCurta];
            if(i == lenLonga - lenCurta){
                longa[i] = '\0';
                break;
            }
        }
    }   
}
//elimina a palavra com diferenciação de maiúscula e minúscula
//repete o processo no caso de reincidência
void FuncaoVI(char * curta, char * longa){
    int lenLonga = sizeof(longa);
    int lenCurta = sizeof(curta);
    while(FuncaoI(curta, longa) != -1){
        for(int i=FuncaoI(curta, longa); i<lenLonga; i++){
            longa[i] = longa[i + lenCurta];
            if(i == lenLonga - lenCurta){
                longa[i] = '\0';
                break;
            }
        }
    }   
}
//substitui por espaços
//não faz diferença entre maiúscula e minúscula
//repete o processo no caso de reincidência
void FuncaoVII(char * curta, char * longa){
    int lenLonga = sizeof(longa);
    int lenCurta = sizeof(curta);
    while(FuncaoII(curta, longa) != -1){
        for(int i=FuncaoII(curta, longa); i<lenLonga; i++){
            longa[i] = ' ';
            if(i == lenLonga - lenCurta){
                longa[i] = '\0';
                break;
            }
        }
    }   
}
//substitui por espaços
//faz diferença entre maiúscula e minúscula
//repete o processo no caso de reincidência
void FuncaoVIII(char * curta, char * longa){
    int lenLonga = sizeof(longa);
    int lenCurta = sizeof(curta);
    while(FuncaoI(curta, longa) != -1){
        for(int i=FuncaoI(curta, longa); i<lenLonga; i++){
            longa[i] = ' ';
            if(i == lenLonga - lenCurta){
                longa[i] = '\0';
                break;
            }
        }
    }   
}
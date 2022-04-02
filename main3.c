#include <stdio.h>
#include <stdlib.h>
#include "exercicio3.h"

int main(){
    //a) declarando a matriz de strings
    char *** tentando;
    int linhas, colunas;
    printf("Determine o número de linhas e colunas da matriz de strings\n");
    scanf("%d %d", &linhas, &colunas);
    //alocando a memória para a matriz de strings
    tentando = malloc(linhas * sizeof(char **));
    for(int k=0; k<linhas; k++){
        tentando[k] = malloc(colunas * sizeof(char *));
    }
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            tentando[i][j] = malloc(100 * sizeof(char));
        }
    }
    //b)
    printf("Digite as strings longas\n");
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            for(int k=0; k<100; k++){
                scanf("%c", &tentando[i][j][k]);
                if(!((tentando[i][j][k] >= '0' && 
                        tentando[i][j][k] <= '9') ||
                    (tentando[i][j][k] >= 'a' &&
                        tentando[i][j][k] <= 'z') ||
                    (tentando[i][j][k] >= 'A' &&
                        tentando[i][j][k] <= 'Z') ||
                    (tentando[i][j][k] == ' ')))
                    {
                        tentando[i][j][k] = '\0';
                        break;
                    }
            }
        }
    }
    printf("Matriz Original: ");
    ImprimeMatrizStrings(tentando, linhas, colunas);
    //c)
    int qtdRepeticoes = 0;
    int operacao = 0;
    int comoFazer = 0;
    printf("Quantidade de repetições: ");
    scanf("%d", &qtdRepeticoes);
    printf("%d\n", qtdRepeticoes);
    char curta[20];
    for(int i=0; i<qtdRepeticoes; i++){
        //I.
        printf("String curta: ");
        scanf("%[^\n]%*[\n]", curta);
        printf("%s\n", curta);
        //II.
        printf("Qual operação você deseja fazer?\n");
        printf("1. Substituir a string curta por uma sequência de espaços do mesmo tamanho\n");
        printf("2. eliminar todas as ocorrências da string curta de cada uma das strings longas sem considerar recorrência\n");
        printf("3. eliminar todas as ocorrências da string curta de cada uma das strings longas considerando recorrência\n");
        scanf("%d", &operacao);
        while(operacao < 1 && comoFazer > 3){
            printf("Valor inválido, escolha 1, 2 ou 3");
            scanf("%d", &comoFazer);
        }
        //III.
        printf("Como você quer que seja feita a operação escolhida?\n");
        printf("1. a operação a ser feita deve diferenciar maiúsculas e minúsculas\n");
        printf("2. não deve fazer diferença entre maiúsculas e minúsculas\n");
        scanf("%d", &comoFazer);
        while(comoFazer < 1 && comoFazer > 2){
            printf("Valor inválido, escolha 1 ou 2");
            scanf("%d", &comoFazer);
        }
        EscolheOperacao(operacao, tentando, comoFazer, linhas, colunas, curta);
        printf("Resultado: ");
        ImprimeMatrizStrings(tentando, linhas, colunas);
    }

    free(tentando);
    return(0);
    
}
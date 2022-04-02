#ifndef EXERCICIO3_H
#define EXERCICIO3_H

void EscolheOperacao(int operacao, char *** matrizStrings, int comoFazer, int linhas, int colunas, char * curta);
void ImprimeMatrizStrings(char *** matrizStrings, int linhas, int colunas);
void ImprimeVetorStrings(char ** vetorStrings, int colunas);

void EliminaRecursivamente(char *curta, char *longa, int comoFazer);
void EliminaSimplicadamente(char *curta, char *longa, int comoFazer);
void SubstituiSimplificadamente(char *curta, char *longa, int comoFazer);

int CaseSensitive(char *curta, char *longa);
int CaseInsensitive(char *curta, char *longa);
#endif
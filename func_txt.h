#include <stdio.h>
#include <stdlib.h>


#ifndef FUNC_TXT_H_INCLUDED
#define FUNC_TXT_H_INCLUDED


void createTxtFile(const char* str);
void printTxtFile(FILE *f);
void UniaoTxt(int *v1, int *v2, int *v3, int t1,int t2, int *t3);
void IntersecaoTxt(int *v1, int *v2, int *v3, int t1, int t2, int *tam);
void DiferencaTxt(int *v1, int *v2, int *v3, int t1, int t2, int *tam);
void PreencheArquivo(FILE *f, int n, int v[n]);
void ContaArq(FILE *f,int *n);
void ArqVet(FILE *f, int t, int v[t]);
	


#endif // FUNC_TXT_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#ifndef FUNC_BIN_H_INCLUDED
#define FUNC_BIN_H_INCLUDED


short createBinFile(const char* str);
void printBinFile(FILE *f);
short BBArq(FILE *f, int key);
void BubbleSort(FILE *f);
void UniaoBin(FILE *f1, FILE *f2, FILE *f3);
void IntersecaoBin(FILE *f1, FILE *f2, FILE *f3);
void DiferencaBin(FILE *f1, FILE *f2, FILE *f3);
void randNumArq(FILE *f, int n);

#endif // FUNC_BIN_H_INCLUDED

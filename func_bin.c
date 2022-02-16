// funcoes para manipulacao de arquivos binarios
#include "func_bin.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short createBinFile(const char* str){
	FILE *f = NULL;

	if((f = fopen(str,"wb")) == NULL){
		fputs("Erro na criacao do arquivo!!",stderr);
		system("pause");
		exit(EXIT_FAILURE);
	}
	fclose(f);
	return 1;
	
}

void printBinFile(FILE *f){
	int n;
	while(!feof(f)){
		fread(&n,sizeof(int),1,f);
		if(feof(f)) break;
		printf("%d \n",n);
	}
	return;
}


short BBArq(FILE *f, int key){
	long int ini=0, meio, fim;
	int n;
	fseek(f,0,SEEK_END);
	fim = ftell(f)/sizeof(int);
	while(ini<=fim){
		meio = (ini + fim)/2;
		fseek(f,meio*sizeof(int),0);
		fread(&n,sizeof(int),1,f);
		if(n==key) return 1;
		else if(n<key) ini = meio+1;
		else fim = meio-1;
	}
	rewind(f);
	return 0;
}


void BubbleSort(FILE *f){
	long int i,j;
	int a,b;
	fseek(f,0,SEEK_END);
	long int tam = ftell(f)/sizeof(int);
	long int tam2 = tam;
	rewind(f);
	for(i=0;i<tam;i++){
		rewind(f);
		for(j=0;j<tam2-1;j++){
			fread(&a,sizeof(int),1,f);
			fread(&b,sizeof(int),1,f);
			if(a>b) {
				fseek(f,(int)(-2*sizeof(int)),SEEK_CUR);
				fwrite(&b,sizeof(int),1,f);
				fwrite(&a,sizeof(int),1,f);
			}
			fseek(f,(int)(-sizeof(int)),SEEK_CUR);
		}
		tam2--;
	}
	rewind(f);
	return;
}


void UniaoBin(FILE *f1, FILE *f2, FILE *f3){
	int n1,n2,t1,t2;
	fseek(f1,0,SEEK_END);
	t1 = ftell(f1)/sizeof(int);
	rewind(f1);
	fseek(f2,0,SEEK_END);
	t2 = ftell(f2)/sizeof(int);
	rewind(f2);
	while(!feof(f1) && !feof(f2)){
		fread(&n1,sizeof(int),1,f1);
		if(feof(f1)) break;
		fread(&n2,sizeof(int),1,f2);
		if(feof(f2)) break;
		if(n1==n2){
			fwrite(&n1,sizeof(int),1,f3);
			fwrite(&n2,sizeof(int),1,f3);
		}
		else if(n1<n2){
			fwrite(&n1,sizeof(int),1,f3);
			fseek(f2,-4,SEEK_CUR);
		}
		else{
			fwrite(&n2,sizeof(int),1,f3);
			fseek(f1,-4,SEEK_CUR);
		}
	}
	if(t1<t2){
		while(!feof(f2)){
			fread(&n2,sizeof(int),1,f2);
			if(feof(f2)) break;
			fwrite(&n2,sizeof(int),1,f3);
		}
	}
	else{
		while(!feof(f1)){
			fread(&n1,sizeof(int),1,f1);
			if(feof(f1)) break;
			fwrite(&n1,sizeof(int),1,f3);
		}
	}
	return;	
}


void IntersecaoBin(FILE *f1, FILE *f2, FILE *f3){
	int n1;
	while(!feof(f1)){
		fread(&n1,sizeof(int),1,f1);
		if(feof(f1)) break;
		if(BBArq(f2,n1)) 
			fwrite(&n1,sizeof(int),1,f3);
	}
	return;
}


void DiferencaBin(FILE *f1, FILE *f2, FILE *f3){
	int n1;
	while(!feof(f1)){
		fread(&n1,sizeof(int),1,f1);
		if(feof(f1)) break;
		if(BBArq(f2,n1)); 
		else fwrite(&n1,sizeof(int),1,f3);
		rewind(f2);
	}
	return;
}


void randNumArq(FILE *f, int n){
	int i,a;
	clock_t seed;
	seed = clock();
	srand((unsigned)seed);
	for(i=0; i<n; i++){
		a = rand()%10000;
		fwrite(&a,sizeof(int),1,f);
	}
	return;	
}

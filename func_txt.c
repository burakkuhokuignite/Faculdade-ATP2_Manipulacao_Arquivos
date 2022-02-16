#include "func_txt.h"
#include "func_aux.h"
#include <stdio.h>
#include <time.h>
#define MAX 1000

void createTxtFile(const char* str){
	int *p,i,n;
	FILE *file_ptr;
	file_ptr = NULL;
	
	if((file_ptr = fopen(str,"w")) == NULL){
		fputs("Erro na cria√ß√£o do aquivo!!",stderr);
		exit(EXIT_FAILURE);
	}
	fclose(file_ptr);
}

void printTxtFile(FILE *f){
	int v[MAX],i;
	for(i = 0; !feof(f); ++i){
		fscanf(f,"%d",(v+i));
		if(feof(f)) break;
		printf("%d\n",v[i]);
	}
}


void PreencheArquivo(FILE *f, int n, int v[n]){
	int i;
	for(i=0;i<n;i++){
		fprintf(f,"%d %c",v[i],'\n');
	}
	return;
}


void ContaArq(FILE *f,int *n){
	int k,cont=0;
	while(fscanf(f,"%d",&k)!=EOF) cont++;
	*n = cont;
	rewind(f);
} 


void ArqVet(FILE *f, int t, int v[t]){
	int n,i=0;
	while(fscanf(f,"%d",&n)!=EOF){
		v[i] = n;
		//printf("\n %d \n",v[i]);
		i++;
	}
	return;
}

//
//


void UniaoTxt(int *v1, int *v2, int *v3, int t1,int t2, int *t3){
	int i,j;
	for(i=0;i<t1;i++){   //Coloca o primeiro vetor na uniao
		*(v3+i)=*(v1+i);
	}
	for(j = 0; j < t2; j++, i++){  //Depois, coloca o segundo
		*(v3+i)=*(v2+j);
	}
	*t3 = i;   //Atualiza o tamanho do vetor uniao   
}

void IntersecaoTxt(int *v1, int *v2, int *v3, int t1, int t2, int *tam){
	int i = 0,j = 0,aux,cont=-1;
	*tam = -1;    //Inicializa como -1, pois, se n„o tiver nenhum valor igual nos vetores, o conjunto ser· vazio.
	while(i < t1 && j < t2){
		if(*(v1+i)==*(v2+j)){
			cont++;     //Atualiza o tamanho do vetor interseÁ„o
			*tam = cont;			
			*(v3+*tam)=*(v1+i);
			i++;
			j++;
		}
		else if(*(v1+i)>*(v2+j)) j++;
		else i++;
	}
	cont++;
	*tam = cont;
}

void DiferencaTxt(int *v1, int *v2, int *v3, int t1, int t2, int *tam){
	int i,j, aux,k = 0;
	for(i = 0; i < t1; i++){
		aux = 0;   //Se aux for alterado para 1, significa que o valor esta presente nos dois vetores, logo, ele nao entrara para o vetor Diferenca
		for(j = 0; j < t2; j++){
			if(*(v1+i) == *(v2+j)){
			 aux = 1;
			 j = t2;
			}
		}	
		if(aux == 0){   //Se aux permanecer 0, o valor so esta no primeiro vetor
			*(v3+k) = *(v1+i);
			k++;
		}
	}
	*tam = k;
}

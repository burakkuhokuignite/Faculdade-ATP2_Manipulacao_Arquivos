#include "func_aux.h"

char isNumber(char* var){
    int i = 0 ;
    while(var[i] != '\0' && var[i] >= '0' && var[i] <= '9')i++;
    return var[i]=='\0';
}


void giveRandom(int vet[], int n){
	int i;
	clock_t seed;
	clock();
    srand((unsigned) time(NULL));
    for(i = 0; i < n; i++)
        vet[i] = rand();
}

void ImprimeVetor(int n, int v[n]){
	int i;
	for(i=0;i<n;i++){
		printf("%d \n",v[i]);
	}
	return;
}


void SelectionSort(int T,int V[T]){
	int lim=T-1, i, j,aux;
	for(i=0; i<lim;i++){
		for(j=i+1; j<T; j++){
			if(V[j]<V[i]){
				aux = V[j];
				V[j] = V[i];
				V[i] = aux;
			} 
		}
	}
	return; 
}



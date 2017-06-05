#include <stdio.h>

int main(){

	/*Vetor com 10 posições*/
	int v[10], i, j;
	for(i = 0; i < 10; ++i){
		printf("Digite o valor da posicao %i: ", i+1);
		scanf("%d", &v[i]);
	}
	for(i = 0; i < 10; ++i){
		printf("Valor da posicao %i: %i\n", i+1, v[i]);
	}

	/*Matriz 3x4*/
	int m[3][4];
	for(i = 0; i < 3; i++){
		for(j = 0; j < 4; j++){
			printf("Digite o valor da posicao %i: ", i+1);
			scanf("%d", &m[i][j]);	
		}
	}	

	for(i = 0; i < 3; i++){
		for(j = 0; j < 4; j++){
			printf("%i ", m[i][j]);
		}
		printf("\n");
	}	


	return 0;
}
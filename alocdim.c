#include <stdio.h>
#include <stdlib.h>

int main(){

	int n, i, media = 0;
	printf("Digite a quantidade de elementos: ");
	scanf("%d", &n);

	int *aloc = (int *) malloc(n * sizeof(int));
	for(i = 0; i < n; ++i){
		printf("Digite o valor da posica %d: ", i+1);
		scanf("%d", &aloc[i]);
		media = media + aloc[i];
	}
	printf("Media: %d\n", media/n);


	return 0;
}
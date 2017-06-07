#include <stdio.h>
#include <stdlib.h>

typedef struct Lista lista;

struct Lista{
	int valor;
	struct Lista* prox;
};

lista *aloca();
void busca(lista *l);
void mostra(lista *l);
void insere(lista *lista);
void retira(lista *l);
void insere_pos(lista *l,int posicao);

int tamanho;

int main(){

	lista *l = (lista *) malloc(sizeof(lista));
	int posicao;
	insere(l);
	insere(l);
	insere(l);
	insere(l);
	insere(l);
	insere(l);
	insere(l);
	insere(l);
	insere(l);
	insere(l);
	mostra(l);

	return 0;
}

void retira(lista *l){
	if(l->prox != NULL){
		lista *temp = l->prox;
		lista *anterior = l;
		int valor;

		printf("Digite o valor a ser removido: ");
		scanf("%d", &valor);
		while(temp->prox != NULL && temp->valor != valor){
			temp = temp->prox;
			anterior = anterior->prox;
		}
		if(temp->prox == NULL){
			printf("Valor nao esta na lista!\n");
		}else{
			anterior->prox = temp->prox;
			free(temp);
		}
	}
}

void busca(lista *l){
	if(l->prox != NULL){
		lista *temp = l->prox;
		int valor;
		printf("Digite um valor a procurar: ");
		scanf("%d", &valor);
		while(temp->prox != NULL && valor != temp->valor){
			temp = temp->prox;
		}
		if(temp->prox == NULL){
			printf("Valor não encontrado!\n");
		}else{
			printf("Valor encontrado.\n");
		}
	}
}

void insere(lista *l){
	lista *novo = aloca();

	if(l->prox == NULL){
		l->prox = novo;
	}else{
		lista *temp = l;
		while(temp->prox != NULL){
			temp = temp->prox;
		}
		temp->prox = novo;
	}
	tamanho++;
}

void mostra(lista *l){
	if(l->prox != NULL){
		lista *temp = l->prox;
		while(temp != NULL){
			printf("Valor: %d\n", temp->valor);
			temp = temp->prox;
		}
	}
}

lista *aloca(){
	lista *l = (lista *) malloc(sizeof(lista));
	if(!l){
		printf("Sem espaço!\n");
		exit(1);
	}else{
		printf("Novo elemento: ");
		scanf("%d", &l->valor);
		l->prox = NULL;
		return l;
	}
}
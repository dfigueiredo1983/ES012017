/*
Universidade de Brasília - UnB  
Disciplina: Estrutura de Dados
Aluno: Daniel do Carmo Figueiredo 
Matrícula: 16/0057922
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Agenda{
	char nome[50];
	char email[50];
	char telefone[20];
	struct Agenda *prox;
};
typedef struct Agenda agenda;

agenda *aloca();
int vazia(agenda *);
void insere(agenda *);
void insereOrdenado(agenda *);
void mostra(agenda *);
void destroi(agenda *no);
void ordenado(agenda *no);
void excluir_contato(agenda *no);
void editar(agenda *no);

int tamanho = 0;

int main(){

	agenda *no = (agenda *) malloc(sizeof(agenda));
	int op;

	do{
		printf("Digite alguma das opções:\n");
		printf("1 - Inserir\n");
		printf("2 - Inserir em ordem\n");
		printf("3 - Ordenar\n");
		printf("4 - Mostrar agenda\n");
		printf("5 - Excluir contato\n");
		printf("6 - Editar contato\n");
		printf("7 - Apagar agenda\n");
		printf("8 - Sair\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				insere(no);
			break;
			case 2:
				insereOrdenado(no);
			break;
			case 3:
				ordenado(no);
			break;
			case 4:
				mostra(no);
			break;			
			case 5:
				excluir_contato(no);
			break;
			case 6:
				editar(no);
			break;
			case 7:
				destroi(no);
			break;
			case 8:
				free(no);
				exit(0);
			break;
			default:
				printf("Digite umas opcao valida: ");
				scanf("%d", &op);
		}
	}while(1);
	return 0;
}

void excluir_contato(agenda *no){
	agenda *temp = no->prox;
	agenda *anterior = no;
	int indice, i = 0;

	mostra(no);
	printf("Digite o contato a excluir:");
	scanf("%d", &indice);
	if(indice >= 0 && indice < tamanho){
		while(indice != i){
			anterior = anterior->prox;
			temp = temp->prox;
			i++;
		}
		anterior->prox = temp->prox;
		free(temp);
	}else{
		printf("Indice inexistente!\n");
	}
	mostra(no);
}

void editar(agenda *no){
	agenda *temp = no->prox;
	int indice, i = 0;

	mostra(no);
	printf("Digite o contato a editar:");
	scanf("%d", &indice);
	if(indice >= 0 && indice < tamanho){
		while(indice != i){
			temp = temp->prox;
			i++;
		}
		printf("Nome: ");
		scanf("%s", temp->nome);
		printf("Email: ");
		scanf("%s", temp->email);
		printf("Telefone: ");
		scanf("%s", temp->telefone);
		ordenado(no);
	}else{
		printf("Indice inexistente!\n");
	}
}

void ordenado(agenda *no){
	agenda *o = (agenda*) malloc(sizeof(agenda));
	agenda *temp = o;

	while(no->prox != NULL){
		agenda *novo = no->prox;
		no->prox = novo->prox;
		novo->prox = NULL;
	
		while(temp->prox != NULL && (novo->nome[0] > temp->prox->nome[0])){
			temp = temp->prox;
		}
		if(temp->prox == NULL){
			temp->prox = novo;
		}else{
			novo->prox = temp->prox;
			temp->prox = novo;
		}
	}
	no->prox = o->prox;
	mostra(no);
}

void destroi(agenda *no){
	if(vazia(no)){
		printf("Agenda vazia!\n");
	}else{
		agenda *temp = no->prox;
		while(temp != NULL){
			no->prox = temp->prox;
			free(temp);
			temp = no->prox;
		}
	}
	tamanho = 0;
}

void insereOrdenado(agenda *no){
	agenda *novo = aloca();
	if(vazia(no)){
		no->prox = novo;
	}else{
		agenda *temp = no;
		while(temp->prox != NULL && (novo->nome[0] > temp->prox->nome[0])){
			temp = temp->prox;
		}
		if(temp->prox == NULL){
			temp->prox = novo;
		}else{
			novo->prox = temp->prox;
			temp->prox = novo;
		}
	}
	tamanho++;
}

void insere(agenda *no){
	agenda *novo = aloca();
	if(vazia(no)){
		no->prox = novo;
	}else{
		agenda *temp = no;
		while(temp->prox != NULL){
			temp = temp->prox;
		}
		temp->prox = novo;
	}
	tamanho++;
}

int vazia(agenda *no){
	if(no->prox == NULL){
		return 1;
	}else{
		return 0;
	}
}

void mostra(agenda *no){
	if(vazia(no)){
		printf("Agenda vazia!\n");
	}else{
		agenda *temp = no;
		int i = 0;
		while(temp->prox != NULL){
			temp = temp->prox;
			printf("Contato: %d\n", i);
			printf("Nome: %s\n", temp->nome);
			printf("E-mail: %s\n", temp->email);
			printf("Telefone: %s\n", temp->telefone);
			i++;
		}
	}
}

agenda *aloca(){
	agenda *novo = (agenda *) malloc(sizeof(agenda));
	if(!novo){
		printf("Sem espaço!\n");
		return;
	}
	printf("Digite o nome: ");
	scanf("%s", novo->nome);
	printf("Digite o e-mail: ");
	scanf("%s", novo->email);
	printf("Digite o telefone: ");
	scanf("%s", novo->telefone);
	return novo;
}
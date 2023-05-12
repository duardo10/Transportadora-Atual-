#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "endereco.h"

struct endereco{
	int id, numero;
	char dono[100], rua[50], bairro[50], logradouro[50], cidade[50], estado[3];
	struct endereco *prox;
};

Endereco *preencherEndereco(int id){
	Endereco *end = (Endereco*) malloc(sizeof(Endereco));
	
	printf("Estado: ");
	scanf("%s", end->estado);
	getchar();
	printf("Cidade: ");
	scanf("%[^\n]s", end->cidade);
	getchar();
	printf("Logradouro: ");
	scanf("%[^\n]s", end->logradouro);
	getchar();
	printf("Bairro: ");
	scanf("%[^\n]s", end->bairro);
	getchar();
	printf("Rua: ");
	scanf("%[^\n]s", end->rua);
	printf("Numero: ");
	scanf("%d", &end->numero);
	getchar();
	printf("Dono da residencia: ");
	scanf("%[^\n]s", end->dono);
	end->id = id;
	end->prox = NULL;
}

Endereco *criarEnderecos(){
	return NULL;
}

Endereco *inserirEndereco(Endereco *lista, Endereco *end){
    Endereco *aux;
    
	if(!estaVaziaEnderecos(lista)){
		for(aux = lista; aux->prox; aux = aux->prox);
		
		aux->prox = end;
		return lista;
	}
	
	return end;
}

Endereco *removerEndereco(Endereco *lista, int id){
	Endereco *aux, *remover;
	
	if(!estaVaziaEnderecos(lista) && id >= 0){
		if(lista->id == id){
			remover = lista;
			lista = remover->prox;
			free(remover);
		}
		
		for(aux = lista; aux->prox && aux->prox->id != id; aux = aux->prox);
		
		if(aux->prox && aux->prox->id == id){
			remover = aux->prox;
			aux->prox = remover->prox;
			free(remover);
		}
	}
	
	return lista;
}

Endereco *buscarEnderecos(Endereco *lista, char *dono, int opc){
	Endereco *aux;
	
	if(!estaVaziaEnderecos(lista)){
		for(aux = lista; aux; aux = aux->prox){
			if(!strcmp(aux->dono, dono)){
				if(opc)
					mostrarEndereco(aux, 0);
				
				return aux;
			}
		}
	}
	
	return NULL;
}

Endereco *liberarListaEnderecos(Endereco *lista){
	
}

int estaVaziaEnderecos(Endereco *lista){
	if(lista)
		return 0;
	else
		return 1;
}

int compararEnderecos(Endereco *A, Endereco *B){
	if(!strcmp(A->estado, B->estado) && !strcmp(A->cidade, B->cidade) && !strcmp(A->bairro, B->bairro))
		return 1;
}

void cabecalhoEndereco(int tipo){
	if(tipo)
		printf("%-7s", "");
	
	printf("%-5s%-12s%-7s%-20s%-16s%-12s%-12s%-7s\n", "ID", "DONO", "NUMERO", "RUA", "BAIRRO", "LOGRADOURO", "CIDADE", "ESTADO");
}

void mostrarEndereco(Endereco *end, int tipo){
	if(tipo == 1)
		printf("%-7s", "De: ");
	else if(tipo == 2)
		printf("%-7s", "Para: ");
	
	printf("%-5d%-12s%-7d%-20s%-16s%-12s%-12s%-7s\n", end->id, end->dono, end->numero, end->rua, end->bairro, end->logradouro, end->cidade, end->estado);
}

void mostrarListaEnderecos(Endereco *lista){  
	Endereco *aux;
	
	for(aux = lista; aux; aux = aux->prox)
		mostrarEndereco(aux, 0);
	
	printf("\n");
}


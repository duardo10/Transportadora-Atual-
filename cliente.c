#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "endereco.h"

struct cliente{
	int id;
	char nome[50], sobrenome[50], cpf[15], telefone[12], email[50];
	Endereco *endereco;
    struct cliente *prox;
};

Cliente *criarListaCliente(){
	return NULL;
}

void preencherCliente(Cliente *c){
	printf("Cadastro de um cliente:\n");
    printf("Nome: ");
    scanf("%s %s", c->nome, c->sobrenome);
    printf("CPF: ");
    scanf("%s", c->cpf);
    printf("Telefone: ");
    scanf("%s", c->telefone);
    printf("E-mail: ");
    scanf("%s", c->email);
    c->id = rand() % 1000;
    c->endereco = preencherEndereco(c->id);
    c->prox = NULL;
}

Cliente *inserirCliente(Cliente *clientes, Endereco **listaEnderecos){
    Cliente *aux, *novo = (Cliente*) malloc(sizeof(Cliente));

	preencherCliente(novo);
	*listaEnderecos = inserirEndereco(*listaEnderecos, novo->endereco);
	if(!estaVaziaClientes(clientes)){
		for(aux = clientes; aux->prox; aux = aux->prox);
		
		aux->prox = novo;
		return clientes;
	}
	
	return novo;
}

Cliente *removerCliente(Cliente *clientes, int id, Endereco **listaEnderecos){
	Cliente *aux, *remover;
	
	if(!estaVaziaClientes(clientes) && id >= 0){
		if(clientes->id == id){
			remover = clientes;
			clientes = remover->prox;
			free(remover);
			*listaEnderecos = removerEndereco(*listaEnderecos, id);
			return clientes;
		}
		
		for(aux = clientes; aux->prox && aux->prox->id != id; aux = aux->prox);
		
		if(aux->prox && aux->prox->id == id){
			remover = aux->prox;
			aux->prox = remover->prox;
			free(remover);
			*listaEnderecos = removerEndereco(*listaEnderecos, id);
		}
	}
	
	return clientes;
}

int buscarCliente(Cliente *clientes, char *nome, int opc){
	Cliente *aux;
	
	if(!estaVaziaClientes(clientes)){
		for(aux = clientes; aux; aux = aux->prox){
			if(!strcmp(aux->nome, nome)){
				if(opc){
					printf("\n\t");
					cabecalhoCliente();
					printf("\t");
					mostrarCliente(*aux);
					printf("\n");
				}
					
				return aux->id;
			}
		}
	}
	
	return -1;
}

Cliente *liberarListaClientes(Cliente *clientes){
    Cliente *aux;
    
    for(aux = clientes; aux; aux = aux->prox)
		free(aux);
	
	return NULL;
}

void cabecalhoCliente(){
	printf("%-5s%-12s%-16s%-13s%-25s\n", "ID", "NOME", "CPF", "FONE", "EMAIL");
}

void mostrarCliente(Cliente c){
	printf("%-5d%-12s%-16s%-13s%-25s\n", c.id, c.nome, c.cpf, c.telefone, c.email);
}

void mostrarListaClientes(Cliente *clientes){
    Cliente *aux;
    
	cabecalhoCliente();
	
	for(aux = clientes; aux; aux = aux->prox)
		mostrarCliente(*aux);
	
	printf("\n");
}

int estaVaziaClientes(Cliente *clientes){
	if(clientes)
		return 0;
	
	return 1;
}

int gerenciadorClientes(Cliente **clientes, Endereco **listaEnderecos){
    char nome[50];
    int opc, id;
    
    printf("[Menu Clientes]\n\n\n\n");
    opcoesCliente();
	scanf("%d", &opc);
	system("cls");
	
	while(opc){
		switch(opc){
			case 1:
				if(!estaVaziaClientes(*clientes)){
					mostrarListaClientes(*clientes);
					system("pause");
					system("cls");
					printf("[Menu Clientes]\n\n\n\n");
				} else
					printf("[Menu Clientes]\n\nLista Vazia.\n\n");
					
				break;
			case 2:
				*clientes = inserirCliente(*clientes, listaEnderecos);
				system("cls");
				printf("[Menu Clientes]\n\nCliente Cadastrado.\n\n");
				break;
			case 3:
				if(!estaVaziaClientes(*clientes)){
					do{
						mostrarListaClientes(*clientes);
						printf("Nome (0 - Sair): ");
						scanf("%s", nome);
						id = buscarCliente(*clientes, nome, 0);
						system("cls");
					} while(id == -1 && nome[0] != 0);
					
					if(id != -1){
						*clientes = removerCliente(*clientes, id, listaEnderecos);
						printf("[Menu Clientes]\n\nCliente Removido.\n\n");
					}
				} else
					printf("[Menu Clientes]\n\nLista Vazia.\n\n");
				
				break;
			case 4:
				if(!estaVaziaClientes(*clientes)){
					printf("Nome: ");
					scanf("%s", nome);
					
					if(buscarCliente(*clientes, nome, 1) == -1){
						system("cls");
						printf("[Menu Clientes]\n\nNao Encontrado.\n\n");
					} else {
						system("pause");
						system("cls");
						printf("[Menu Clientes]\n\n\n\n");
					}
				} else
					printf("[Menu Clientes]\n\nLista Vazia.\n\n");
				
				break;
			case 5:
				if(!estaVaziaClientes(*clientes)){
					*clientes = liberarListaClientes(*clientes);
					system("cls");
					printf("[Menu Clientes]\n\nLista Esvaziada.\n\n");
				} else
					printf("[Menu Clientes]\n\nLista Vazia.\n\n");
				
				break;
			default:
				printf("[Menu Clientes]\n\nOpcao nao disponivel.\n\n");
		}
		
		opcoesCliente();
		scanf("%d", &opc);
		system("cls");
	}
    
    return 0;
}

void opcoesCliente(){
	printf("1 - Exibir lista de Clientes\n"
		   "2 - Cadastrar Cliente\n"
		   "3 - Remover Cliente\n"
		   "4 - Buscar Cliente\n"
		   "5 - Limpar lista de Clientes\n"
		   "0 - Sair\n\n");
}


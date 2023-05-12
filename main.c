#include <stdio.h>
#include <stdlib.h>

#include "pontuacao.h"
#include "endereco.h"
#include "cliente.h"
#include "rota.h"

void opcoesPrincipal();

int main(){
	Pontuacao *score = criarEscore();
	Endereco *listaEnderecos = criarEnderecos();
	Cliente *listaClientes = criarListaCliente();
	Rota *filaEntregas = criarRotas(), *pilhaProcessamento = criarRotas(), *filaDevolucoes = criarRotas();
	int opc;
    
    printf("[Menu Principal]\n\n\n\n");
    opcoesPrincipal();
	scanf("%d", &opc);
	
	if(opc)
		system("cls");
	
	while(opc){
		switch(opc){
			case 1:
				gerenciadorClientes(&listaClientes, &listaEnderecos);
				printf("[Menu Principal]\n\n\n\n");
				break;
			case 2:
				gerenciadorRotas(&score, &filaEntregas, &pilhaProcessamento, &filaDevolucoes, &listaEnderecos);
				printf("[Menu Principal]\n\n\n\n");
				break;
			case 3:
				imprimirEscore(&score);
				system("pause");
				system("cls");
				printf("[Menu Principal]\n\n\n\n");
				break;
			default:
				printf("[Menu Principal]\n\nOpcao nao disponivel.\n\n");
		}
		
		opcoesPrincipal();
		scanf("%d", &opc);
		
		if(opc)
			system("cls");
	}
    
    return 0;
}

void opcoesPrincipal(){
	printf("1 - Gerenciar Clientes\n"
		   "2 - Gerenciar Rotas de Entrega\n"
		   "3 - Pontuacao\n"
		   "0 - Sair\n\n");
}


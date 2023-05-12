#ifndef CLIENTES_H_INCLUDED_
#define CLIENTES_H_INCLUDED_

typedef struct cliente Cliente; // 1 - Lista Simples

#include "endereco.h"

Cliente *criarListaCliente();
void preencherCliente(Cliente *c);
Cliente *inserirCliente(Cliente *clientes, Endereco **listaEnderecos);
Cliente *removerCliente(Cliente *clientes, int id, Endereco **listaEnderecos);
int buscarCliente(Cliente *clientes, char *nome, int opc);
Cliente *liberarListaClientes(Cliente *clientes);

void cabecalhoCliente();
void mostrarCliente(Cliente c);
void mostrarListaClientes(Cliente *clientes);
int estaVaziaClientes(Cliente *clientes);
void opcoesCliente();
int gerenciadorClientes(Cliente **clientes, Endereco **listaEnderecos);

#endif


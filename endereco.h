#ifndef ENDERECO_H_INCLUDED_
#define ENDERECO_H_INCLUDED_

typedef struct endereco Endereco;

Endereco *criarEnderecos();
Endereco *preencherEndereco(int id);
Endereco *inserirEndereco(Endereco *lista, Endereco *end);
Endereco *removerEndereco(Endereco *lista, int id);
Endereco *buscarEnderecos(Endereco *lista, char *dono, int opc);
Endereco *liberarListaEnderecos(Endereco *lista);

void cabecalhoEndereco();
void mostrarEndereco(Endereco *end, int tipo);
void mostrarListaEnderecos(Endereco *lista);
int estaVaziaEnderecos(Endereco *lista);
int compararEnderecos(Endereco *A, Endereco *B);

#endif


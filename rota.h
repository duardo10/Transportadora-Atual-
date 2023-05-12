#ifndef ROTAS_H_INCLUDED_
#define ROTAS_H_INCLUDED_

typedef struct rota Rota; // 2 - Fila

#include "endereco.h"

Rota *criarRotas();
Rota *inserirRota(Rota *rotas, Endereco *remetente, Endereco *destinatario, int prioridade, Rota *aux_fila);
Rota *inserirPilhaRota(Rota *pilha, Rota *aux);
Rota *removerRota(Rota *rotas, Rota *aux);
Rota *removerPilhaRota(Rota *pilha, Rota *aux, int opc, int *entrega_feita);
int estaVaziaRotas(Rota *rotas);

void mostrarRota(Rota r);
void mostrarRotas(Rota *rotas);
//void gerenciadorRotas(Rota **filaEntregas, Rota **pilhaProcessamento, Rota **filaDevolucoes, Endereco **listaEnderecos, Endereco **pilhaEnderecos, Endereco **filaEnderecos);
void gerenciadorRotas(Pontuacao **score, Rota **filaEntregas, Rota **pilhaProcessamento, Rota **filaDevolucoes, Endereco **listaEnderecos);
void opcoesRotas();

#endif


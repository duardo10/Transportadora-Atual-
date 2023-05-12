#ifndef PONTUACAO_H_INCLUDED
#define PONTUACAO_H_INCLUDED

typedef struct pontuacao Pontuacao;

Pontuacao *criarEscore();
void alterarEscore(Pontuacao **score, float pontos, int devolveu);
void imprimirEscore(Pontuacao **score);

#endif

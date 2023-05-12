#include <stdio.h>
#include <stdlib.h>

#include "pontuacao.h"

struct pontuacao{
	int entregas, devolvidas;
	float pontos, media;
};

Pontuacao *criarEscore(){
	Pontuacao *score = (Pontuacao*) calloc(1, sizeof(Pontuacao));
	
	return score;
}

void alterarEscore(Pontuacao **score, float pontos, int devolveu){
	(*score)->pontos += pontos;
	(*score)->entregas++;
	
	if(devolveu)
		(*score)->devolvidas++;

	(*score)->media = (*score)->pontos / ((*score)->entregas);
}

void imprimirEscore(Pontuacao **score){
	printf("Pontuacao:\n\n\tEntregas: %d\n\tDevolvidas: %d\n\tPontos: %.2f\n\tMedia: %.2f\n\n", (*score)->entregas, (*score)->devolvidas, (*score)->pontos, (*score)->media);
}


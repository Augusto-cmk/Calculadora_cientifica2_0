//
// Created by pedro on 26/07/2020.
//

#ifndef CALCULADORA_CIENTIFICA2_0_TAD_FILA_DE_OPERACOES_H
#define CALCULADORA_CIENTIFICA2_0_TAD_FILA_DE_OPERACOES_H

#include "TAD_fila_de_resultados.h"
typedef struct Celula2* Ponteiro_da_fila_de_operacoes;

typedef struct Celula2 {
    struct Celula2 *prox;
    char operacao;
    int Posicao;
}Tcelula2;

typedef struct{
    Ponteiro_da_fila_de_operacoes initial;
    Ponteiro_da_fila_de_operacoes end;
    int Tamanho;
}Fila_de_operacoes;

void Inicia_fila_de_operacoes(Fila_de_operacoes *fila);
void InsereOperacao(Fila_de_operacoes *fila,char operacao,int Posicao);
#endif //CALCULADORA_CIENTIFICA2_0_TAD_FILA_DE_OPERACOES_H

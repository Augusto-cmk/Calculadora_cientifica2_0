//
// Created by pedro on 26/07/2020.
//

#ifndef CALCULADORA_CIENTIFICA2_0_FILA_DE_OPERACOES_ENTRE_FILAS_H
#define CALCULADORA_CIENTIFICA2_0_FILA_DE_OPERACOES_ENTRE_FILAS_H
#include <stdio.h>
#include <stdlib.h>
typedef struct Celula_da_fila_de_operacoes_entre_filas* Ponteiro_da_fila_de_operacoes_entre_filas;

typedef struct Celula_da_fila_de_operacoes_entre_filas {
    struct Celula_da_fila_de_operacoes_entre_filas *prox;
    char Operacao;
}Tcelula_de_operacoes_entre_filas;

typedef struct{
    Ponteiro_da_fila_de_operacoes_entre_filas initial;
    Ponteiro_da_fila_de_operacoes_entre_filas end;
    int Tamanho;
}Fila_de_operacoes_entre_filas;

void Inicia_fila_de_operacoes_entre_filas(Fila_de_operacoes_entre_filas *fila);
void InsereOperacao_entre_filas(Fila_de_operacoes_entre_filas *fila,char Operacao);
#endif //CALCULADORA_CIENTIFICA2_0_FILA_DE_OPERACOES_ENTRE_FILAS_H

//
// Created by pedro on 26/07/2020.
//

#ifndef CALCULADORA_CIENTIFICA2_0_TAD_FILA_DE_EXPOENTES_H
#define CALCULADORA_CIENTIFICA2_0_TAD_FILA_DE_EXPOENTES_H
#include "TAD_fila_de_resultados.h"
typedef struct celula3* Ponteiro_da_fila_de_expoentes;

typedef struct celula3 {
    struct celula3 *prox;
    double expoente;
    int Posicao;
}Tcel3;

typedef struct{
    Ponteiro_da_fila_de_expoentes initial;
    Ponteiro_da_fila_de_expoentes end;
    int Tamanho;
}Fila_de_expoentes;

void Inicia_fila_de_expoentes(Fila_de_expoentes *fila);
void InsereExpoente(Fila_de_expoentes *fila,double expoente,int Posicao);
#endif //CALCULADORA_CIENTIFICA2_0_TAD_FILA_DE_EXPOENTES_H

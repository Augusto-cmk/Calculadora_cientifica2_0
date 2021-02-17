//
// Created by pedro on 26/07/2020.
//

#ifndef CALCULADORA_CIENTIFICA2_0_TAD_FILA_DE_LETRAS_H
#define CALCULADORA_CIENTIFICA2_0_TAD_FILA_DE_LETRAS_H
#include "TAD_fila_de_resultados.h"
typedef struct celula2* Poteiro_da_fila_de_letras;

typedef struct celula2 {
    struct celula2 *prox;
    char letra;
    int Posicao;
}Tcel;

typedef struct{
    Poteiro_da_fila_de_letras initial;
    Poteiro_da_fila_de_letras end;
    int Tamanho;
}Fila_de_letras;

void Inicia_fila_de_letras(Fila_de_letras *fila);
void InsereLetra(Fila_de_letras *fila,char letra,int Posicao);
#endif //CALCULADORA_CIENTIFICA2_0_TAD_FILA_DE_LETRAS_H

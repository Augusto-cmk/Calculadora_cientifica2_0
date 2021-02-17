//
// Created by pedro on 26/07/2020.
//

#ifndef CALCULADORA_CIENTIFICA2_0_TAD_FILA_DE_RESULTADOS_H
#define CALCULADORA_CIENTIFICA2_0_TAD_FILA_DE_RESULTADOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Celula1* Ponteiro_da_fila_de_resultados;

typedef struct Celula1{
    struct Celula1 *prox;
    double Resultado;
}Tcelula1;

typedef struct{
    Ponteiro_da_fila_de_resultados Start;
    Ponteiro_da_fila_de_resultados End;
    int Tamanho;
}Fila_de_resultados;

void Start(Fila_de_resultados *fila);
void InsereResultado(Fila_de_resultados *fila,double Resultado);
void Remove(Fila_de_resultados *fila,double Valor,int Posicao);
void Print(Fila_de_resultados *fila);
#endif //CALCULADORA_CIENTIFICA2_0_TAD_FILA_DE_RESULTADOS_H

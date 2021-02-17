//
// Created by pedro on 26/07/2020.
//

#ifndef CALCULADORA_CIENTIFICA2_0_FILA_PRINCIPAL_DE_INTEIROS_H
#define CALCULADORA_CIENTIFICA2_0_FILA_PRINCIPAL_DE_INTEIROS_H
#include <stdlib.h>
#include <stdio.h>
typedef struct celula_da_fila_principal_de_inteiros* Poteiro_da_fila_princial_de_inteiros;

typedef struct celula_da_fila_principal_de_inteiros {
    struct celula_da_fila_principal_de_inteiros *prox;
    double Inteiro;
    int Posicao;
}Tcelula_da_fila_principal;

typedef struct{
    Poteiro_da_fila_princial_de_inteiros initial;
    Poteiro_da_fila_princial_de_inteiros end;
}Fila_pricipal_de_inteiros;

void Inicia_fila_principal_de_inteiros(Fila_pricipal_de_inteiros *fila);
void InsereInteiros(Fila_pricipal_de_inteiros *fila,double Inteiro,int Posicao);
#endif //CALCULADORA_CIENTIFICA2_0_FILA_PRINCIPAL_DE_INTEIROS_H

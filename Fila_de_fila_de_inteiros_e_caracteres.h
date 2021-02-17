//
// Created by pedro on 26/07/2020.
//

#ifndef CALCULADORA_CIENTIFICA2_0_FILA_DE_FILA_DE_INTEIROS_E_CARACTERES_H
#define CALCULADORA_CIENTIFICA2_0_FILA_DE_FILA_DE_INTEIROS_E_CARACTERES_H
#include <stdlib.h>
#include <stdio.h>
#include "Fila_principal_de_inteiros.h"
#include "Fila_principal_de_caracteres.h"
typedef struct celula_da_fila_de_filas* Poteiro_da_fila_de_filas;

typedef struct celula_da_fila_de_filas {
    struct celula_da_fila_de_filas *prox;
    Fila_pricipal_de_inteiros Fila_de_inteiros;
    Fila_pricipal_de_caracteres Fila_de_caracteres;
}Tcelula_da_fila_de_filas;

typedef struct{
    Poteiro_da_fila_de_filas initial;
    Poteiro_da_fila_de_filas end;
    int Tamanho;
}Fila_de_filas;

void Inicia_fila_de_filas(Fila_de_filas *fila);
void InsereFila(Fila_de_filas *fila,Fila_pricipal_de_inteiros *Fila_de_inteiros,Fila_pricipal_de_caracteres *Fila_de_caracteres);
#endif //CALCULADORA_CIENTIFICA2_0_FILA_DE_FILA_DE_INTEIROS_E_CARACTERES_H

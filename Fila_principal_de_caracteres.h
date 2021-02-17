//
// Created by pedro on 26/07/2020.
//

#ifndef CALCULADORA_CIENTIFICA2_0_FILA_PRINCIPAL_DE_CARACTERES_H
#define CALCULADORA_CIENTIFICA2_0_FILA_PRINCIPAL_DE_CARACTERES_H
#include <stdio.h>
#include <stdlib.h>
typedef struct celula_da_fila_principal_de_caracteres* Poteiro_da_fila_princial_de_caracteres;

typedef struct celula_da_fila_principal_de_caracteres {
    struct celula_da_fila_principal_de_caracteres *prox;
    char Caractere;
    int Posicao;
}Tcelula_da_fila_principal2;

typedef struct{
    Poteiro_da_fila_princial_de_caracteres initial;
    Poteiro_da_fila_princial_de_caracteres end;
}Fila_pricipal_de_caracteres;

void Inicia_fila_principal_de_caracteres(Fila_pricipal_de_caracteres *fila);
void InsereCaractere(Fila_pricipal_de_caracteres *fila,char Caracteres,int Posicao);
#endif //CALCULADORA_CIENTIFICA2_0_FILA_PRINCIPAL_DE_CARACTERES_H

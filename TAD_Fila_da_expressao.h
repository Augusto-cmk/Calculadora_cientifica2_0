//
// Created by pedro on 26/07/2020.
//

#ifndef CALCULADORA_CIENTIFICA2_0_TAD_FILA_DA_EXPRESSAO_H
#define CALCULADORA_CIENTIFICA2_0_TAD_FILA_DA_EXPRESSAO_H
#include "TAD_fila_de_resultados.h"
#include "TAD_fila_de_letras.h"
#include "TAD_fila_de_expoentes.h"
#include "TAD_fila_de_operacoes.h"
#include "Fila_de_fila_de_inteiros_e_caracteres.h"
#include "Fila_de_operacoes_entre_filas.h"
typedef struct Celula* Ponteiro_da_fila_de_valores;

typedef struct Celula {
    struct Celula *prox;
    double Valor;
    int Posicao;
}Tcelula;

typedef struct{
    Ponteiro_da_fila_de_valores initial;
    Ponteiro_da_fila_de_valores end;
    int Tamanho;
    Fila_de_letras Letter;
    Fila_de_expoentes Expoentes;
    Fila_de_operacoes Operacao;
    Fila_de_filas Filas;
    Fila_pricipal_de_inteiros Fila_de_inteiros;
    Fila_pricipal_de_caracteres Fila_de_caracteres;
    Fila_de_operacoes_entre_filas Operacoes_entre_filas;
}Fila_de_valores;

void Inicia(Fila_de_valores *fila);
void InsereValor(Fila_de_valores *fila,double Valor,int Posicao);
Fila_de_resultados Resultado(Fila_de_resultados *fila_de_resultados,Fila_de_operacoes *Operacoes,int Tamanho_dos_valores);

#endif //CALCULADORA_CIENTIFICA2_0_TAD_FILA_DA_EXPRESSAO_H

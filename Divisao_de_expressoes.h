//
// Created by pedro on 26/07/2020.
//

#ifndef CALCULADORA_CIENTIFICA2_0_DIVISAO_DE_EXPRESSOES_H
#define CALCULADORA_CIENTIFICA2_0_DIVISAO_DE_EXPRESSOES_H
#include "TAD_calculadora.h"
#include "Interface.h"
#include <string.h>
typedef struct{
    Fila_de_expoentes Expoentes;
    Fila_de_valores Valores;
    Fila_de_operacoes Operacoes;
    Fila_de_letras Letras;
}Estrutura_expressao;

double Analise_da_divisao(Estrutura_expressao *Exp1,Estrutura_expressao *Exp2,Limite *X);
int Determina_fatores(int Dividendo,int Divisor);
int Compara(Fila_de_resultados *Fatores_numerador,Fila_de_resultados *Fatores_denominador,int flag_is_negative);
int Verifica_dizima(int valor);
#endif //CALCULADORA_CIENTIFICA2_0_DIVISAO_DE_EXPRESSOES_H

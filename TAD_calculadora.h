//
// Created by pedro on 26/07/2020.
//

#ifndef CALCULADORA_CIENTIFICA2_0_TAD_CALCULADORA_H
#define CALCULADORA_CIENTIFICA2_0_TAD_CALCULADORA_H
#include "TAD_Fila_da_expressao.h"
#include "TAD_fila_de_resultados.h"
#include <math.h>
typedef struct{
    Fila_de_valores Fila_da_Expressao;
}Expressao;

typedef struct{
    Expressao exp;
    double Tendencia;
    double Direita,esquerda;
    Fila_de_resultados Resultados;
}Limite;

typedef struct{
    Expressao exp;
}Derivada;

typedef struct{
    Expressao exp;
    int Limite_superior,Limite_inferior;
}Integral;
void Imprime_analiza(Fila_de_valores *Valores,Fila_de_letras *Letras,Fila_de_expoentes *Expoentes,Fila_de_operacoes *Operacoes);
void Organiza(Fila_de_valores *Valores,Fila_de_letras *Letras,Fila_de_expoentes *Expoentes,Fila_de_operacoes *Operacoes,Poteiro_da_fila_princial_de_caracteres auxiliar_primario,Poteiro_da_fila_princial_de_inteiros auxiliar_secundario);
void Leitura_da_expressao(Limite *lim);
double Primeira_analise(Limite *lim);
void Resultado_do_limite(Limite *lim);
double Particiona(Fila_de_valores *Valores,Fila_de_expoentes *Expoentes,Fila_de_operacoes *Operacoes,double Inteiro_de_analise);
void Resultado_da_Derivada(Derivada *Y,Expressao *E,int resposta);
void Resultado_da_Integral(Integral *Z,Expressao *E,int resposta);
double Fatorial(double Valor);
double Seno(double Valor);
double Cosseno(double Valor);
double Tangente(double Valor);
void Cria(char *Expressao);

#endif //CALCULADORA_CIENTIFICA2_0_TAD_CALCULADORA_H

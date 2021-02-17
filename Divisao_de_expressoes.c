//
// Created by pedro on 26/07/2020.
//

#include "Divisao_de_expressoes.h"
double Analise_da_divisao(Estrutura_expressao *Exp1,Estrutura_expressao *Exp2,Limite *X){
    double Resultado_correto=0;
    double Primeira_expressao, Segunda_expressao;
    double Vetor_de_valores_para_analise [10];
    int Vetor_de_parametros[10];
    int Position = 0;
    int Auxiliar_traspondo_para_inteiro;
    int Flag_para_finalisar_analise = 0;
    int isDivisivel=0,notDivisivel=0,Inteiro;
    int Dividendo,Divisor,Tipo_de_dizima;
    for(int i=0;i<10;i++){
        Primeira_expressao = Particiona(&Exp1->Valores,&Exp1->Expoentes,&Exp1->Operacoes,i);
        Segunda_expressao = Particiona(&Exp2->Valores,&Exp2->Expoentes,&Exp2->Operacoes,i);
        if(Segunda_expressao != 0){
            if(Flag_para_finalisar_analise == 0) {
                if (Primeira_expressao != 0) {
                    Auxiliar_traspondo_para_inteiro = Primeira_expressao / Segunda_expressao;
                    if (((Primeira_expressao / Segunda_expressao) - Auxiliar_traspondo_para_inteiro) == 0) {
                        isDivisivel = 1;
                    } else {
                        notDivisivel = 1;
                    }
                    Flag_para_finalisar_analise = 1;
                }
            }
            Vetor_de_valores_para_analise[Position] = Primeira_expressao/Segunda_expressao;
            Vetor_de_parametros [Position] = i;
            Position++;
        }
    }
    if(isDivisivel == 1){
        for(int i=0;i<Position;i++){
            Inteiro = Vetor_de_valores_para_analise[i];
            if (Vetor_de_valores_para_analise[i] < Inteiro || Vetor_de_valores_para_analise[i] > Inteiro) {
                Dividendo = Vetor_de_valores_para_analise[i] * 1000000;
                Divisor = 1000000;
                Tipo_de_dizima = Verifica_dizima(Dividendo);
                if(Tipo_de_dizima == 0){
                    //simples
                }
                if(Tipo_de_dizima == 1){
                    //composta
                }
                if(Tipo_de_dizima == 2){
                    //a determinar
                }
                Determina_fatores(Dividendo,Divisor);
            }
            else{
                //inteiro
            }
        }
    }
    return Resultado_correto;
}
int Verifica_dizima(int valor){
    int Tipo_de_dizima;

    return Tipo_de_dizima;
}
int Determina_fatores(int Dividendo,int Divisor){
    Fila_de_resultados Resultados_numerador,Resultados_denominador;
    Start(&Resultados_numerador);Start(&Resultados_denominador);
    int Fatores_a_serem_divididos = 2;
    int flag_is_negative = 0;
    int Resultado;
    if(Dividendo<0){
        Dividendo = Dividendo*(-1);
        flag_is_negative = 1;
    }
    printf("Dividendo %d Divisor %d\n",Dividendo,Divisor);
    while(1){
        if(Dividendo%Fatores_a_serem_divididos == 0){
            Resultado = Dividendo / Fatores_a_serem_divididos;
            InsereResultado(&Resultados_numerador,Fatores_a_serem_divididos);
            Dividendo = Resultado;
        }
        if(Resultado%Fatores_a_serem_divididos != 0){
            Fatores_a_serem_divididos++;
        }
        if(Resultado == 1)
            break;
    }
    Fatores_a_serem_divididos = 2;
    while(1){
        if(Divisor%Fatores_a_serem_divididos == 0){
            Resultado = Divisor / Fatores_a_serem_divididos;
            InsereResultado(&Resultados_denominador,Fatores_a_serem_divididos);
            Divisor = Resultado;
        }
        if(Resultado%Fatores_a_serem_divididos != 0){
            Fatores_a_serem_divididos++;
        }
        if(Resultado == 1)
            break;
    }
    if(Resultados_numerador.Tamanho>Resultados_denominador.Tamanho){
        int diferenca = Resultados_numerador.Tamanho - Resultados_denominador.Tamanho;
        for(int i =0;i<diferenca;i++){
            InsereResultado(&Resultados_denominador,0);
        }
    }
    Compara(&Resultados_numerador,&Resultados_denominador,flag_is_negative);
    return 0;
}
int Compara(Fila_de_resultados *Fatores_numerador,Fila_de_resultados *Fatores_denominador,int flag_is_negative){
    Ponteiro_da_fila_de_resultados Aponta_fatores_numerador,Aponta_fatores_denominador;
    Aponta_fatores_numerador = Fatores_numerador->Start;
    Aponta_fatores_denominador = Fatores_denominador->Start;
    int Resultado_numerador = 1;
    int Resultado_denominador = 1;
    while (Aponta_fatores_numerador!=NULL && Aponta_fatores_denominador!=NULL){
        if(Aponta_fatores_numerador->Resultado == Aponta_fatores_denominador->Resultado){
            Aponta_fatores_denominador->Resultado = 0;
            Aponta_fatores_numerador->Resultado = 0;
        }
        Aponta_fatores_numerador = Aponta_fatores_numerador->prox;
        Aponta_fatores_denominador = Aponta_fatores_denominador->prox;
    }
    Aponta_fatores_numerador = Fatores_numerador->Start;
    Aponta_fatores_denominador = Fatores_denominador->Start;
    while (Aponta_fatores_numerador!=NULL && Aponta_fatores_denominador!=NULL){
        if(Aponta_fatores_numerador->Resultado != 0){
            Resultado_numerador*=Aponta_fatores_numerador->Resultado;
        }
        if(Aponta_fatores_denominador->Resultado != 0){
            Resultado_denominador*=Aponta_fatores_denominador->Resultado;
        }
        Aponta_fatores_numerador = Aponta_fatores_numerador->prox;
        Aponta_fatores_denominador = Aponta_fatores_denominador->prox;
    }
    if(flag_is_negative == 1){
        Resultado_numerador*=(-1);
    }
    printf("Resultado numerador %d Resultado denominador %d\n",Resultado_numerador,Resultado_denominador);
    return 0;
}
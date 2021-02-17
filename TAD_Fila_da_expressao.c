//
// Created by pedro on 26/07/2020.
//

#include "TAD_Fila_da_expressao.h"

void Inicia(Fila_de_valores *fila){
    Inicia_fila_de_expoentes(&fila->Expoentes);
    Inicia_fila_de_letras(&fila->Letter);
    Inicia_fila_de_operacoes(&fila->Operacao);
    Inicia_fila_de_filas(&fila->Filas);
    Inicia_fila_de_operacoes_entre_filas(&fila->Operacoes_entre_filas);
    fila->initial=NULL;
    fila->end=NULL;
    fila->Tamanho=0;
}
void InsereValor(Fila_de_valores *fila,double Valor,int Posicao){
    if(fila->end==NULL){
        fila->end=(Ponteiro_da_fila_de_valores)malloc(sizeof(Tcelula));
        fila->initial=fila->end;
    }
    else{
        fila->end->prox=(Ponteiro_da_fila_de_valores)malloc(sizeof(Tcelula));
        fila->end=fila->end->prox;
    }
    fila->end->Posicao=Posicao;
    fila->end->Valor=Valor;
    fila->end->prox = NULL;
    fila->Tamanho++;
}

Fila_de_resultados Resultado(Fila_de_resultados *fila_de_resultados,Fila_de_operacoes *Operacoes,int Tamanho_dos_valores) {
    char Operacao[Operacoes->Tamanho];
    double Numbers[Tamanho_dos_valores];
    int auxiliar=0;
    int verifica = 0;
    int posicao = 0;
    double Resultado1 = 0;
    double Resultado2 = 0;
    double Resultado3 = 0;
    int posicao2 = 0;
    Fila_de_resultados Result_final;
    Start(&Result_final);
    Ponteiro_da_fila_de_operacoes aux;
    Ponteiro_da_fila_de_resultados aux1;
    aux = Operacoes->initial;
    aux1 = fila_de_resultados->Start;
    while (aux != NULL) {
        Operacao[posicao] = aux->operacao;
        aux = aux->prox;
        posicao++;
        verifica++;
    }
    posicao = 0;
    while (aux1 != NULL) {
        Numbers[posicao] = aux1->Resultado;
        aux1 = aux1->prox;
        posicao++;
    }
    posicao = 0;
    if (verifica == 0) {
        InsereResultado(&Result_final, Numbers[0]);
        return Result_final;
    }
    else{
        for (int i = 0; i < Tamanho_dos_valores - 1; i++) {
            if (Operacao[i] == '*' && posicao == 0) {
                posicao2 = 0;
                auxiliar = 1;
                Resultado1=Numbers[i];
                if (Operacao[i - 1] == '-') {
                    Resultado1 = Numbers[i] * (-1);
                }
                if (Operacao[i - 1] == '+') {
                    Resultado1 = Numbers[i];
                }
                if (Operacao[i - 1] == '/') {
                    Resultado1 = Resultado3;
                    Remove(&Result_final, Resultado1, Result_final.Tamanho - 1);
                }
                if (Operacao[i + 1] == '*') {
                    posicao = i + 1;
                    while (1) {
                        if (Operacao[posicao] != '*') {
                            Resultado1 *= Numbers[posicao];
                            break;
                        }
                        Resultado1 *= Numbers[posicao];
                        posicao++;
                    }
                    InsereResultado(&Result_final, Resultado1);
                }
                if ((Operacao[i - 1] != '*' && Operacao[i + 1] != '*') && Operacao[i - 1] != '/') {
                    Resultado1 = Resultado1 * Numbers[i + 1];
                    InsereResultado(&Result_final, Resultado1);
                }
                if ((Operacao[i - 1] != '*' && Operacao[i + 1] != '*') && Operacao[i - 1] == '/') {
                    Resultado1 = Resultado1 * Numbers[i + 1];
                    InsereResultado(&Result_final, Resultado1);
                }
                Resultado3 = Resultado1;
            }
            else if ((Operacao[i + 1] != '*' && Operacao[i + 1] != '/') &&
                     ((Operacao[i] == '+' || Operacao[i] == '-') &&
                      (Operacao[i + 2] != '*' && Operacao[i + 2] != '/'))) {
                posicao = 0;
                posicao2 = 0;
                auxiliar=1;
                if (Operacao[i] == '+') {
                    if (Operacao[i - 1] == '*' || Operacao[i - 1] == '/') {
                        Resultado2 = Numbers[i + 1];
                        InsereResultado(&Result_final, Resultado2);
                    }
                    else if (Operacao[i - 1] != '*' && Operacao[i - 1] != '/') {
                        if (Operacao[i - 1] != '+' && Operacao[i - 1] != '-') {
                            Resultado2 = Numbers[i];
                            InsereResultado(&Result_final, Resultado2);
                        }
                        Resultado2 = Numbers[i + 1];
                        InsereResultado(&Result_final, Resultado2);
                    } else {
                        if (Operacao[i - 1] == '*') {
                            Resultado2 = Numbers[i + 1];
                        }
                        else {
                            Resultado2 = Numbers[i];
                        }
                        InsereResultado(&Result_final, Resultado2);
                    }
                }
                else {
                    if (Operacao[i - 1] == '*' || Operacao[i - 1] == '/') {
                        Resultado2 = Numbers[i + 1] * (-1);
                        InsereResultado(&Result_final, Resultado2);
                    }
                    else if (Operacao[i - 1] != '*' && Operacao[i - 1] != '/') {
                        if (Operacao[i - 1] != '+' && Operacao[i - 1] != '-') {
                            Resultado2 = Numbers[i];
                            InsereResultado(&Result_final, Resultado2);
                        }
                        Resultado2 = Numbers[i + 1] * (-1);
                        InsereResultado(&Result_final, Resultado2);
                    }
                    else {
                        if (Operacao[i - 1] == '*') {
                            Resultado2 = Numbers[i + 1] * (-1);
                        }
                        else {
                            Resultado2 = Numbers[i] * (-1);
                        }
                        InsereResultado(&Result_final, Resultado2);
                    }
                }
            }
            else if ((Operacao[i + 1] == '*' || Operacao[i + 1] == '/') &&
                     (Operacao[i] == '+' || Operacao[i] == '-') && Operacao[i - 1] != '/' && Operacao[i - 1] != '*') {
                posicao = 0;
                posicao2 = 0;
                auxiliar = 1;
                if (Operacao[i] == '+')
                    Resultado2 = Numbers[i];
                if (Operacao[i - 1] == '-')
                    Resultado2 = Numbers[i] * (-1);
                if (Operacao[i - 1] == '+')
                    Resultado2 = Numbers[i];
                InsereResultado(&Result_final, Resultado2);
            }
            else if (Operacao[i] == '/' && posicao2 == 0) {
                posicao = 0;
                auxiliar = 1;
                Resultado1=Numbers[i];
                if (Operacao[i - 1] == '-') {
                    Resultado1 = Numbers[i] * (-1);
                }
                if (Operacao[i - 1] == '+') {
                    Resultado1 = Numbers[i];
                }
                if (Operacao[i - 1] == '*') {
                    Resultado1 = Resultado3;
                    Remove(&Result_final, Resultado1, Result_final.Tamanho - 1);
                }
                if (Operacao[i + 1] == '/') {
                    posicao2 = i + 1;
                    while (1) {
                        if (Operacao[posicao2] != '/') {
                            Resultado1 /= Numbers[posicao2];
                            break;
                        }
                        Resultado1 /= Numbers[posicao2];
                        posicao2++;
                    }
                    InsereResultado(&Result_final, Resultado1);
                }
                if ((Operacao[i - 1] != '/' && Operacao[i + 1] != '/') && Operacao[i - 1] != '*') {
                    Resultado1 = Resultado1 / Numbers[i + 1];
                    InsereResultado(&Result_final, Resultado1);
                }
                if ((Operacao[i - 1] != '/' && Operacao[i + 1] != '/') && Operacao[i - 1] == '*') {
                    Resultado1 = Resultado1 / Numbers[i + 1];
                    InsereResultado(&Result_final, Resultado1);
                }
                Resultado3 = Resultado1;
            }
            else if ((Operacao[i - 1] != '/' && Operacao[i + 1] != '/') && Operacao[i - 1] != '*' &&
                     Operacao[i] == '/') {
                auxiliar =1;
                Resultado1 = Numbers[i] / Numbers[i + 1];
                if(Operacao[i-1]=='-'){
                    Resultado1=Resultado1*(-1);
                }
                InsereResultado(&Result_final, Resultado1);
            }
            else if ((Operacao[i - 1] != '*' && Operacao[i + 1] != '*') && Operacao[i - 1] != '/' &&
                     Operacao[i] == '*') {
                auxiliar =1;
                Resultado1 = Numbers[i] * Numbers[i + 1];
                if(Operacao[i-1]=='-'){
                    Resultado1=Resultado1*(-1);
                }
                InsereResultado(&Result_final, Resultado1);
            }
            else{
                if(auxiliar==0)
                    InsereResultado(&Result_final,Numbers[i]);
                auxiliar = 1;
            }
        }
        return Result_final;
    }
}
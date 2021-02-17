//
// Created by pedro on 26/07/2020.
//

#include "TAD_fila_de_operacoes.h"
void Inicia_fila_de_operacoes(Fila_de_operacoes *fila){
    fila->initial=NULL;
    fila->end=NULL;
    fila->Tamanho=0;
}
void InsereOperacao(Fila_de_operacoes *fila,char operacao,int Posicao){
    if(fila->end==NULL){
        fila->end=(Ponteiro_da_fila_de_operacoes)malloc(sizeof(Tcelula2));
        fila->initial=fila->end;
    }
    else{
        fila->end->prox=(Ponteiro_da_fila_de_operacoes)malloc(sizeof(Tcelula2));
        fila->end=fila->end->prox;
    }
    fila->end->operacao=operacao;
    fila->end->Posicao=Posicao;
    fila->end->prox = NULL;
    fila->Tamanho++;
}
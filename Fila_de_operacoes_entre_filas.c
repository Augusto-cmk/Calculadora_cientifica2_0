//
// Created by pedro on 26/07/2020.
//

#include "Fila_de_operacoes_entre_filas.h"
void Inicia_fila_de_operacoes_entre_filas(Fila_de_operacoes_entre_filas *fila){
    fila->initial=NULL;
    fila->end=NULL;
    fila->Tamanho=0;
}
void InsereOperacao_entre_filas(Fila_de_operacoes_entre_filas *fila,char Operacao){
    if(fila->end==NULL){
        fila->end=(Ponteiro_da_fila_de_operacoes_entre_filas)malloc(sizeof(Tcelula_de_operacoes_entre_filas));
        fila->initial=fila->end;
    }
    else{
        fila->end->prox=(Ponteiro_da_fila_de_operacoes_entre_filas)malloc(sizeof(Tcelula_de_operacoes_entre_filas));
        fila->end=fila->end->prox;
    }
    fila->end->Operacao=Operacao;
    fila->end->prox = NULL;
    fila->Tamanho++;
}
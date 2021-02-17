//
// Created by pedro on 26/07/2020.
//

#include "TAD_fila_de_expoentes.h"
void Inicia_fila_de_expoentes(Fila_de_expoentes *fila){
    fila->initial=NULL;
    fila->end=NULL;
    fila->Tamanho=0;
}
void InsereExpoente(Fila_de_expoentes *fila,double expoente,int Posicao){
    if(fila->end==NULL){
        fila->end=(Ponteiro_da_fila_de_expoentes)malloc(sizeof(Tcel3));
        fila->initial=fila->end;
    }
    else{
        fila->end->prox=(Ponteiro_da_fila_de_expoentes)malloc(sizeof(Tcel3));
        fila->end=fila->end->prox;
    }
    fila->end->Posicao=Posicao;
    fila->end->expoente=expoente;
    fila->end->prox = NULL;
    fila->Tamanho++;
}
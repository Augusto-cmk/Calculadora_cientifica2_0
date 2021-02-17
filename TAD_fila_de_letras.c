//
// Created by pedro on 26/07/2020.
//

#include "TAD_fila_de_letras.h"
void Inicia_fila_de_letras(Fila_de_letras *fila){
    fila->initial=NULL;
    fila->end=NULL;
    fila->Tamanho=0;
}
void InsereLetra(Fila_de_letras *fila,char letra,int Posicao){
    if(fila->end==NULL){
        fila->end=(Poteiro_da_fila_de_letras)malloc(sizeof(Tcel));
        fila->initial=fila->end;
    }
    else{
        fila->end->prox=(Poteiro_da_fila_de_letras)malloc(sizeof(Tcel));
        fila->end=fila->end->prox;
    }
    fila->end->letra=letra;
    fila->end->Posicao=Posicao;
    fila->end->prox = NULL;
    fila->Tamanho++;
}
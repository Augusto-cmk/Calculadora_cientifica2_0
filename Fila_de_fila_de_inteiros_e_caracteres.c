//
// Created by pedro on 26/07/2020.
//

#include "Fila_de_fila_de_inteiros_e_caracteres.h"
void Inicia_fila_de_filas(Fila_de_filas *fila){
    fila->initial=NULL;
    fila->end=NULL;
    fila->Tamanho=0;
}
void InsereFila(Fila_de_filas *fila,Fila_pricipal_de_inteiros *Fila_de_inteiros,Fila_pricipal_de_caracteres *Fila_de_caracteres){
    if(fila->end==NULL){
        fila->end=(Poteiro_da_fila_de_filas)malloc(sizeof(Tcelula_da_fila_de_filas));
        fila->initial=fila->end;
    }
    else{
        fila->end->prox=(Poteiro_da_fila_de_filas)malloc(sizeof(Tcelula_da_fila_de_filas));
        fila->end=fila->end->prox;
    }
    fila->end->Fila_de_inteiros=*Fila_de_inteiros;
    fila->end->Fila_de_caracteres=*Fila_de_caracteres;
    fila->end->prox = NULL;
    fila->Tamanho++;
}
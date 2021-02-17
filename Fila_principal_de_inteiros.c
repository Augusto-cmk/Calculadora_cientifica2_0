//
// Created by pedro on 26/07/2020.
//

#include "Fila_principal_de_inteiros.h"
void Inicia_fila_principal_de_inteiros(Fila_pricipal_de_inteiros *fila){
    fila->initial=NULL;
    fila->end=NULL;
}
void InsereInteiros(Fila_pricipal_de_inteiros *fila,double Inteiro,int Posicao){
    if(fila->end==NULL){
        fila->end=(Poteiro_da_fila_princial_de_inteiros)malloc(sizeof(Tcelula_da_fila_principal));
        fila->initial=fila->end;
    }
    else{
        fila->end->prox=(Poteiro_da_fila_princial_de_inteiros)malloc(sizeof(Tcelula_da_fila_principal));
        fila->end=fila->end->prox;
    }
    fila->end->Inteiro=Inteiro;
    fila->end->Posicao=Posicao;
    fila->end->prox = NULL;
}
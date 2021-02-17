//
// Created by pedro on 26/07/2020.
//

#include "Fila_principal_de_caracteres.h"
void Inicia_fila_principal_de_caracteres(Fila_pricipal_de_caracteres *fila){
    fila->initial=NULL;
    fila->end=NULL;
}
void InsereCaractere(Fila_pricipal_de_caracteres *fila,char Caractere,int Posicao){
    if(fila->end==NULL){
        fila->end=(Poteiro_da_fila_princial_de_caracteres)malloc(sizeof(Tcelula_da_fila_principal2));
        fila->initial=fila->end;
    }
    else{
        fila->end->prox=(Poteiro_da_fila_princial_de_caracteres)malloc(sizeof(Tcelula_da_fila_principal2));
        fila->end=fila->end->prox;
    }
    fila->end->Caractere=Caractere;
    fila->end->Posicao=Posicao;
    fila->end->prox = NULL;
}
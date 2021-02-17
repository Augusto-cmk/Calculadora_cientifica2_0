//
// Created by pedro on 26/07/2020.
//

#include "TAD_fila_de_resultados.h"

void Start(Fila_de_resultados *fila){
    fila->Start=NULL;
    fila->End=NULL;
    fila->Tamanho=0;
}

void InsereResultado(Fila_de_resultados *fila,double Resultado){
    if(fila->End==NULL){
        fila->End=(Ponteiro_da_fila_de_resultados)malloc(sizeof(Tcelula1));
        fila->Start=fila->End;
    }
    else{
        fila->End->prox=(Ponteiro_da_fila_de_resultados)malloc(sizeof(Tcelula1));
        fila->End=fila->End->prox;
    }
    fila->End->Resultado=Resultado;
    fila->End->prox=NULL;
    fila->Tamanho++;
}
void Remove(Fila_de_resultados *fila,double Valor,int Posicao){
    Ponteiro_da_fila_de_resultados aux;
    aux=fila->Start;
    int contador=0;
    while (aux!=NULL){
        if(aux->Resultado==Valor && Posicao==contador){
            aux->Resultado=0;
        }
        aux=aux->prox;
        contador++;
    }
}

void Print(Fila_de_resultados *fila){
    Ponteiro_da_fila_de_resultados aux;
    aux=fila->Start;
    printf("Resultados:");
    while (aux!=NULL){
        printf("%lf ",aux->Resultado);
        aux=aux->prox;
    }
}
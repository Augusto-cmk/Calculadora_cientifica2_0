//
// Created by pedro on 26/07/2020.
//

#include "Interface.h"

void Info(){
    printf("|-------------Forma de construção da expressão-------------|\n");
    printf("|->Multiplicacao é representada por [*]                    |\n");
    printf("|->Divisao é representada por [/]                          |\n");
    printf("|->Nao é representado o simbolo de expoente                |\n");
    printf("|->O expoente 1 deve ser digitado                          |\n");
    printf("|->O numero 1 deve ser digitado                            |\n");
    printf("|->Lembre de salvar o arquivo no Cmake do Clion            |\n");
    printf("|->Operações entre funções deve ser colocada na prox linha |\n");
    printf("|->Só é valido colocar um numero isolado por função        |\n");
    printf("|->O numero isolado deve se encontrar no final da função   |\n");
    printf("|----------------------------------------------------------|\n");
}

void Questions(){
    int Resposta;
    char resposta;
    printf("O que deseja calcular de sua expressão:");printf("\n");
    printf("1->Limite\n");printf("2->Derivada\n");printf("3->Integral\n");printf("Resposta:");
    scanf("%d",&Resposta);
    if(Resposta==1){
        Limite lim;
        Resultado_do_limite(&lim);
        printf("\nDeseja encerrar o calculo ?\n");printf("\nS para sim e N para não\n");printf("->");
        scanf("%s",&resposta);
        if(resposta=='S'){
            exit(0);
        }
        if(resposta=='N'){
//            free(&lim);
            Questions();
        }
    }
}
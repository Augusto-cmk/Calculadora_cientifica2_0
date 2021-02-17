//
// Created by pedro on 26/07/2020.
//

#include "TAD_calculadora.h"
#include "Divisao_de_expressoes.h"
#include "Interface.h"
double Fatorial(double Valor){
    if(Valor==0){
        return 1;
    }
    if(Valor==1){
        return 1;
    }
    else{
        return Valor*Fatorial(Valor-1);
    }
}
double Seno(double Valor){
    double numerador = 1;
    double denominador =1;
    int expoente = 1;
    double resultado=0;
    double valor_final = Valor*0.0174533;
    for(int i=0;i<100;i++){
        if(i%2==0){
            resultado+=(numerador*pow(valor_final,expoente))/Fatorial(denominador);
            expoente+=2;
            denominador+=2;
        }
        else{
            resultado+=((numerador*pow(valor_final,expoente))/Fatorial(denominador))*(-1);
            expoente+=2;
            denominador+=2;
        }
    }
    return resultado;
}
double Cosseno(double Valor){
    double numerador = 1;
    double denominador =0;
    int expoente = 0;
    double resultado=0;
    double valor_final = Valor*0.0174533;
    for(int i=0;i<100;i++){
        if(i%2==0){
            resultado+=(numerador*pow(valor_final,expoente))/Fatorial(denominador);
            expoente+=2;
            denominador+=2;
        }
        else{
            resultado+=((numerador*pow(valor_final,expoente))/Fatorial(denominador))*(-1);
            expoente+=2;
            denominador+=2;
        }
    }
    return resultado;
}
double Tangente(double Valor){
    double Valor_da_tangente;
    if(Cosseno(Valor)<0.000004){
        return 0;
    }
    else{
        Valor_da_tangente = Seno(Valor)/Cosseno(Valor);
        return Valor_da_tangente;
    }
}
void Imprime_analiza(Fila_de_valores *Valores,Fila_de_letras *Letras,Fila_de_expoentes *Expoentes,Fila_de_operacoes *Operacoes){
    Ponteiro_da_fila_de_operacoes operacao = Operacoes->initial;
    Ponteiro_da_fila_de_valores valores = Valores->initial;
    Poteiro_da_fila_de_letras letras = Letras->initial;
    Ponteiro_da_fila_de_expoentes expoentes = Expoentes->initial;
    printf("\nValores:");
    while (valores!=NULL){
        printf("%lf ",valores->Valor);
        valores=valores->prox;
    }
    printf("\nLetras:");
    while (letras!=NULL){
        printf("%c ",letras->letra);
        letras=letras->prox;
    }
    printf("\nExpoentes:");
    while (expoentes!=NULL){
        printf("%lf ",expoentes->expoente);
        expoentes=expoentes->prox;
    }
    printf("\nOperacoes:");
    while (operacao!=NULL){
        printf("%c ",operacao->operacao);
        operacao=operacao->prox;
    }
//    printf("\n%d",X->exp.Fila_da_Expressao.Filas.Tamanho);
}
double Primeira_analise(Limite *lim){
    Estrutura_expressao Exp1; Estrutura_expressao Exp2;int Posicao2=0;int Posicao_de_analise[lim->exp.Fila_da_Expressao.Operacoes_entre_filas.Tamanho];
    Poteiro_da_fila_de_filas Particionando = lim->exp.Fila_da_Expressao.Filas.initial;
    Ponteiro_da_fila_de_operacoes_entre_filas Operacoes_entre = lim->exp.Fila_da_Expressao.Operacoes_entre_filas.initial;
    Fila_de_operacoes Operacoes_entre_filas;Fila_de_resultados Valores_resultantes1;
    Inicia_fila_de_operacoes(&Operacoes_entre_filas);
    Start(&Valores_resultantes1);
    Fila_de_resultados Final1;
    Posicao_de_analise[0]=10;
    double Resultado_correto;
    int Validacao=0;int Comfirma=0;
    double auxilia1;int Posicao=0;double Resposta1=0;
    while (Operacoes_entre!=NULL){
        if(Operacoes_entre->Operacao=='/'){
            Posicao_de_analise[Posicao] = Posicao;
        }
        else{
            InsereOperacao(&Operacoes_entre_filas,Operacoes_entre->Operacao,Posicao);
        }
        Operacoes_entre = Operacoes_entre->prox;
        Posicao++;
    }
    while (Particionando!=NULL) {
        Fila_de_valores Valores;Fila_de_letras Letras;Fila_de_expoentes Expoentes;Fila_de_operacoes Operacoes;
        Inicia_fila_de_operacoes(&Operacoes);
        Inicia_fila_de_expoentes(&Expoentes);
        Inicia_fila_de_letras(&Letras);
        Inicia(&Valores);
        Poteiro_da_fila_princial_de_caracteres auxiliar_primario = Particionando->Fila_de_caracteres.initial;
        Poteiro_da_fila_princial_de_inteiros auxiliar_secundario = Particionando->Fila_de_inteiros.initial;
        Organiza(&Valores,&Letras,&Expoentes,&Operacoes,auxiliar_primario,auxiliar_secundario);
        //Imprime_analiza(&Valores,&Letras,&Expoentes,&Operacoes);printf("\n");
        if(Posicao_de_analise[Posicao2] == Posicao2){
            Exp1.Valores=Valores;
            Exp1.Letras=Letras;
            Exp1.Operacoes=Operacoes;
            Exp1.Expoentes=Expoentes;
            Validacao++;
        }
        if (Posicao_de_analise[Posicao2-1] == Posicao2-1){
            Exp2.Valores=Valores;
            Exp2.Letras=Letras;
            Exp2.Expoentes=Expoentes;
            Exp2.Operacoes=Operacoes;
            Validacao++;
        }
        if(Validacao==2){
            Resultado_correto = Analise_da_divisao(&Exp1,&Exp2,lim);
            InsereResultado(&Valores_resultantes1,Resultado_correto);
            Validacao=0;
            Comfirma=1;
        }
        if(Validacao == 0 && Comfirma == 0) {
            auxilia1 = Particiona(&Valores, &Expoentes, &Operacoes, lim->Tendencia);
            InsereResultado(&Valores_resultantes1, auxilia1);
        }
        Particionando=Particionando->prox;
        Posicao2++;
        Comfirma = 0;
    }
    Final1 = Resultado(&Valores_resultantes1, &Operacoes_entre_filas, lim->exp.Fila_da_Expressao.Operacoes_entre_filas.Tamanho+1);
    Ponteiro_da_fila_de_resultados aux1;
    aux1 = Final1.Start;
    while (aux1 != NULL) {
        Resposta1 += aux1->Resultado;
        aux1 = aux1->prox;
    }
    return Resposta1;
}
void Organiza(Fila_de_valores *Valores,Fila_de_letras *Letras,Fila_de_expoentes *Expoentes,Fila_de_operacoes *Operacoes,Poteiro_da_fila_princial_de_caracteres auxiliar_primario,Poteiro_da_fila_princial_de_inteiros auxiliar_secundario){
    int Posicao=0;int Posicao2;
    while (auxiliar_primario!=NULL){
        if(auxiliar_primario->Caractere=='+' || auxiliar_primario->Caractere=='-' || auxiliar_primario->Caractere=='*' || auxiliar_primario->Caractere=='/') {
            InsereOperacao(Operacoes, auxiliar_primario->Caractere, auxiliar_primario->Posicao);
        }
        else
            InsereLetra(Letras,auxiliar_primario->Caractere,auxiliar_primario->Posicao);
        auxiliar_primario=auxiliar_primario->prox;
    }
    Poteiro_da_fila_de_letras auxiliar_de_posicao= Letras->initial;
    int Posicoes[Letras->Tamanho];
    while (auxiliar_de_posicao!=NULL){
        Posicoes[Posicao]=auxiliar_de_posicao->Posicao;
        auxiliar_de_posicao=auxiliar_de_posicao->prox;
        Posicao++;
    }
    Posicao2=Posicao;
    while (auxiliar_secundario!=NULL) {
        if(Posicoes[Posicao - Posicao2] == auxiliar_secundario->Posicao - 1){
            InsereExpoente(Expoentes,auxiliar_secundario->Inteiro,auxiliar_secundario->Posicao);
            Posicao2--;
        }
        else{
            InsereValor(Valores,auxiliar_secundario->Inteiro,auxiliar_secundario->Posicao);
        }
        auxiliar_secundario=auxiliar_secundario->prox;
    }
}
void Leitura_da_expressao(Limite *lim){
    FILE *file;
    Inicia(&lim->exp.Fila_da_Expressao);
    Fila_pricipal_de_caracteres aux1;
    Fila_pricipal_de_inteiros aux2;
    Inicia_fila_principal_de_caracteres(&aux1);
    Inicia_fila_principal_de_inteiros(&aux2);
    char Nome[2000];double varia = 0.00001;double tendencia = lim->Tendencia;double valor_real;
    printf("\nDigite a expressão:");scanf("%s",Nome);
    Cria(Nome);
    file=fopen("Controle","r");char resto;
    double Numero,numero_antigo,numero_novo;char caractere,caractere_antigo;int Posicao=0, Posicao_inteiro=0;char operacao;
    int confirma=0,continue1=0;
    if(file==NULL){
        printf("\nArquivo nao existe\n");printf("Deseja continuar? S para sim e N para não:");scanf("%s",&resto);
        if(resto=='S'){
            Questions();
        }
        else{
            exit(0);
        }
    }
    while (!feof(file)) {
        caractere = fgetc(file);
        if(caractere!='\n' && !feof(file) && caractere!='/' && caractere!='*') {
            if(caractere !='0' && caractere !='1' && caractere !='2' && caractere !='3' && caractere !='4' && caractere !='5' && caractere !='6' && caractere !='7' && caractere !='8' && caractere !='9') {
                InsereCaractere(&aux1,caractere,Posicao_inteiro+1);
                if(caractere_antigo == '0' || caractere_antigo == '1' || caractere_antigo == '2' || caractere_antigo == '3' || caractere_antigo == '4' || caractere_antigo == '5' || caractere_antigo == '6' || caractere_antigo == '7' || caractere_antigo == '8' || caractere_antigo == '9'){
                    InsereInteiros(&aux2,Numero,Posicao_inteiro);
                }
                confirma=1;
            }
            else{
                Numero = caractere - '0';
                if(confirma == 0) {
                    numero_novo = numero_antigo * 10 + Numero;
                    Numero = numero_novo;
                }
                confirma =0;
                Posicao_inteiro = Posicao;
            }
            numero_antigo=Numero;
            caractere_antigo = caractere;
            Posicao++;
            continue1 =0;
        }
        else if(caractere == '\n' && continue1 == 0) {
            if(caractere_antigo == '0' || caractere_antigo == '1' || caractere_antigo == '2' || caractere_antigo == '3' || caractere_antigo == '4' || caractere_antigo == '5' || caractere_antigo == '6' || caractere_antigo == '7' || caractere_antigo == '8' || caractere_antigo == '9'){
                InsereInteiros(&aux2,Numero,Posicao_inteiro);
            }
            Posicao_inteiro = 0;
            Posicao = 0;
            InsereFila(&lim->exp.Fila_da_Expressao.Filas,&aux2,&aux1);
            Inicia_fila_principal_de_caracteres(&aux1);
            Inicia_fila_principal_de_inteiros(&aux2);
            continue1 = 1;
            confirma =1;
        }
        else if(caractere == '*' || caractere == '/'){
            InsereOperacao_entre_filas(&lim->exp.Fila_da_Expressao.Operacoes_entre_filas, caractere);
            confirma =1;
        }
        else if(feof(file)){
            if(caractere_antigo == '0' || caractere_antigo == '1' || caractere_antigo == '2' || caractere_antigo == '3' || caractere_antigo == '4' || caractere_antigo == '5' || caractere_antigo == '6' || caractere_antigo == '7' || caractere_antigo == '8' || caractere_antigo == '9'){
                InsereInteiros(&aux2,Numero,Posicao_inteiro);
            }
            InsereFila(&lim->exp.Fila_da_Expressao.Filas,&aux2,&aux1);
        }
    }
    fclose(file);
    //lim->Tendencia = tendencia-varia;
    //lim->esquerda = Primeira_analise(lim);
    //lim->Tendencia = tendencia+varia;
    //lim->Direita = Primeira_analise(lim);
    //if(lim->Direita - lim->esquerda < 1){
        lim->Tendencia = tendencia;
        valor_real = Primeira_analise(lim);
        printf("Limite existente=%lf",valor_real);
    //}
    //else
        //printf("limite inexistente");
}
void Resultado_do_limite(Limite *lim){
    double Tendencia;
    printf("Digite o valor da tendencia do limite:");
    scanf("%lf",&Tendencia);
    lim->Tendencia=Tendencia;
    Leitura_da_expressao(lim);
}
double Particiona(Fila_de_valores *Valores,Fila_de_expoentes *Expoentes,Fila_de_operacoes *Operacoes,double Inteiro_de_analise){
    Fila_de_resultados Resultados;
    Start(&Resultados);
    double Result;double Resposta=0;
    Ponteiro_da_fila_de_valores aux;
    Ponteiro_da_fila_de_expoentes aux1;
    Fila_de_resultados Final;
    aux = Valores->initial;
    aux1 = Expoentes->initial;
    while(1) {
        if((aux1 == NULL && aux != NULL)){
            Result = aux->Valor;
            InsereResultado(&Resultados,Result);
            aux = aux->prox;
        }
        else if(aux1 != NULL && aux != NULL){
            Result = aux->Valor*pow(Inteiro_de_analise,aux1->expoente);
            InsereResultado(&Resultados,Result);
            aux1 = aux1->prox;
            aux = aux->prox;
        }
        else
            break;
    }
    Final = Resultado(&Resultados,Operacoes,Valores->Tamanho);
    Ponteiro_da_fila_de_resultados aux2;
    aux2 = Final.Start;
    while (aux2 != NULL){
        Resposta += aux2->Resultado;
        aux2 = aux2->prox;
    }
    return Resposta;
}
void Cria(char *Expressao){
    FILE *file;
    unsigned int tamanho = strlen(Expressao);

    file = fopen("Controle","w");
    for(int i = 0;i<tamanho;i++){
        if(Expressao[i] == ')' || Expressao[i] == '('){
            if(i!=0 && (Expressao[i+1] == '/' || Expressao[i+1] == '*' || Expressao[i+1] == '+' || Expressao[i+1] == '-')) {
                fprintf(file,"%c",'\n');
            }
            if(i!=0 && Expressao[i]=='('){
                fprintf(file,"%c",'\n');
            }
        }
        else{
            fprintf(file,"%c",Expressao[i]);
        }
    }
    fclose(file);
}

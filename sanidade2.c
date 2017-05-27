#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    struct no *anterior;
    unsigned long long conteudo;
    int teste;
    struct no *prox;

}tNo;
typedef struct lista{
    tNo *cabeca;
    int tamanho;
    tNo *fim;

}tLista;

void cria(tLista *list){
    list->cabeca = NULL;
    list->tamanho = 0;
    list ->fim = NULL;
}

int existe(tLista *list,unsigned long long valor){
    tNo *novoNO;
    if (list->tamanho == 0){
        return 0;
    }
    novoNO = list->cabeca;
    int i=1;
    while (i <= list->tamanho ){
        if (novoNO->conteudo == valor){
            return 1;
        }
        if (novoNO->prox ==NULL){
            break;
        }

        novoNO = novoNO->prox;
        i++;
    }
    return 0;

}

tNo* ponteiro(tLista *list,unsigned long long valor){
    tNo *ptr;
    ptr = list->cabeca;
    int i=1;
    while (i <= list->tamanho ){
        if (ptr->conteudo == valor){
            return ptr ;
        }
        if (ptr->prox == NULL){
            break;
        }
        ptr = ptr->prox;
        i++;
    }
    return NULL;

}

void inserirFrente(tLista *list, tNo *ptr ){
    tNo *p;
    if (list->tamanho==0){
        ptr->anterior=NULL;
        ptr->prox=NULL;
        list->cabeca=ptr;
        list->fim = ptr;
        list->tamanho++;
        return;
    }
    p = list->cabeca;
    ptr->anterior=NULL;
    ptr->prox=p;
    p->anterior=ptr;
    list->cabeca=ptr;
    list->tamanho++;
    return;
}

void inserirFim(tLista *list, tNo *ptr){
        ptr->prox = NULL;
        ptr->anterior = list->fim;
        list->fim->prox = ptr;
        list->fim = ptr;
        list->tamanho++;
        return;
}

void inserirNaFrente(tLista *list,tNo *frente,tNo *atras){
    if (atras->prox == NULL){
        inserirFim(list,frente);
        return;
    }
    frente->anterior = atras;
    frente->prox = atras->prox;
    atras->prox->anterior = frente;
    atras->prox = frente;
    list->tamanho++;
    return;
}

void inserirAtras(tLista *list,tNo *atras, tNo *frente){
    if (atras->anterior == NULL){
        inserirFrente(list,atras);
        return;
    }
    atras->prox = frente;
    atras->anterior = frente->anterior;
    frente->anterior->prox = atras;
    frente->anterior = atras;
    list->tamanho++;
    return;
}

void inserir(tLista *list, unsigned long long valorMeio,unsigned long long valorAntes,unsigned long long valorDepois){
    tNo *antes;
    tNo *meio;
    tNo *depois;
  /*********************************************************************************************************/
    if (valorAntes == 0){                           //se o valor for zero eh pq o ponteiro tem que ser NULL
        antes = NULL;
    }
    else if (existe(list,valorAntes)){                   //v se o elemento ja existe na lista se sim, ele
        antes = ponteiro(list,valorAntes);
    }
    else {
        antes =  malloc(sizeof(tNo));
        antes->conteudo=valorAntes;
        antes->teste=0;
    }
    /*********************************************************************************************************/
    if (valorDepois == 0){                          //se o valor for zero eh pq o ponteiro tem que ser NULL
        depois = NULL;
    }
    else if (existe(list,valorDepois)){
        depois = ponteiro(list,valorDepois);
    }
    else {
        depois =  malloc(sizeof(tNo));
        depois->conteudo=valorDepois;
        depois->teste=0;
    }
    /**********************************************************************************************************/
    if (existe(list,valorMeio)){
        meio = ponteiro(list,valorMeio);
    }
    else{
        meio = malloc(sizeof(tNo));
        meio->conteudo = valorMeio;
        meio->teste = 0;
    }
    /**********************************************************************************************************/
    if (existe(list,valorMeio)==1 && existe(list,valorDepois)==1 && existe(list,valorAntes)==1 ){
        meio->teste++;
        depois->teste++;
        antes->teste++;
        return;
    }
    if  (existe(list,valorMeio)==1 && existe(list,valorDepois)==1 && valorAntes==0){
        meio->teste++;
        depois->teste++;
        return;
    }
    if (existe(list,valorMeio)==1 && existe(list,valorAntes)==1 && valorDepois == 0){
        meio->teste++;
        antes->teste++;
        return;
    }
    if(existe(list,valorMeio)==1 && existe(list,valorDepois)==1 && existe(list,valorAntes)== 0){
        inserirAtras(list,antes,meio);
        meio->teste++;
        depois->teste++;
        return;
    }
    if(existe(list,valorMeio)==1 && existe(list,valorDepois)==0 && existe(list,valorAntes)== 1){
        inserirNaFrente(list,depois,meio);
        meio->teste++;
        antes->teste++;
        return;
    }
    if(valorAntes == 0){
        inserirFrente(list,meio);
        inserirNaFrente(list,depois,meio);
        return;
    }
    if  (existe(list,valorAntes)){
        inserirNaFrente(list,meio,antes);
        inserirNaFrente(list,depois,meio);
        antes->teste++;
        return;
    }

   if(valorDepois == 0){
        inserirFim(list,meio);
        inserirAtras(list,antes,meio);
        return;
    }
    if (existe(list,valorDepois)){
        inserirAtras(list,meio,depois);
        inserirAtras(list,antes,meio);
        depois->teste++;
        return;
    }

    else if (existe(list,valorMeio)){
        inserirAtras(list,antes,meio);
        inserirNaFrente(list,depois,meio);
        meio->teste++;
        return;
    }

    if (list->tamanho == 0){
        inserirFrente(list,antes);
        inserirFim(list,meio);
        inserirFim(list,depois);
        return;
    }
    if (existe(list,valorMeio)==0 && existe(list,valorDepois)==0 && existe(list,valorAntes)==0){
        inserirFim(list,antes);
        inserirFim(list,meio);
        inserirFim(list,depois);
    }

    return;
}

int teste (tLista *list){
    int i=2;
    tNo *noTeste;
    noTeste = list->cabeca->prox;
    if (list->cabeca->teste == 1 && list->fim->teste == 1){
        while (i < list->tamanho-1){
                if (noTeste->teste < 2)
                    return 1;
                noTeste = noTeste->prox;
                i++;
            }
            return 0;
        }
    return 1;
}
tNo *ptr1,*ptr2;
tLista *lst;

void sano(tLista *list){
    tNo *p;
    p = list->cabeca;
    while(1){
        if (p->conteudo == ptr1->conteudo){
            printf("sana\n");
            return;
        }
        else if (p->conteudo == ptr2->conteudo){
            printf("insana\n");
            return;
        }
        p = p->prox;

    }
}

int main(){
    lst = malloc(sizeof(tLista));
    cria(lst);
    unsigned long long a,b,c;
    scanf("%llx %llx %llx",&a,&b,&c);
    inserir(lst,a,b,c);
    ptr1 = ponteiro(lst,a);
    scanf("%llx %llx %llx",&a,&b,&c);
    inserir(lst,a,b,c);
    ptr2 = ponteiro(lst,a);
    while(teste(lst)){
        scanf("%llx %llx %llx",&a,&b,&c);
        inserir(lst,a,b,c);
    }
    sano(lst);
return 0;

}

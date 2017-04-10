#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
typedef struct no{
    int dado;    /* informação */
    struct no *prox; /* ponteiro para próximo nó */
}tNo;  /* tipo do nó */

typedef struct lista{
   struct no *cabeca;
   int tamanho;
}tLista;

void cria (tLista *lista);
int vazia (tLista lista);
int tamanho (tLista lista);
int elemento (tLista lista, int pos, int *dado );
int posicao (tLista lista, int dado);
int insere (tLista *lista, int pos, int dado );
int remov (tLista *lista, int pos, int *dado );
void imprimirSaida(tLista lista);
void imprimeLista(tLista lista) ;
int strc(char* a,char* b);
/*int insereInicioLista(tLista *lista, int valor);
int insereMeioLista(tLista *lista, int pos, int dado);
int inserirFimLista(tLista *lista, int dado);*/

int main(){

	tLista lista;
	char* operacao[10+1];
    int valor,quantidade;

	cria(&lista);

	printf("Tamanho lista: %d\n",lista.tamanho);/* Apagar depois*/

    scanf("%d",&quantidade);
    while (quantidade > lista.tamanho){


    scanf("%s",&operacao);
	/* Remoção no final da lista*/
	if (strcmp(operacao,"back") == 0){
        if (!vazia(lista)){
               remov(&lista, tamanho(lista), &valor);
               printf("%d\n", valor);
        }

        else
               printf("No job for Ada?\n");
	}
	else
	/* Remove no inicio da lista*/
	if (strcmp(operacao,"front") == 0){

        if (!vazia(lista)){
               remov(&lista, 1, &valor);
               printf("%d\n", valor);
        }

        else
               printf("No job for Ada?\n");
	}
    else
      /* Reverte a lista*/
    if (strcmp(operacao,"reverse")==0){
            imprimeLista(lista);
        int tam = lista.tamanho/2;
        int j=lista.tamanho;
        int aux;
        for(aux = 0; aux<tam; aux++,j--){
            int temporario, temporario2;
            remov(&lista, j,&temporario);
            remov(&lista, aux+1,&temporario2);
            insere(&lista, aux+1,temporario);
            insere(&lista, j,temporario2);
        }
        imprimeLista(lista);
    }
    else
    /* Adiciona no final da lista*/
    if (strcmp(operacao,"push_back")==0){
        scanf(" %d",&valor);
        insere(&lista,tamanho(lista)+1,valor);
    }
    else
    /* Adiciona no incio da lista*/
    if (strcmp(operacao, "toFront")==0){
        scanf(" %d",&valor);
        insere(&lista,1,valor);
    }
    printf("Tamanho lista: %d\n",lista.tamanho);

    imprimeLista(lista);

}

    getchar();

	return 0;
}

void imprimeLista(tLista lista) {
    int dado=0,tamLista = tamanho(lista),i=0;

    if (vazia(lista)==1){
        printf("empty\n");
        return;
    }

    for(i = 1; i <= tamLista; i++)
    {
      elemento (lista, i, &dado);
      printf("%d ",dado);
    }

    printf("\n");




}

void imprimirSaida(tLista lista){

	if (vazia(lista)){

		printf("No job for Ada?\n");

	}

	else{

		tNo *listaCabeca = lista.cabeca;
		/*printf("Tamanho da lista: %d\n",lista.tamanho);*/
		while (listaCabeca != NULL){

			printf("%d ", listaCabeca->dado );
			listaCabeca = listaCabeca->prox;
		}

		printf("\n");


	}

}


/**Cria uma Lista vazia */
void cria (tLista *lista) {
    lista->cabeca = NULL;
    lista->tamanho = 0;
}

/** Verifica se a Lista está vazia */
int vazia (tLista lista) {
    if (lista.tamanho == 0)
        return 1;
    else
        return 0;
}

/**Obtém o tamanho da Lista*/
int tamanho (tLista lista) {
    return lista.tamanho;
    /* ou
 	  tNo *p = lista.cabeca;
	  int qtde = 0;
	  while(p != NULL){
		  p = p-> prox;
		  qtde++;
	  }
	  return qtde;
    */
}

/* Reverte a Lista*/
/*
tLista reverse (tLista lista){
    lista nova=lista;
    atual = mulaFinal;
    mulaFinal = NULL;
    while (atual != NULL) {
       nova = atual->next;
       atual->next = mulaFinal;
       mulaFinal = atual;
       atual = nova;
    }
    return mulaFinal;
}
 */

/** Obtém o i-ésimo elemento de uma lista
    Retorna 0 se a posição passada for inválida,
    caso contrário 1. O parâmetro dado irá receber
    o elemento encontrado*/
int elemento (tLista lista, int pos, int *dado ) {
    tNo *p;
    int n = 1;

    /* Lista vazia */
    if (lista.cabeca == NULL) {
            return 0;
    }

    /* Percorre a lista do 1o elemento até pos */
    p = lista.cabeca;
    while ((p != NULL) && (n < pos)){
        /* modifica "p" para apontar para o proximo elemento da lista */
        p = p-> prox;
        n++;
    }

    /* Caso chegue-se ao final da lista, pos eh invalida */
	 if (p == NULL) {
            return 0;
     }

    *dado = p->dado;
    return 1;
}

/** Retorna a posição de um elemento pesquisado.
    Retorna 0 caso não seja encontrado */
int posicao (tLista lista, int dado) {
    int n = 1;
    tNo *p;

    /* Lista vazia */
    if ( lista.cabeca == NULL) {
            return 0;
    }

    /* Percorre a lista do inicio ao fim até encontrar o elemento*/
    p = lista.cabeca;
	while (p != NULL) {
        /* Se encontrar o elemento, retorna sua posicao n;*/
        if (p->dado == dado){
            return n;
        }

        /* modifica "p" para apontar para o proximo elemento da lista */
        p = p->prox;
        n++;
    }

    return 0;
}

/** Insere nó em lista vazia */
int insereInicioLista(tLista *lista, int valor) {
    tNo *novoNo;

    /* Aloca memoria para novo no */
    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL) { /* mem. insuf. */
		 return 0;
    }

    /* Insere novo elemento na cabeca da lista */
    novoNo->dado = valor;
    novoNo->prox = lista->cabeca;
    lista->cabeca = novoNo;
    lista->tamanho++;
    return 1;
}

/** Insere nó no meio da lista */
int insereMeioLista(tLista *lista, int pos, int dado){
    tNo *p, *novoNo;

    int n = 1;
    /* Localiza a pos. onde será inserido o novo nó */
    p = lista->cabeca;
    while ((n < pos-1) && (p != NULL)){
          p = p->prox;
          n++;
    }

    if (p == NULL) {  /* pos. inválida */
            return 0;
    }

    /* Aloca memoria para novo no */
    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL) { /* mem. insuf. */
		 return 0;
    }

    /* Insere novo elemento apos p */
    novoNo->dado = dado;
    novoNo->prox = p->prox;
    p->prox = novoNo;
    lista->tamanho++;

    return 1;
}

/** Insere nó no fim da lista */
int insereFimLista(tLista *lista, int dado){
    tNo *novoNo;

    /* Aloca memoria para novo no */
    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL) { /* mem. insuf. */
		 return 0;
    }

    novoNo->dado = dado;

    /* Procura o final da lista */
    tNo *ult = lista->cabeca;
    while(ult->prox != NULL){
        ult = ult->prox;
    }

    ult->prox = novoNo;
    novoNo->prox = NULL;
    lista->tamanho++;

    return 1;
}


/**Insere um elemento em uma determinada posição
    Retorna 0 se a lista estiver cheia ou
    a posição for inválida. Caso contrário retorna 1 */
int insere(tLista *lista, int pos, int dado ) {
    /*tNo *p, *novoNo;*/
    int  ret, tamanho = lista->tamanho;

 	/* inserção no início da lista (ou lista vazia)*/
    if ((vazia(*lista)) || (pos == 1)){
        ret = insereInicioLista(lista, dado);
        return ret;
    }
    /* inserção no fim da lista */
    /*alterei, coloquei o igual*/
    else if (pos >= tamanho+1){
        ret = insereFimLista(lista, dado);
        return ret;
   }
   /* inserção no meio da lista */
   else{
        ret = insereMeioLista(lista, pos, dado);
        return ret;
   }
}

/** Remove elemento do início da lista */
int removeInicioLista(tLista *lista, int *dado){
    tNo *p = lista->cabeca;

    /* dado recebe o dado removido*/
    *dado = p->dado;

    /* retira o 1o elemento da lista (p)*/
    lista->cabeca = p->prox;
    lista->tamanho--;

    /* libera a memoria da regiao apontada por p*/
    free(p);

    return 1;
}


/** Remove elemento no meio da lista */
int removeNaLista(tLista *lista, int pos, int *dado){
     tNo *aux, *p;
     int n = 1;

     /* Localiza o nó que será removido*/
     p = lista->cabeca;
     while((n < pos) && (p != NULL)){
           aux = p;
           p = p->prox;
           n++;
     }

     if (p == NULL) { /* pos. inválida */
        return (0);
     }

    /* retira o elemento da lista */
    *dado = p->dado;
     aux->prox = p->prox;
     lista->tamanho--;

    /* libera a memoria da regiao apontada por p*/
     free(p);
     return 1;
}

/**Remove um elemento de uma determinada posição
    Retorna 0 se a posição for inválida ou a lista
    estiver vazia. Caso contrário retorna 1 */
int remov (tLista *lista, int pos, int *dado ) {
    int  ret;

    /* Lista vazia */
    if (vazia(*lista)) {
            return 0;
    }

    /*remoção do elemento da cabeça da lista */
    if (pos == 1){
        ret = removeInicioLista(lista, dado);
        return ret;
    }
    /* remoção em outro lugar da lista*/
    else{
        ret = removeNaLista(lista, pos, dado);
        return ret;
    }
}


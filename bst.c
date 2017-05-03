#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int conteudo;  	 /* conteudo */
	struct  no *esq; /* ref. para filho da esquerda */
	struct  no *dir; /* ref. para filho da direita  */
} tNo;       /* tipo do nó */

typedef tNo *tArvBin; /* tipo árvore binária */

void cria (tArvBin *T);
int vazia (tArvBin T);
tArvBin busca(tArvBin T, int dado);
int insereRaiz(int dado, tArvBin *T);
int insereDireita(tArvBin T, int vPai, int vFilho );
int insereEsq(tArvBin T, int vPai, int vFilho );

void exibePreOrdem(tArvBin T);
void exibeInOrdem(tArvBin T);
void exibePosOrdem(tArvBin T);
int insere(tArvBin *T, int dado);








int main()
{
    int c=0;
    tArvBin arv;
    tArvBin no;
    printf("Arvores Binarias!\n");

    cria(&arv);
    if (c = 0){
            scanf("%d", &no->conteudo);
            insereRaiz(no, &arv);
            c=c+1;
            if(arv->conteudo> no){
                arv->esq = insereEsq(arv, arv->conteudo, no);
            else arv->dir = insereDireita(arv,arv->conteuo,no);
            }
    }












    printf("Pre-ordem \n");
    exibePreOrdem(arv);

    printf("\nIn-ordem \n");
    exibeInOrdem(arv);

    printf("\nPos-ordem \n");
    exibePosOrdem(arv);

    return 0;
}

















/**Cria uma árvore vazia */
void cria (tArvBin *T) {
	*T = NULL;
}

/**Verifica se a árvore está vazia*/
int vazia (tArvBin T) {
    if (T == NULL)
        return 1;
    else
        return 0;
}

/**Buscar um elemento na árvore
    Retorna o endereço se o elemento for
    encontrado, caso contrário retorna NULL*/
tArvBin busca(tArvBin T, int dado) {
	tArvBin achou;
	if (T == NULL)
		return NULL;  /* Arvore Vazia*/

	if(T->conteudo == dado)
		return T; /*Elem. encontrado na raiz*/

	achou = busca(T->esq, dado); /* Tenta na sub-arv da esq */
	if (achou == NULL)
		achou = busca(T->dir, dado); /* Tenta na sub-arv da dir */

	return achou;
}

/** Insere um nó raiz em uma árvore vazia
    Retorna 1 se a inserção for com sucesso.
    Caso contrário 0 */
int insereRaiz(int dado, tArvBin *T) {
	tNo *novoNo;
	if (*T != NULL)
		return 0;  /*Erro: árvore não está vazia*/

	novoNo = malloc(sizeof(tNo));
	if (novoNo == NULL)
        return 0;  /*Err: mem.  Insuf. */

	novoNo->conteudo = dado;
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	*T = novoNo;
	return 1;
}

/** Insere um filho à direita de um dado nó
    Retorna 1 se a inserção for com sucesso,
    Caso contrário 0  */
int insereDireita(tArvBin T, int vPai, int vFilho ) {
	tNo *f, *p, *novoNo;
	/*Verifica se o elemento já existe*/
	f = busca(T, vFilho);
	if (f != NULL)
        return 0;  /*Err: dado já existe*/

	/*Busca o pai e verifica se possui filho direito*/
	p = busca(T, vPai);
  	if (p == NULL)
		return 0; /*Err: pai não encontrado*/
	if (p->dir != NULL)
		return 0; /*Err: filho dir já existe*/

	novoNo = malloc(sizeof(tNo));
	if (novoNo == NULL)
		return (0);  /*Err: mem. insuf.*/

	novoNo->conteudo = vFilho;
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	p->dir = novoNo;
	return 1;
}

/**Insere um filho à esquerda de um dado nó
    Retorna 1 se a inserção for com sucesso, caso contrário 0*/
int insereEsq(tArvBin T, int vPai, int vFilho ) {
	tNo *f, *p, *novoNo;
	/*Verifica se o elemento já existe*/
	f = busca(T, vFilho);
	if (f != NULL)
        return 0;  /*Err: dado já existe*/

	/*Busca o pai e verifica se possui filho da esq*/
	p = busca(T, vPai);
  	if (p == NULL)
		return 0; /*Err: pai não encontrado*/
	if (p->esq != NULL)
		return 0; /*Err: filho esq já existe*/

	novoNo = malloc(sizeof(tNo));
	if (novoNo == NULL)
		return 0;  /*Err: mem. insuf.*/

	novoNo->conteudo = vFilho;
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	p->esq = novoNo;
	return 1;
}

/**Exibe o conteúdo de uma árvore em pré-ordem*/
void exibePreOrdem(tArvBin T) {
	if (T == NULL)
		return ;

	printf("%d   ", T->conteudo);
	if (T->esq != NULL)
		exibePreOrdem(T->esq);

 	if (T->dir != NULL)
		exibePreOrdem(T->dir);
}

/**Exibe o conteúdo de uma árvore em pré-ordem*/
void exibeInOrdem(tArvBin T) {
	if (T == NULL)
		return ;

	if (T->esq != NULL)
		exibeInOrdem(T->esq);

    printf("%d   ", T->conteudo);

 	if (T->dir != NULL)
		exibeInOrdem(T->dir);

}

/**Exibe o conteúdo de uma árvore em pré-ordem*/
void exibePosOrdem(tArvBin T) {
	if (T == NULL)
		return ;

	if (T->esq != NULL)
		exibePosOrdem(T->esq);
	if (T->dir != NULL)
		exibePosOrdem(T->dir);

	printf("%d   ", T->conteudo);
}

/**Insere um nó em uma árvore ABP
    Retorna 1 se a inserção for com sucesso.
    Caso contrário retorna 0*/
int insere(tArvBin *T, int dado){
	tNo *novoNo, *aux, *p;

	novoNo = malloc(sizeof(tNo));
	if (novoNo == NULL)
        return 0;

	novoNo->conteudo = dado;
	novoNo->esq = NULL;
	novoNo->dir = NULL;

	if (*T == NULL){ /* Arvore vazia*/
 		*T = novoNo;
		return 1;
	}
}

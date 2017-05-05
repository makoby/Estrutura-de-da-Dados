#include <stdio.h>
#include <stdlib.h>

typedef struct no{

	int conteudo; //conteudo do no
	struct no *esq; // filho da esquerda
	struct no *dir; // filho da direita

}tNo;
static int c = 0;

// inserir nÑ raiz em uma arvore vazia
//retorna 1 se inserido se nao 0
void  insere (tNo **arv, int dado){
	tNo *novoNo, *aux, *p;

	novoNo = (tNo*)malloc(sizeof (tNo));

	if (*arv == NULL){
	novoNo ->conteudo = dado;
	novoNo ->esq = NULL;
	novoNo ->dir = NULL;
	*arv = novoNo;
}
else if ((*arv )-> conteudo < dado) {
       c++;
       /**/
	   insere (&(*arv )-> dir, dado);
	   printf("entrei no no da direita e c vale:%d\n",c);

}
else if ((*arv )->conteudo > dado) {
	c++;
	/**/
	insere (&(*arv ) -> esq, dado);
	printf("entrei no no da esquerda e c vale:%d\n",c);
	}
}



int main(){

	long operacao;

	tNo *arvore = NULL;
	scanf("%ld", &operacao);

	while(operacao>0 && operacao<300001){
		int dadotemporario;
		scanf("%d", &dadotemporario);
	    insere (&arvore, dadotemporario);
	    printf("%d\n",c);
        operacao--;
	}

	return 0;
}

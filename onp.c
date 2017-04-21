/* Fiz essa questao com o Mateus*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct divisor{
    struct divisor *baixo;
    char caractere;
}tDivisor;

typedef struct pilha{
    tDivisor *topo;
}tPilha;

void criaPilha(struct pilha *pilha){
     pilha->topo = NULL;
}

void pop(tPilha *p, int onAndOff){ // A varíavel, onAndOff, é uma flag/um interruptor.
    if(p->topo != NULL && onAndOff == 1){
        printf("%c", p->topo->caractere);
        tDivisor *apaga = p->topo;
        p->topo = p->topo->baixo;
        free(apaga);
    }else if(p->topo != NULL && onAndOff == 0){
        tDivisor *apaga = p->topo;
        p->topo = p->topo->baixo;
        free(apaga);
    }
}

void push(tPilha *pilha, char c){
    tDivisor *empilha = malloc(sizeof(tDivisor));
    empilha->caractere = c;
    if(pilha->topo == NULL){
        empilha->baixo = NULL;
        pilha->topo = empilha;
    }else{
        empilha->baixo = pilha->topo;
        pilha->topo = empilha;
    }
}

int Operador(char c){
    if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
        return 1;

    return 0;
}

int main(){
    char str[401];
    int qnt, tam, i;
    tPilha par, op;

    criaPilha(&par);
    criaPilha(&op);

    scanf("%d", &qnt);
    fflush(stdin);

    while(qnt--){
        scanf("%s", str);
        tam = strlen(str);

        for(i = 0; i < tam; i++){
            if(str[i] == '('){
                push(&par, '(');
            }else if(str[i] == ')'){
                pop(&op, 1);
            }else if(Operador(str[i])){
                push(&op, str[i]);
            }else{
                printf("%c", str[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

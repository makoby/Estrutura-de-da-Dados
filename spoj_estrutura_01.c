#include <stdio.h>
 
int main(void) {

	int sTamanho;
	int qTamanho;
	int i,achou = 0;
	int *s,*q,*d;

	 /*printf("Digite o tamanho da sequencia ordenada s\n");*/
	scanf("%d",&sTamanho);
    /*printf("O tamanho da primeira sequencia ordenada é: %d \n",sTamanho);*/

	s = (int*)malloc( sTamanho * sizeof (int) );

    /*printf("Digite a sequencia ordenada de tam: %d\n",sTamanho);*/

    for(i = 1; i <= sTamanho; i++)
    {
      scanf("%d", &s[i-1]);
    }



	/*printf("\nDigite o tamanho da sequencia ordenada q\n");*/
	scanf("%d",&qTamanho);
	/*printf("O tamanho da segunda sequencia ordenada é: %d \n",qTamanho);*/

	q = (int*)malloc( qTamanho * sizeof (int) );

    /*printf("Digite a sequencia ordenada de tamanho: %d\n",qTamanho);*/

     for(i = 1; i <= qTamanho; i++)
    {
      scanf("%d", &q[i-1]);
    }

    d = (int*)malloc( sTamanho * sizeof (int) );
    int k = 0;
    int j = 0;
    for(i=0;i<sTamanho;i++){
        achou = 0;
        for(j = 0;j<qTamanho;j++){

            if(q[j] <= s[i]){

                if(q[j] == s[i]){
                    achou = 1;
                    break;
                }

            }else{
                break;
            }
        }

        if(achou == 0){
            d[k] = s[i];
            k++;
        }
    }

    for(i=0;i<k;i++){
        if(i == k-1){
            printf("%d",d[i]);
        }else{
            printf("%d ",d[i]);
        }

    }

    printf("\n");

    getchar();

	return 0;
}

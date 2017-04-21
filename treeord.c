#include <stdio.h>
int main(){
  int N;
  int item;
  int arvore1[8000], arvore2[8000], arvore3[8000];

  scanf("%d", &N);

  for(int i = 0; i < N; i++){

    scanf("%d",&item);
    arvore1[i] = item;
  }
  for (int i = 0; i < N; i++) {

    scanf("%d",&item);
    arvore2[i] = item;
  }

  for (int i = 0; i < N; i++) {
    scanf("%d",&item);
    arvore3[i] = item;
  }

  if(arvore1[0] == arvore2[N-1] && arvore1[N-1] == arvore3[N-1]){
    printf("yes\n");
  }
  else{
    printf("no\n");
  }
    return 0;
}

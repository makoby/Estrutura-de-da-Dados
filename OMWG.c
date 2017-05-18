#include <stdio.h>

int main(){

	int T;
	scanf("%d", &T);

	while (T--){
		int N, M;
		scanf("%d ", &N);
		scanf("%d", &M);
		printf("%d \n", 2*M*N-N-M);
	}

	return 0;

}

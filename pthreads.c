#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main () {
	int n_valores = 0, n_threads = 0;
	printf("Digite a quantidade de números a processar: ");
	scanf("%d", &n_valores);
	printf("Digite a quantidade de threads a criar: ");
	scanf("%d", &n_threads);
	// O número total de números primos encontrados foi: 5
	return 1;
}
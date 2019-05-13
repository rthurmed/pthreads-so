#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *primo(void *args) {
	// Thread 0: O número 1 é primo
}

int main () {
	int n_valores = 0, n_threads = 0;
	pthread_t* threads = (pthread_t *) malloc(sizeof(pthread_t)) ;
	printf("Digite a quantidade de números a processar: ");
	scanf("%d", &n_valores);
	printf("Digite a quantidade de threads a criar: ");
	scanf("%d", &n_threads);
	threads = (pthread_t *) realloc(threads, n_threads * sizeof(pthread_t));
	// O número total de números primos encontrados foi: 5
	return 1;
}
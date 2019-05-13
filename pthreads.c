#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *primo(void *args) {
	int id = 0; // Vai receber dos argumentos
	int valor = 3; // Vai pegar do espaço compartilhado
	int i = 2;
    while (i < valor && valor%i != 0) i++;
    if(i == valor) printf("Thread %d: O número %d é primo.\n", id, valor);
    else printf("Thread %d: O número %d não é primo.\n", id, valor);
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
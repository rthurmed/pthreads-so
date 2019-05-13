// ARTHUR MEDEIROS, BRUNO POHREN

// Usar "-lpthread"
// gcc pthreads.c -o pthreads -lpthread && ./pthreads 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int primo(int value) {
	int i = 2;
	while (i < value && value%i != 0) i++;
	return i == value;
} 

void *thread_fn(void *threadid) {
	int *id = (int*) threadid;
	int valor = 3; // Vai pegar do espaço compartilhado
    if(primo(valor)) printf("Thread %d: O número %d é primo.\n", *id, valor);
    else printf("Thread %d: O número %d não é primo.\n", *id, valor);
}

int main () {
	int n_valores = 0, 
		n_threads = 0,
		i = 0;

	int* args = (int *) malloc(sizeof(int));
	pthread_t* threads = (pthread_t *) malloc(sizeof(pthread_t));
	
	printf("Digite a quantidade de números a processar: ");
	scanf("%d", &n_valores);
	printf("Digite a quantidade de threads a criar: ");
	scanf("%d", &n_threads);

	args = (int *) realloc(args, n_threads * sizeof(int));
	threads = (pthread_t *) realloc(threads, n_threads * sizeof(pthread_t));
	for (i = 0; i < n_threads; i++) {
		args[i] = i;
		pthread_create(&(threads[i]), NULL, thread_fn, &(args[i]));
	}
	for (i = 0; i < n_threads; i++) {
		pthread_join(threads[i], NULL);
	}
	
	// O número total de números primos encontrados foi: 5
	return 1;
}
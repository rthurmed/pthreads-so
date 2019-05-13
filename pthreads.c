// ARTHUR MEDEIROS, BRUNO POHREN

// Usar "-lpthread"
// gcc pthreads.c -o pthreads -lpthread && ./pthreads 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;

int n_primos = 0;
int atual = 1;
int max = 10;
int qtd_threads = 0;

int primo(int value) {
	int i = 2;
	while (i < value && value%i != 0) i++;
	return i == value;
} 

void *thread_fn(void *threadid) {
	int *id = (int*) threadid; // Vem como argumento da thread
	int valor = 0; // Pega do espaço compartilhado
	while (atual <= max) {
		pthread_mutex_lock(&lock);
		valor = atual;
		atual++;
		pthread_mutex_unlock(&lock);
		if(primo(valor)) {
			printf("Thread %d: O número %d é primo.\n", *id, valor);
			pthread_mutex_lock(&lock);
			n_primos++;
			pthread_mutex_unlock(&lock);
		} else {
			printf("Thread %d: O número %d não é primo.\n", *id, valor);
		}
	}
}

int main () {
	int n_valores = 0, 
		n_threads = 0,
		i = 0;

	int* args = (int *) malloc(sizeof(int));
	pthread_t* threads = (pthread_t *) malloc(sizeof(pthread_t));
	
	pthread_mutex_init(&lock, NULL);

	printf("Digite a quantidade de números a processar: ");
	scanf("%d", &n_valores);
	printf("Digite a quantidade de threads a criar: ");
	scanf("%d", &n_threads);

	max = n_valores;
	qtd_threads = n_threads;
	args = (int *) realloc(args, n_threads * sizeof(int));
	threads = (pthread_t *) realloc(threads, n_threads * sizeof(pthread_t));
	for (i = 0; i < n_threads; i++) {
		args[i] = i;
		pthread_create(&(threads[i]), NULL, thread_fn, &(args[i]));
	}
	for (i = 0; i < n_threads; i++) {
		pthread_join(threads[i], NULL);
	}
	
	pthread_mutex_destroy(&lock);
	
	printf("O número total de números primos encontrados foi: %d", n_primos);
	return 1;
}
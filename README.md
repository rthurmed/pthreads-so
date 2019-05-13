# pthreads-so
Trabalho da cadeira de Sistemas Operacionais

Enunciado:
O trabalho da disciplina de Sistemas Operacionais no semestre 2019/1 será sobre o uso da biblioteca pthreads para implementação de um programa multithread para calcular quais números dentro de uma faixa são primos ou não.
- Os trabalhos poderão ser feitos em dupla ou individualmente;
- No início da execução, o programa deverá solicitar do usuário a faixa de números que serão verificados (N) e o número de threads a serem criadas para processar em paralelo (T);
- Cada thread processará um número dentro da faixa indicada de cada vez, em ordem sequencial, de 1..N;
- Será necessária uma variável compartilhada para indicar qual o próximo número a ser processado pela próxima thread disponível, e outra para armazenar o número total de números primos que foram encontrados;
- A cada processamento, cada thread deverá imprimir mensagem com seu ID, e informando se o número que acabou de processar é primo ou não;
- Ao final do processamento, o programa principal deverá imprimir o número total de números primos encontrados;
- Exemplo: 
```
(início da execução)
Digite a quantidade de números a processar: 10
Digite a quantidade de threads a criar: 3
Thread 0: O número 1 é primo
Thread 1: O número 2 é primo
Thread 2: O número 3 é primo
Thread 0: O número 4 não é primo
Thread 1: O número 5 é primo
Thread 2: O número 6 não é primo
Thread 0: O número 7 é primo
Thread 1: O número 8 não é primo
Thread 2: O número 9 não é primo
Thread 0: O número 10 não é primo
O número total de números primos encontrados foi: 5
(fim da execução)
```
- A data de apresentação do trabalho será 14/05/2019.

#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio, fim;
    double tempoDecorrido;

    inicio = clock();

    // Seu código aqui

    fim = clock();

    tempoDecorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo decorrido: %.2f segundos\n", tempoDecorrido);

    return 0;
}

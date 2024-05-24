#include <stdio.h>

void inverterArray(int *array, int tamanho) {
    int *inicio = array;
    int *fim = array + tamanho - 1;

    while (inicio < fim) {
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(array) / sizeof(int);

    inverterArray(array, tamanho);

    printf("Array invertido: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

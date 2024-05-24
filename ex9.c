#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort
int comparar(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

float calcularMedia(int *array, int tamanho) {
  float soma = 0;
  for (int i = 0; i < tamanho; i++) {
    soma += array[i];
  }
  return soma / tamanho;
}

float calcularMediana(int *array, int tamanho) {
  qsort(array, tamanho, sizeof(int), comparar);
  if (tamanho % 2 == 0) {
    return (array[tamanho / 2 - 1] + array[tamanho / 2]) / 2.0;
  } else {
    return array[tamanho / 2];
  }
}

int calcularModa(int *array, int tamanho) {
  int moda = array[0];
  int frequencia = 1;
  int maxFrequencia = 1;

  for (int i = 1; i < tamanho - 1; i++) {
    if (array[i] == array[i - 1]) {
      frequencia++;
    } else {
      if (frequencia > maxFrequencia) {
        maxFrequencia = frequencia;
        moda = array[i - 1];
      }
      frequencia = 1;
    }
  }

  return moda;
}

int main() {
  int array[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
  int tamanho = sizeof(array) / sizeof(int);

  float media = calcularMedia(array, tamanho);
  float mediana = calcularMediana(array, tamanho);
  int moda = calcularModa(array, tamanho);

  printf("Média: %.2f\n", media);
  printf("Mediana: %.2f\n", mediana);
  printf("Moda: %d\n", moda);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  int idade;
} Pessoa;

int compararIdade(const void *a, const void *b) {
  return ((Pessoa *)a)->idade - ((Pessoa *)b)->idade;
}

int main() {
  Pessoa pessoas[] = {{"Alice", 25}, {"Bob", 30}, {"Carol", 20}};
  int numPessoas = sizeof(pessoas) / sizeof(Pessoa);

  qsort(pessoas, numPessoas, sizeof(Pessoa), compararIdade);

  printf("Pessoas ordenadas por idade:\n");
  for (int i = 0; i < numPessoas; i++) {
    printf("%s - %d anos\n", pessoas[i].nome, pessoas[i].idade);
  }

  return 0;
}

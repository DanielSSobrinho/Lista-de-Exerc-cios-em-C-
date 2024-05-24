#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  int idade;
  float salario;
} Funcionario;

void adicionarRegistro(FILE *arquivo) {
  Funcionario novoFuncionario;
  printf("Nome, idade e salário do novo funcionário: ");
  scanf("%s %d %f", novoFuncionario.nome, &novoFuncionario.idade,
        &novoFuncionario.salario);
  fwrite(&novoFuncionario, sizeof(Funcionario), 1, arquivo);
  printf("Funcionário adicionado!\n");
}

void listarRegistros(FILE *arquivo) {
  Funcionario funcionario;
  rewind(arquivo);
  printf("\nLista de Funcionários:\n");
  while (fread(&funcionario, sizeof(Funcionario), 1, arquivo))
    printf("%s - %d anos - R$ %.2f\n", funcionario.nome, funcionario.idade,
           funcionario.salario);
  printf("\n");
}

void buscarPorNome(FILE *arquivo) {
  char nomeBusca[50];
  printf("Digite o nome para busca: ");
  scanf("%s", nomeBusca);

  Funcionario funcionario;
  int encontrado = 0;

  while (fread(&funcionario, sizeof(Funcionario), 1, arquivo))
    if (strcmp(funcionario.nome, nomeBusca) == 0) {
      printf("%s - %d anos - R$ %.2f\n", funcionario.nome, funcionario.idade,
             funcionario.salario);
      encontrado = 1;
    }

  if (!encontrado)
    printf("Nenhum funcionário encontrado com o nome '%s'.\n", nomeBusca);
}


int main() {
  FILE *arquivo = fopen("funcionarios.bin", "ab+");
  if (arquivo == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo.\n");
    exit(1);
  }

  int opcao;
  do {
    printf("\nMenu:\n1. Adicionar funcionário\n2. Listar todos\n3. Buscar por "
           "nome\n0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      adicionarRegistro(arquivo);
      break;
    case 2:
      listarRegistros(arquivo);
      break;
    case 3:
      buscarPorNome(arquivo);
      break;
    case 0:
      printf("Até logo!\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao != 0);

  fclose(arquivo);
  return 0;
}

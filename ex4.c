#include <stdio.h>
#include <stdlib.h>

double **alocarMatriz(int rows, int cols) {
  double **matriz = malloc(rows * sizeof(double *));
  for (int i = 0; i < rows; i++)
    matriz[i] = malloc(cols * sizeof(double));
  return matriz;
}

void liberarMatriz(double **matriz, int rows) {
  for (int i = 0; i < rows; i++)
    free(matriz[i]);
  free(matriz);
}

double **multiplicarMatrizes(double **matriz1, int rows1, int cols1,
                             double **matriz2, int rows2, int cols2) {
  double **resultado = alocarMatriz(rows1, cols2);
  for (int i = 0; i < rows1; i++)
    for (int j = 0; j < cols2; j++)
      for (int k = 0; k < cols1; k++)
        resultado[i][j] += matriz1[i][k] * matriz2[k][j];
  return resultado;
}

double **transporMatriz(double **matriz, int rows, int cols) {
  double **transposta = alocarMatriz(cols, rows);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      transposta[j][i] = matriz[i][j];
  return transposta;
}

void imprimirMatriz(double **matriz, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      printf("%.2f\t", matriz[i][j]);
    printf("\n");
  }
}

int main() {

  double **matriz1 = alocarMatriz(3, 2), **matriz2 = alocarMatriz(2, 4);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      matriz1[i][j] = i + j;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 4; j++)
      matriz2[i][j] = i - j;

  printf("Matriz 1:\n");
  imprimirMatriz(matriz1, 3, 2);
  printf("\nMatriz 2:\n");
  imprimirMatriz(matriz2, 2, 4);

  double **resultado = multiplicarMatrizes(matriz1, 3, 2, matriz2, 2, 4);
  printf("\nResultado da multiplicação:\n");
  imprimirMatriz(resultado, 3, 4);

  double **transposta = transporMatriz(matriz1, 3, 2);
  printf("\nTransposta da matriz 1:\n");
  imprimirMatriz(transposta, 2, 3);

  liberarMatriz(matriz1, 3), liberarMatriz(matriz2, 2);
  liberarMatriz(resultado, 3), liberarMatriz(transposta, 2);

  return 0;
}

#include <ctype.h>
#include <stdio.h>

char *converterParaMaiusculas(char *str) {
  char *ptr = str;
  while (*ptr != '\0') {
    *ptr = toupper(*ptr);
    ptr++;
  }
  return str;
}

int main() {
  char string[] = "tring para teste!";
  printf("string original: %s\n", string);

  char *resultado = converterParaMaiusculas(string);
  printf("string convertida para maiúsculas: %s\n", resultado);

  return 0;
}

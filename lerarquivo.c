#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
  int id;
  char nome[60];
};

typedef struct aluno aln;

int main(int argc, char *argv[]) {

  FILE *arq;
  char Linha[100];
  char *result, *teste;
  int i;

  arq = fopen("nomes.txt", "rt");
  if (arq == NULL) 
  {
     printf("Problemas na abertura do arquivo\n");
     return 0;
  }
  
  i = 1;
  while (!feof(arq))
  {
    result = fgets(Linha, 100, arq);

    teste = strtok(Linha, ";");
	  printf("%s\n", teste);

    teste = strtok(NULL, ";");
    printf("%s\n", teste);
    
    i++;
  }
  
  fclose(arq);
  
}
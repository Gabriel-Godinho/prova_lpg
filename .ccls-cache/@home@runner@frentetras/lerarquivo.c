#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
  int id;
  char nome[60];
};

typedef struct aluno aln;

void relatorio(){};

void consulta(){};

int main(int argc, char *argv[]) {

  FILE *arq;
  aln listaAlunos[25];
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

    aln al;
    
    result = fgets(Linha, 100, arq);

    teste = strtok(Linha, ";");
	  printf("%s\n", teste);
    al.id = (long int)teste;

    teste = strtok(NULL, ";");
    printf("%s\n", teste);
    strcpy(al.nome, teste);

    listaAlunos[i] = al;
    
    i++;
  }
  
  fclose(arq);
  
}
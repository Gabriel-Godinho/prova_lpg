#include <stdio.h>
#include <stdlib.h>

struct aluno {
  int id;
  char nome[60];
};

typedef struct aluno aln;

int main() {

  aln a[25];
  int id;
  char nome[50];

  FILE *arquivo = fopen("nomes.txt", "r");

  if (arquivo == NULL)
    printf("Falha ao abrir o arquivo!");

  while(fscanf(arquivo, "%d;%[^;]", &id, nome) == 2) {

    


    
  }

  


  
}
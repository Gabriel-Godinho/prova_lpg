#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#define MAXCHAR 1000

typedef struct a {

  char nome[60];
  int id;

} aluno;

// Consultar por id
void consultarAluno(int tamanho, aluno als[10]) {
  int i, cod;
  printf("\n\tCódigo do aluno: ");
  scanf("%d", &cod);
  
  for (i = 0; i < tamanho; i++) {
    if (als[i].id == cod) {
      printf("\tNome: %s\n\n", als[i].nome);
      break;
    }
  }
}

// RelatÃ³rio alunos
void relatorioAlunos(int tamanho, aluno als[10]) {
  int i;
  
  printf("\t|--------------------------------------------------------|\n");
  printf("\t                         Relatório\n");
  printf("\t---------------------------------------------------------|\n");
  printf("\t|--------------------------------------------------------|\n");
  printf("\t|  ID  | Nome                                            |\n");
  printf("\t|------|-------------------------------------------------|\n");
  for (i = 0; i < tamanho; i++) {
    
    if (als[i].id <= 0)
      break; // Quando os alunos acabarem o loop acabada
    
    printf("\t|  %d  | %s                                              |\n", als[i].id, als[i].nome);
    printf("\t|------|-------------------------------------------------|\n");
  }

  printf("\t|--------------------------------------------------------|\n");
}

int main() {
  
  int option ;
  FILE * fp;
  char row[MAXCHAR];
  char * token;
  aluno listaAlunos[510];
  int i = 0;

  int tamanhoListaAlunos = sizeof(listaAlunos)/sizeof(listaAlunos[0]); // Tamanho da lista de alunos

  fp = fopen("nomes.txt","r");


    while (feof(fp) != true)
    {

        aluno a;
        fgets(row, MAXCHAR, fp);

        token = strtok(row, ";");
        a.id = atoi(token);

        while(token != NULL)
        {
            strcpy(a.nome, token);
            token = strtok(NULL, ";");
        }

        listaAlunos[i] = a;
        i++;
    }

  do {
    printf("Escolha uma opcao\n");
    printf("\tO que deseja?\n");
    printf("\t[1] - Consultar por id\n");
    printf("\t[2] - Relatorio\n");
    printf("\t[3] - Sair\n");
    printf("Opcao: ");
    scanf("%d", &option);
    
    if (option > 3 || option < 1) {
      printf("Opcao invalida! Digite outra: ");
      scanf("%d", &option);
    } else {
       
        switch (option) {
          case 1:  
              consultarAluno(tamanhoListaAlunos, listaAlunos);
            break;
        
          case 2:
              relatorioAlunos(tamanhoListaAlunos, listaAlunos);
            break;
        }
      }
  } while (option != 3);
}
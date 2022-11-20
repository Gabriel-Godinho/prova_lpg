#include <stdio.h>
#include <string.h>
#include <locale.h>

// Aluno
struct aluno {
  int id_aluno;
  char nm_aluno[50];
  int deleted;

};

// Notas
struct notas {
  int id_aluno;
  int id_nota;
  float vl_nota;
};

typedef struct aluno aluno;
typedef struct notas notas;

aluno cadastrarAluno() {
  int id;
  char nome[50];

  printf("\n\tNome do aluno: ");
  scanf("\t%s", nome);

  if (strlen(nome) < 3) {
    printf("\tNome inválido! Digite novamente: ");
    scanf("\t%s", nome);
  }
  printf("\tCódigo do aluno: ");
  scanf("\t%d", &id);
  
  aluno al;
  al.id_aluno = id;
  al.deleted = 0;
  strcpy(al.nm_aluno, nome);
  
  return al;
}

void consultarAluno(int tamanho, aluno als[100]) {
  int i, cod;

  printf("\n\tCódigo do aluno: ");
  scanf("%d", &cod);
  
  for (i = 0; i < tamanho; i++) {
    if (als[i].id_aluno == cod) {
      printf("Nome: %s", als[i].nm_aluno);
      break;
    }
  }
}

int main() {
  int option, i, listaIds[100];
  aluno listaAlunos[100];
  int tamanhoListaAlunos = sizeof(listaAlunos)/sizeof(listaAlunos[0]);

  // Menu principal
  do {
    printf("Escolha uma opção\n");
    printf("[1] Aluno\n");
    printf("[2] Notas\n");
    printf("[3] Relatório\n");
    printf("[4] Sair\n");
    printf("Opção: ");
    scanf("%d", &option);
    
    if (option > 4 || option < 1) {
      printf("Opção inválida! Digite outra: ");
      scanf("%d", &option);
    } else {
        // Demais menus
        switch (option) {
          case 1:
            // Menu do aluno
            do {
              printf("\tO que deseja?\n");
              printf("\t[1] - Cadastrar\n");
              printf("\t[2] - Consultar por id\n");
              printf("\t[3] - Excluir por id\n");
              printf("\t[4] - Alterar por id\n");
              printf("\t[5] - Relatório\n");
              printf("\t[6] - Voltar\n");
              printf("\tOpção: ");
              scanf("%d", &option);
              if (option > 6 || option < 1) {
                printf("\tOpção inválida! Digite outra: ");
                scanf("\t%d", &option);
              } else {
                switch (option) {
                  case 1:
                    for (i = 0; i < tamanhoListaAlunos; i++) {
                      if (listaIds[i] == 0) {
                        listaAlunos[i] = cadastrarAluno();
                        listaIds[i] = listaAlunos[i].id_aluno;
                        printf("\n\tAluno cadastrado com sucesso!\n\tNome: %s\n\tID: %d\n\n", listaAlunos[i].nm_aluno, listaIds[i]);
                        break;
                      }
                    }
                    break;
                  case 2:
                    consultarAluno(tamanhoListaAlunos, listaAlunos);
                    break;
                }
              }
            } while (option != 6);
            break;
          // Menu das notas
          case 2:
            do {
              printf("\tO que deseja?\n");
              printf("\t[1] - Cadastrar\n");
              printf("\t[2] - Consultar por id\n");
              printf("\t[3] - Excluir por id\n");
              printf("\t[4] - Alterar por id\n");
              printf("\t[5] - Relatório\n");
              printf("\t[6] - Voltar\n");
              printf("\tOpção: ");
              scanf("%d", &option);
              if (option > 6 || option < 1) {
                printf("\tOpção inválida! Digite outra: ");
                scanf("\t%d", &option);
              }
            } while (option != 6);
            break;
          // Menu do relatório
          case 3:
            do {
              printf("\tO que deseja?\n");
              printf("\t[1] - Cadastrar\n");
              printf("\t[2] - Consultar por id\n");
              printf("\t[3] - Excluir por id\n");
              printf("\t[4] - Alterar por id\n");
              printf("\t[5] - Relatório\n");
              printf("\t[6] - Voltar\n");
              printf("\tOpção: ");
              scanf("%d", &option);
              if (option > 6 || option < 1) {
                printf("\tOpção inválida! Digite outra: ");
                scanf("\t%d", &option);
              }
            } while (option != 6);
            break;
        }
      }
  } while (option != 4);
  
}
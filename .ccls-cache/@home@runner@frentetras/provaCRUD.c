/* #include <stdio.h>
#include <string.h>
#include <locale.h>

// Notas
struct notas {
  int id_aluno;
  int id_nota;
  float vl_nota;
};

// Aluno
struct aluno {
  int id_aluno;
  char nm_aluno[50];
  int deleted;
};

typedef struct notas notas;
typedef struct aluno aluno;

// Cadastrar
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

// Consultar
void consultarAluno(int tamanho, aluno als[10]) {
  int i, cod;

  printf("\n\tCódigo do aluno: ");
  scanf("%d", &cod);
  
  for (i = 0; i < tamanho; i++) {
    if (als[i].id_aluno == cod) {
      if (als[i].deleted == 1)
        continue;
      
      printf("\tNome: %s\n\n", als[i].nm_aluno);
      break;
    }
  }
}

// Deletar
aluno* deletarAluno(int tamanho, aluno als[10]) {
  int i, cod;
  char option;

  printf("\n\tCódigo do aluno: ");
  scanf("%d", &cod);

  for (i = 0; i < tamanho; i++) {
    if (als[i].id_aluno == cod) {
      printf("\tDeseja excluir o seguinte aluno? %s\n", als[i].nm_aluno);
      printf("\t[S]im ou [N]ão: ");
      scanf("\t%c", &option);
      if (option == 'S' || option == 's') {
        als[i].deleted = 1;
        printf("\tAluno deletado com sucesso!\n\n");
        return als;
      } else if (option == 'N' || option == 'n') {
        printf("\tAluno não deletado!");
        return als;
      }
    }
  }
  
  return als;
}

// Alterar
aluno* alterarAluno(int tamanho, aluno als[10]) {
  int i, cod;
  char option;
  char novoNome[50];

  printf("\n\tCódigo do aluno: ");
  scanf("%d", &cod);

  for (i = 0; i < tamanho; i++) {
    if (als[i].id_aluno == cod) {

      if (als[i].deleted == 1)
        continue;
      
      printf("\tNome do aluno: %s\n", als[i].nm_aluno);
      printf("\tNovo nome: ");
      scanf("\t%s", novoNome);
      printf("\tConfirma a alteração?");
      printf("\t[S]im ou [N]ão: ");
      scanf("\t%c", &option);
      if (option == 'S' || option == 's') {
        strcpy(als[i].nm_aluno, novoNome);
        als[i].id_aluno = cod;
        printf("\tAluno alterado com sucesso!\n\n");
        return als;
      } else if (option == 'N' || option == 'n') {
        printf("Alteração cancelada!");
        return als;
      }
    }
  }

  return als;
}

// Relatório alunos
void relatorioAlunos(int tamanho, aluno als[10]) {
  int i;
  
  printf("\t-------------------------------------------------------------------------\n");
  printf("\tRelatório\n");
  printf("\t-------------------------------------------------------------------------\n");
  printf("\t-------------------------------------------------------------------------\n");
  printf("\t|  ID  | Nome                                            |   Excluído   |\n");
  printf("\t|------|-------------------------------------------------|--------------|\n");

  for (i = 0; i < tamanho; i++) {
    
    if (als[i].id_aluno <= 0)
      break; // Quando os alunos acabarem o loop acabada
    
    printf("\t|  %d  | %s                                              |   %d         |\n", als[i].id_aluno, als[i].nm_aluno, als[i].deleted);
    printf("\t|------|-------------------------------------------------|--------------|\n");
  }
}

// Cadastrar notas
notas cadastrarNotasAluno(int tamanho, aluno als[10]) {
  int i, cod;

  printf("\tCódigo do aluno: ");
  scanf("\t%d", &cod);

  for (int i = 0;i < tamanho; i++) {
    if (als[i].id_aluno == cod) {
      printf("\tNome do aluno: %s\n", als[i].nm_aluno);
      break;
    }
  }

  notas nota;
  printf("\tDigite o valor da nota: ");
  scanf("\t%f", &nota.vl_nota);
  if (nota.vl_nota < 0.0) {
    printf("\tNota inválida! Digite outra: ");
    scanf("\t%f", &nota.vl_nota);
  }
  nota.id_aluno = cod;
  nota.id_nota = cod;

  return nota;
}

void consultarNotas(notas listaNotas[10], int tamanho, aluno als[10]) {
  int i, j, cod;

  printf("\tCódigo do aluno: ");
  scanf("\t%d", &cod);

  for (int i = 0;i < tamanho; i++) {
    if (als[i].id_aluno == cod) {
      printf("\tNome do aluno: %s\n", als[i].nm_aluno);
      printf("\tNota: %f\n", listaNotas[i].vl_nota);
      break;
    }
  }
}

int main() {
  int option, i, j, listaIds[10]; // Lista que guarda o id dos alunos
  aluno listaAlunos[10]; // Lista de alunos
  notas listaNotas[10]; // Lista de notas
  int tamanhoListaAlunos = sizeof(listaAlunos)/sizeof(listaAlunos[0]); // Tamanho da lista de alunos

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
                  case 3:
                    strcpy(listaAlunos, deletarAluno(tamanhoListaAlunos, listaAlunos));
                    break;
                  case 4:
                    strcpy(listaAlunos, alterarAluno(tamanhoListaAlunos, listaAlunos));
                    break;
                  case 5:
                    relatorioAlunos(tamanhoListaAlunos, listaAlunos);
                    break;
                }
              }
            } while (option != 6);
            break;
          // Menu das notas
          case 2:
            do {
              printf("\tO que deseja?\n");
              printf("\t[1] - Incluir Nota do Aluno\n");
              printf("\t[2] - Alterar Nota do Aluno\n");
              printf("\t[3] - Excluir Nota do Aluno\n");
              printf("\t[4] - Consultar Notas do Aluno\n");
              printf("\t[5] - Voltar\n");
              printf("\tOpção: ");
              scanf("%d", &option);
              if (option > 6 || option < 1) {
                printf("\tOpção inválida! Digite outra: ");
                scanf("\t%d", &option);
              } else {
                switch(option) {
                  case 1:
                    for (i = 0; i < tamanhoListaAlunos; i++) {
                      if (listaNotas[i].id_aluno <= 0) {
                        listaNotas[i] = cadastrarNotasAluno(tamanhoListaAlunos, listaAlunos);
                        printf("\tNota cadastrada com sucesso!\n\n");
                        break;
                      }
                    }  
                    break;
                  case 2:
                    break;
                  case 3:
                    break;
                  case 4:
                    consultarNotas(listaNotas, tamanhoListaAlunos, listaAlunos);
                    break;
                  case 5:
                    break;
                }
              }
            } while (option != 5);
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
  
} */
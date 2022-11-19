#include <stdio.h>
#include <locale.h>

struct aluno {
  int id_aluno;
  char nm_aluno[50];
  int deleted;

};

struct notas {
  int id_aluno;
  int id_nota;
  float vl_nota;
};

int main() {
  int option;
  do {
    printf("Escolha uma opção\n");
    printf("[1] Aluno\n");
    printf("[2] Notas\n");
    printf("[3] Relatório\n");
    printf("[4] Sair\n");
    scanf("%d", &option);
    
    if (option > 4 || option < 1) {
      printf("Está opção não existe! Digite outra: ");
      scanf("%d", &option);
    } else {
        switch (option) {
          
        }
          
      }
    }
    
  } while (option != 4);
  
}
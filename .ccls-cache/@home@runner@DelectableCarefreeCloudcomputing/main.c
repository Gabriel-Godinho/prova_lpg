#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    int i, option;;
    int primos[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27};
    printf("\n==> MMC e MDC <==\n\n");
    printf("1- Calcular MMC e MDC\n");
    printf("2- Sair\n");
    printf("opcão: ");
    scanf("%d", &option);

    while (option == 1)
    {   
        int num1, num2, mmc = 1, mdc = 1, cont = 0;
        
        // Solicita o primeiro número
        printf("\nInsira o primeiro número: ");
        scanf("%d", &num1);
        // Validação do primeiro número
        while (num1 <= 0) 
        {
            printf("Apenas positivos maiores que zero são válidos, insira outro n°: ");
            scanf("%d", &num1);
        }
        // Solicita o segundo número
        printf("Insira o segundo número: ");
        scanf("%d", &num2);
        // Validação do segundo número
        while (num2 <= 0) 
        {
            printf("Apenas positivos maiores que zero são válidos, insira outro n°: ");
            scanf("%d", &num2);
        }

        // Cálculo do MMC e do MDC
        while (num1 != 1 && num2 != 1)
        {   
            if (num1 % primos[cont] == 0 && num2 % primos[cont] == 0) {
                num1 = num1 / primos[cont];
                num2 = num2/ primos[cont];
                mmc *= primos[cont];
                mdc *= primos[cont];
            } else if (num1 % primos[cont] == 0 && num2 % primos[cont] != 0) {
                num1 = num1 / primos[cont];
                mmc *= primos[cont];
            } else if (num2 % primos[cont] == 0 && num1 % primos[cont] != 0) {
                num2 = num2 / primos[cont];
                mmc *= primos[cont];
            }
            if (num1 % primos[cont] != 0 && num2 % primos[cont] != 0) {
                cont++;              
            }
            if (num1 == 1 && num2 != 1 || num1 != 1 && num2 == 1) {
                mmc *= primos[cont];
            }
        }

        // Saídas
        printf("\nMMC = %d\nMDC = %d\n\n", mmc, mdc);
        printf("Deseja continuar?\n1- Sim\n2- Não\n");
        printf("opcão: ");
        scanf("%d", &option);       
    }
    
    printf("\n==> Programa Finalizado com sucesso! <==\n\n");

    return 0;
}
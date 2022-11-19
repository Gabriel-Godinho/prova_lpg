#include <stdio.h>
#include <locale.h>

void frente(int vet[], int n, int i, int v) {
    while (v != 0 && i <= n)
    {
        vet[i] += v;
        i++;
        v--;
    } 
}

void tras(int vet[], int n, int i, int v) {
    while (v != 0 && i >= 1)
    {
        vet[i] += v;
        i--;
        v--;
    } 
}

void imprime(int v[], int n, int i) {
    printf("%d\n", v[i]);
}

int main(int argc, char const *argv[])
{
    int n, m, func;
    int j, v;

    /* Entrada do tamanho do vetor e do nímero de instruções */
    scanf("%d %d", &n, &m);
    int vet[n];

    /* Validação de dados */
    while (n > 200000 || n < 1)
    {
        printf("\nDigite novamente os valores: ");
        scanf("%d %d", &n, &m);
    } 
    
    /* Inicializa o vetor com 0 em todas as posições */
    for (size_t i = 0; i < n; i++)
    {
        vet[i] = 0;
    }

    /* Entrada das instruções e execução das funções */
    for (size_t i = 0; i < m; i++)
    {   
        scanf("%d %d", &func, &j);

        if (func != 3)
            scanf("%d", &v);

        switch (func)
        {
        case 1:
            frente(vet, n, j, v);
            break;
        
        case 2:
            tras(vet, n, j, v);
            break;

        case 3:
            imprime(vet, n, j);
            break;
        }
    }

    return 0;
}
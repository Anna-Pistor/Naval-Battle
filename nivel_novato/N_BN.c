#include <stdio.h>

int main()
{

    // VETOR DE LINHAS PARA LISTA
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];

    for (int t = 0; t < 10; t++)
    {
        for (int i = 0; i < 10; i++)
        {
            tabuleiro[t][i] = 0;
        }
    }

    int navioH[3] = {3, 3, 3};
    int navioV[3] = {3, 3, 3};

    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;

    if (colunaH + 2 >= 10)
    {
        printf("erro: navio horizontal não cabe no tabuleiro.");
    }

    if (linhaV + 2 >= 10)
    {
        printf("erro: navio vertical não cabe no tabuleiro.");
    }

    // verificando espaço na horizontal
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[linhaH][colunaH + i] != 0)
        {
            printf("erro: navio horizontal esta sobrepondo outro navio.");
            return 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linhaH][colunaH + i] = navioH[i];
    }

    // verificando espaço na vertical
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[linhaV][colunaV + i] != 0)
        {
            printf("erro: navio horizontal esta sobrepondo outro navio.");
        }
    }

    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }

    // impressão dos barcos
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        // imprime cada letra
        printf("%c  |  ", linha[i]);

        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}
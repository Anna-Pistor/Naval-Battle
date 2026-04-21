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

    // TAMANHO DO NAVIO
    int navioH[3] = {1, 1, 1};
    int navioV[3] = {1, 1, 1};
    int navioD1[3] = {1, 1, 1};
    int navioD2[3] = {1, 1, 1};

    // INICIO DOS NAVIOS
    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;
    int linhaD1 = 0, colunaD1 = 0;
    int linhaD2 = 2, colunaD2 = 9;

    // REGRAS
    if (colunaH + 2 >= 10)
    {
        printf("erro: navio horizontal não cabe no tabuleiro!");
    }

    if (linhaV + 2 >= 10)
    {
        printf("erro: navio vertical não cabe no tabuleiro!");
    }

    if (linhaD1 + 2 >= 10 || colunaD1 + 2 >= 10)
    {
        printf("erro: navio diagonal 1 não cabe no tabuleiro!");
        return 0;
    }

    if (linhaD2 + 2 >= 10 || colunaD2 - 2 >= 10)
    {
        printf("erro: navio diagonal 2 não cabe no tabuleiro!");
        return 0;
    }

    // verificando espaço na horizontal
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[linhaH][colunaH + i] != 0)
        {
            printf("erro: navio horizontal esta sobrepondo outro navio!");
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
            printf("erro: navio horizontal esta sobrepondo outro navio!");
        }
    }

    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }

    // verificando espaço na diagonal 1
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0)
        {
            printf("erro: navio diagonal 1 esta sobrepondo outro navio!");
        }
    }

    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linhaD1 + i][colunaD1 + i] = navioD1[i];
    }

    // verificando espaço diagonal 2
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0)
        {
            printf("erro: navio diagonal 2 esta sobrepondo outro navio!");
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        tabuleiro[linhaD2 + i][colunaD2 - i] = navioD2[i];
    }

    // impressão dos barcos
    printf("\n      ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", i);
    }

    printf("\n     ");

    for (int i = 0; i < 10; i++)
    {
        printf("--");
    }

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
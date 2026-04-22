#include <stdio.h>
#include <stdlib.h>

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
    int navioH[3] = {3, 3, 3};
    int navioV[3] = {3, 3, 3};
    int navioD1[3] = {3, 3, 3};
    int navioD2[3] = {3, 3, 3};

    // INICIO DOS NAVIOS
    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;
    int linhaD1 = 0, colunaD1 = 0;
    int linhaD2 = 2, colunaD2 = 9;

    // INICIO MATRIZES DE HABILIDADES
    int cruzL = 2, cruzC = 2;
    int coneL = 5, coneC = 5;
    int octaL = 8, octaC = 8;

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
        if (tabuleiro[linhaV + i][colunaV + ] != 0)
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

    // HABILIDADES

    // CRUZ
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 2 || j == 2)
            {
                int destinoL = cruzL + i - 2;
                int destinoC = cruzC + j - 2;

                // validação
                if (destinoL >= 0 && destinoL < 10 && destinoC >= 0 && destinoC < 10)
                {
                    tabuleiro[destinoL][destinoC] = 5;
                }
            }
        }
    }

    // CONE
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j >= (2 - i) && j <= (2 + i))
            {
                int destinoL = coneL + i - 2;
                int destinoC = coneC + j - 2;

                // validação
                if (destinoL >= 0 && destinoL < 10 && destinoC >= 0 && destinoC < 10)
                {
                    tabuleiro[destinoL][destinoC] = 5;
                }
            }
        }
    }

    // OCTAEDRO
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (abs(i - 2) + abs(j - 2) <= 2)
            {
                int destinoL = octaL + i - 2;
                int destinoC = octaC + j - 2;

                // validação
                if (destinoL >= 0 && destinoL < 10 && destinoC >= 0 && destinoC < 10)
                {
                    tabuleiro[destinoL][destinoC] = 5;
                }
            }
        }
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
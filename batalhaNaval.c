#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    //declarando variáveis
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int linha[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int limiteTabuleiroX = 10;
    int limiteTabuleiroY = 10;
    int tabuleiro [limiteTabuleiroX] [limiteTabuleiroY];
    int tamanhoNavioVertical = 3;
    int tamanhoNavioHorizontal = 3;
    int inicioYNavioVertical = 2;
    int posicaoXNavioVertical = 5;
    int inicioXNavioHorizontal = 6;
    int posicaoYNavioHorizontal = 6;
    int inicioXNavioDiagonal1 = 1;
    int inicioYNavioDiagonal1 = 1;
    int inicioXNavioDiagonal2 = 2;
    int inicioYNavioDiagonal2 = 7;
    int posicaoFinalXNavioDiagonal1 = 3;
    int posicaoFinalYNavioDiagonal1 = 3;
    int posicaoFinalXNavioDiagonal2 = 0;
    int posicaoFinalYNavioDiagonal2 = 9;
    int navioVertical [tamanhoNavioVertical];
    int navioHorizontal [tamanhoNavioHorizontal];

    //Criando o Tabuleiro
    printf ("Criando o Tabuleiro\n");
    printf ("\n"); //quebra de linha para melhor visualização

    //Criando o cabeçalho do tabuleiro
    printf ("   ");
    for (int y = 0; y < limiteTabuleiroY; y++)
    {
        printf ("%c ", coluna[y]);
    }

    printf ("\n"); //quebra de linha para melhor visualização

    //Identificação da água do tabuleiro
    for (int y = 0; y < limiteTabuleiroY; y++)
    {  
         //Criando a identificação de linhas
        if (linha[y] < 10)
        {
            printf ("%d  ", linha[y]);
        } else if (linha [y] >= 10)
        {
            printf ("%d ", linha[y]);
        }
        
        for (int x = 0; x < limiteTabuleiroX; x++)
        {
            tabuleiro [y] [x] = 0;
            printf ("%d ", tabuleiro [y] [x]);
        }
        printf ("\n");
    }

    //Bloco de verificação de viabilidade de limite do tabuleiro
    if ( (inicioXNavioHorizontal > limiteTabuleiroX) || 
        (posicaoYNavioHorizontal > limiteTabuleiroY) || 
        (inicioXNavioHorizontal + tamanhoNavioHorizontal > limiteTabuleiroX) ) 
    {
        printf ("Posição do navio horizontal fora do limite do tabuleiro.\n");
        return 1;
    } else if ( (inicioYNavioVertical > limiteTabuleiroY) ||
                (posicaoXNavioVertical > limiteTabuleiroX) ||
                (inicioYNavioVertical + tamanhoNavioVertical > limiteTabuleiroY) )
    {
        printf ("Posição do navio vertical fora do limite do tabuleiro.\n");
        return 1;
    }

    //Definindo o valor do navio vertical
    for (int y = inicioYNavioVertical; y < (inicioYNavioVertical + tamanhoNavioVertical); y++)
    {
        tabuleiro [y] [posicaoXNavioVertical] = 3;
    }

    //Definindo o valor do navio horizontal
    for (int x = inicioXNavioHorizontal; x < (inicioXNavioHorizontal + tamanhoNavioHorizontal); x++)
    {
        //identificação de colisão de navios
        if (tabuleiro [posicaoYNavioHorizontal] [x] == 3)
        {
            printf ("Erro: Sobreposição de navios.\n");
            return 1;
        }
        
        tabuleiro [posicaoYNavioHorizontal] [x] = 3;
    }

    //Definindo o valor do navio diagonal 1
    for (int x = inicioXNavioDiagonal1, y = inicioYNavioDiagonal1; x <= posicaoFinalXNavioDiagonal1 && y <= posicaoFinalYNavioDiagonal1; x++, y++)
    {
          //identificação de colisão de navios
          if (tabuleiro [y] [x] == 3)
          {
              printf ("Erro: Sobreposição de navios.\n");
              return 1;
          }
       tabuleiro [y] [x] = 3;
    }
    
    //Definindo o valor do navio diagonal 2
    for (int x = inicioXNavioDiagonal2, y = inicioYNavioDiagonal2; x >= posicaoFinalXNavioDiagonal2 && y <= posicaoFinalYNavioDiagonal2; x--, y++)
    {
          //identificação de colisão de navios
          if (tabuleiro [y] [x] == 3)
          {
              printf ("Erro: Sobreposição de navios.\n");
              return 1;
          }
        tabuleiro [y] [x] = 3; 
    }
    
    
    //Mostrando o Tabuleiro com navios
    printf ("\n"); //quebra de linha para melhor visualização
    printf ("Tabuleiro com os navios\n");
    printf ("\n"); //quebra de linha para melhor visualização

        //Criando o cabeçalho do tabuleiro
    printf ("   ");
    for (int y = 0; y < limiteTabuleiroY; y++)
    {
        printf ("%c ", coluna[y]);
    }

    printf ("\n"); //quebra de linha para melhor visualização

    //Mostrar o tabuleiro com navios
    for (int y = 0; y < limiteTabuleiroY; y++)
    {
        //Criando a identificação de linhas
        if (linha[y] < 10)
        {
            printf ("%d  ", linha[y]);
        } else if (linha [y] >= 10)
        {
            printf ("%d ", linha[y]);
        }
        for (int x = 0; x < limiteTabuleiroX; x++)
        {
            printf ("%d ", tabuleiro [y] [x]);
        }
        printf ("\n");
    }


    //criar matriz em cone
    //criar matriz 3x5   
    //   0 0 3 0 0
    //   0 3 3 3 0
    //   3 3 3 3 3

    const int linhas_cone = 3;
    const int colunas_cone = 5;
    int matriz_cone[linhas_cone][colunas_cone];

    for (int i = 0; i < linhas_cone; i++) {
        for (int j = 0; j < colunas_cone; j++) {
            int centro = colunas_cone / 2;
            if (j >= centro - i && j <= centro + i) {
                matriz_cone[i][j] = 1;
            } else {
                matriz_cone[i][j] = 0;
            }
        }
    }

    /* Imprimir matriz do cone para teste de funcionamento
    for (int i = 0; i < linhas_cone; i++) {
        for (int j = 0; j < colunas_cone; j++) {
            printf("%d ", matriz_cone[i][j]);
        }
        printf("\n");
    }
    */

    //criar matriz em cruz
    //criar matriz 5x5  
    //   0 0 3 0 0
    //   0 0 3 0 0
    //   3 3 3 3 3
    //   0 0 3 0 0
    //   0 0 3 0 0

    int matriz_cruz[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Condição para formar a cruz: linha do meio ou coluna do meio
            if (i == 2 || j == 2) {
                matriz_cruz[i][j] = 1;
            } else {
                matriz_cruz[i][j] = 0;
            }
        }
    }

    /* Imprimir matriz da cruz para teste de funcionamento
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz_cruz[i][j]);
        }
        printf("\n");
    }
    */



    //criar matriz em octaedro (+)
    //criar matriz 3x5
    //   0 0 3 0 0
    //   0 3 3 3 0
    //   0 0 3 0 0
    
    const int linhas_octaedro = 3;
    const int colunas_octaedro = 5;
    int matriz_octaedro[linhas_octaedro][colunas_octaedro];

    // Preenchendo a matriz
    for (int i = 0; i < linhas_octaedro; i++) {
        for (int j = 0; j < colunas_octaedro; j++) {
            // Condição para formar o octaedro
            if ((i == 0 || i == 2) && j == 2) {
                matriz_octaedro[i][j] = 1;
            } else if (i == 1 && (j >= 1 && j <= 3)) {
                matriz_octaedro[i][j] = 1;
            } else {
                matriz_octaedro[i][j] = 0;
            }
        }
    }


    /* Imprimir matriz do octaedro para teste de funcionamento
    for (int i = 0; i < linhas_octaedro; i++) {
        for (int j = 0; j < colunas_octaedro; j++) {
            printf("%d ", matriz_octaedro[i][j]);
        }
        printf("\n");
    }
    */

    // bloco de definição das posições iniciais dos poderes

    int inicio_linha_cone = 1;
    int inicio_coluna_cone = 1;
    int inicio_linha_cruz = 5;
    int inicio_coluna_cruz = 5;
    int inicio_linha_octaedro = 0;
    int inicio_coluna_octaedro = 6;

    // bloco de sobreposição das habilidades na matriz
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) { 
            //identificando onde há sobreposição de habilidade com o navio
            if (matriz_cone[i][j] == 1 && tabuleiro[inicio_linha_cone + i][inicio_coluna_cone + j] == 3) {
                tabuleiro[inicio_linha_cone + i][inicio_coluna_cone + j] = 5;
            } 
            // identificando onde há sobreposição de navio com área não atingida da matriz_cone
            else if (matriz_cone[i][j] == 0 && tabuleiro[inicio_linha_cone + i][inicio_coluna_cone + j] == 3)
            {
                tabuleiro[inicio_linha_cone + i][inicio_coluna_cone + j] = 3;
            }
            // identificndo onde há sobreposição de habilidade com água e água com área não atingida
            // no caso, ambas as situações podemos utilizar o valor da matriz_cone
            else {
                tabuleiro[inicio_linha_cone + i][inicio_coluna_cone + j] = matriz_cone [i] [j];
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            //identificando onde há sobreposição de habilidade com o navio
            if (matriz_cruz[i][j] == 1 && tabuleiro[inicio_linha_cruz + i][inicio_coluna_cruz + j] == 3) {
                tabuleiro[inicio_linha_cruz + i][inicio_coluna_cruz + j] = 5;
            }
            // identificando onde há sobreposição de navio com área não atingida da matriz_cruz
            else if (matriz_cruz[i][j] == 0 && tabuleiro[inicio_linha_cruz + i][inicio_coluna_cruz + j] == 3)
            {
                tabuleiro[inicio_linha_cruz + i][inicio_coluna_cruz + j] = 3;
            }
            // identificndo onde há sobreposição de habilidade com água e água com área não atingida
            // no caso, ambas as situações podemos utilizar o valor da matriz_cruz
            else {
                tabuleiro[inicio_linha_cruz + i][inicio_coluna_cruz + j] = matriz_cruz [i] [j];
            }
            
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz_octaedro[j][i] == 1 && tabuleiro[inicio_coluna_octaedro + j][inicio_linha_octaedro + i] == 3) {
                tabuleiro[inicio_coluna_octaedro + j][inicio_linha_octaedro + i] = 5;
            }
            // identificando onde há sobreposição de navio com área não atingida da matriz_octaedro
            else if (matriz_octaedro[j][i] == 0 && tabuleiro[inicio_coluna_octaedro + j][inicio_linha_octaedro + i] == 3)
            {
                tabuleiro[inicio_coluna_octaedro + j][inicio_linha_octaedro + i] = 3;
            }
            // identificndo onde há sobreposição de habilidade com água e água com área não atingida
            // no caso, ambas as situações podemos utilizar o valor da matriz_octaedro
            else {
                tabuleiro[inicio_coluna_octaedro + j][inicio_linha_octaedro + i] = matriz_octaedro [j] [i];
            }
        }
    }

    //Mostrando o Tabuleiro com navios e habilidades
    printf ("\n"); //quebra de linha para melhor visualização
    printf ("Tabuleiro com os navios e habilidades\n");
    printf ("\n"); //quebra de linha para melhor visualização

        //Criando o cabeçalho do tabuleiro
    printf ("   ");
    for (int y = 0; y < limiteTabuleiroY; y++)
    {
        printf ("%c ", coluna[y]);
    }

    printf ("\n"); //quebra de linha para melhor visualização

    //Mostrar o tabuleiro com navios e habilidades
    for (int y = 0; y < limiteTabuleiroY; y++)
    {
        //Criando a identificação de linhas
        if (linha[y] < 10)
        {
            printf ("%d  ", linha[y]);
        } else if (linha [y] >= 10)
        {
            printf ("%d ", linha[y]);
        }
        for (int x = 0; x < limiteTabuleiroX; x++)
        {
            printf ("%d ", tabuleiro [y] [x]);
        }
        printf ("\n");
    }













    return 0;
}
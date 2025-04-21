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


    return 0;
}

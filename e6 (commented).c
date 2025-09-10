#include <stdio.h>   // Biblioteca padrão para entrada e saída
#include <stdlib.h>  // Biblioteca padrão para funções utilitárias

int a[6][6],i,j,X,soma; // Declara matriz 6x6 e variáveis globais

void leitura();         // Declara função de leitura da matriz
void leiturahash();     // Declara função para somar os triângulos

void leitura(){
    printf("Insira os 36 valores do array:\n"); // Solicita os 36 números ao usuário
    for(i=0;i<6;i++){          // Loop para percorrer as linhas da matriz
        for(j=0;j<6;j++){      // Loop para percorrer as colunas da matriz
            scanf("%d",&a[i][j]); // Lê cada elemento da matriz
        }
    }
}

void leiturahash(){
    soma=0;  // Inicializa a soma com zero
    printf("\nDigite 1 valor entre 1 e 8:\n"); // Solicita qual operação executar
    scanf("%d", &X); // Lê a escolha do usuário

    switch(X){  
        case 1:  
            for(i=0;i<6;i++){            // Loop pelas linhas
                for(j=0+i;j<6;j++){      // Loop pelas colunas do triângulo superior direito
                    soma += a[i][j];    // Acumula os valores na soma
                }
            } 
            printf("O resultado da soma e: %d\n", soma); // Imprime o resultado
            break;

        case 2:
            soma = 0;  
            for(i = 0; i < 6; i++){          // Loop pelas linhas
                for(j = 0; j <= i; j++){     // Loop pelas colunas do triângulo inferior esquerdo
                    soma += a[i][j];        // Acumula os valores na soma
                }
            }
            printf("O resultado da soma e: %d\n", soma);  
            break;

        case 3:
            soma = 0;  
            for(i = 0; i < 6; i++){  
                for(j = 0; j < 6; j++){  
                    if(i < j && i + j < 5){  // Condição para o triângulo de cima (entre duas diagonais)
                        soma += a[i][j];  
                    }
                }
            } 
            printf("O resultado da soma e: %d\n", soma);  
            break;

        case 4:
            soma = 0;  
            for(i = 0; i < 6; i++){  
                for(j = 0; j < 6; j++){  
                    if(i > j && i + j < 5){ // Condição para o triângulo da esquerda
                        soma += a[i][j];  
                    }
                }
            } 
            printf("O resultado da soma e: %d\n", soma);  
            break;

        case 5:
            soma = 0;  
            for(i = 0; i < 6; i++){  
                for(j = 0; j < 6; j++){  
                    if(i + j < 5 || i + j > 5){ // Soma triângulos da esquerda e direita
                        soma += a[i][j];  
                    }
                }
            } 
            printf("O resultado da soma e: %d\n", soma);  
            break;

        case 6:
            soma = 0;  
            for(i = 0; i < 6; i++){  
                for(j = 0; j < 6; j++){  
                    if((i < j && i + j < 5) || (i > j && i + j > 5)){ // Soma triângulos de cima e de baixo
                        soma += a[i][j];  
                    }
                }
            }
            printf("O resultado da soma e: %d\n", soma);  
            break;

        case 7:
            soma = 0;  
            for(i = 0; i < 6; i++){  
                for(j = 0; j < 6; j++){  
                    if((i < j && i + j < 5) || (i > j && i + j < 5)){ // Soma triângulos de cima e esquerda
                        soma += a[i][j];  
                    }
                }
            } 
            printf("O resultado da soma e: %d\n", soma);  
            break;

        case 8:
            soma = 0;  
            for(i = 0; i < 6; i++){  
                for(j = 0; j < 6; j++){  
                    if((i > j && i + j < 5) || (i > j && i + j > 5)){ // Soma triângulos da esquerda e de baixo
                        soma += a[i][j];  
                    }
                }
            } 
            printf("O resultado da soma e: %d\n", soma);  
            break;
    }
}

int main (void){
    leitura();        // Chama a função para ler a matriz
    leiturahash();    // Chama a função que soma os triângulos
}
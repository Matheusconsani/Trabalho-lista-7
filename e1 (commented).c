#include <stdio.h>   // Biblioteca padrão de entrada/saída
#include <stdlib.h>  // Biblioteca para funções rand, srand, etc.
#include <time.h>    // Biblioteca para usar time() na semente do rand

// Declaração de variáveis globais
int a, b;        // Valores apostados pelo usuário
int av = 3, bv = 2; // Valores sorteados do "computador" ou jogo
int p;           // Pontuação do jogador
char ab, tecla;  // ab: resposta de sair ou não, tecla: não usada no código

// Função para leitura do placar apostado pelo usuário
void leitura(){
    p = 0;  // Zera a pontuação a cada nova aposta
    printf("digite o placar a ser apostado:"); 
    scanf("%d%c%d", &a, &ab, &b);  
    // Lê o placar no formato "x:y" (ex: 2:1)
    // %c pega o caractere ':' entre os números
}

// Função que calcula a pontuação do jogador
void comp(){
    if(av == bv){          // Se o placar sorteado tem empate
        p = p + 10;        // 10 pontos para o jogador
    }
    if(a == av){            // Se o usuário acertou o placar do time A
        p = p + 5;          // 5 pontos
        if(b == bv){        // E se também acertou o placar do time B
            p = p + 10;     // 10 pontos extras
        }
    }
    if(b == bv){            // Se o usuário acertou o placar do time B
        p = p + 5;          // 5 pontos
    }
}

// Função principal
int main (){
    while(1){   // Loop infinito até o usuário decidir sair
        srand(time(NULL));        // Semente do gerador de números aleatórios
        av = rand() % 8;          // Gera um número aleatório entre 0 e 7 para o time A
        bv = rand() % 8;          // Gera um número aleatório entre 0 e 7 para o time B

        printf("Quer sair do programa? S/N\n");
        scanf(" %c", &ab);       // Pergunta se o usuário quer sair
        if(ab=='S'||ab=='s'){    // Se sim, quebra o loop
            break;
        }

        leitura();               // Lê o placar apostado pelo usuário
        comp();                  // Calcula a pontuação
        printf("Sua pontuacao foi: %d\n", p); // Mostra a pontuação
    }

    printf("Programa encerrando..."); // Mensagem de saída
    return 0;   // Encerra o programa
}
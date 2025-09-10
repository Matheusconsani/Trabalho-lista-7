#include <stdio.h>   // Biblioteca padrão de entrada e saída

int i, a[80], ab[11] = {0};   // 'i' é índice global, 'a' armazena 80 notas, 'ab' é vetor de frequências absolutas inicializado em 0
float rl[11] = {0};           // 'rl' armazena as frequências relativas, inicializado em 0

// Declaração das funções
void leitura();
void absoluta();
void relativa();

// Função para ler as 80 notas
void leitura(){
    for(i = 0; i < 80; i++){           // Loop para 80 entradas
        scanf("%d", &a[i]);            // Lê uma nota inteira e guarda em a[i]
    }
}

// Função para calcular a frequência absoluta
void absoluta(){
    for(i = 0; i < 80; i++){           // Percorre todas as 80 notas
        switch(a[i]){                  // Usa switch para contar cada nota
            case 1: ab[0]++; break;    // Nota 1 incrementa ab[0]
            case 2: ab[1]++; break;    // Nota 2 incrementa ab[1]
            case 3: ab[2]++; break;
            case 4: ab[3]++; break;
            case 5: ab[4]++; break;
            case 6: ab[5]++; break;
            case 7: ab[6]++; break;
            case 8: ab[7]++; break;
            case 9: ab[8]++; break;
            case 10: ab[9]++; break;
            case 11: ab[10]++; break;  // Nota 11 incrementa ab[10]
        }
    }
}

// Função para calcular a frequência relativa
void relativa(){
    for(i = 0; i < 11; i++){                  // Loop para as 11 notas possíveis
        rl[i] = (float) ab[i] / 80.0;         // Divide a frequência absoluta pelo total (80)
    }
}

// Função para imprimir os resultados
void print(){
    for(i = 0; i < 11; i++){   // Percorre as 11 notas
        printf("Nota %d, freq. absoluta = %d, freq. relativa = %.2f\n",
               i+1, ab[i], rl[i]);   // Imprime nota, absoluta e relativa formatada com 2 casas decimais
    }
}

// Função principal
int main (void){
    leitura();     // Lê as notas
    absoluta();    // Calcula frequências absolutas
    relativa();    // Calcula frequências relativas
    print();       // Exibe os resultados
}
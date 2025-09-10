#include <stdio.h>

// Variáveis globais
int X;          // X = opção escolhida
float A,B,C,aux;    // A, B, C = números digitados, aux = auxiliar para troca

// Declaração das funções
void leitura(); 
void print();

// Função para ler os valores digitados
void leitura(){
    printf("Entre com o Valor de X:\n");
    scanf("%d", &X);          // Lê a opção escolhida
    printf("Entre com o Valor de A:\n");
    scanf("%f", &A);          // Lê o valor de A
    printf("Entre com o Valor de B:\n");
    scanf("%f", &B);          // Lê o valor de B
    printf("Entre com o Valor de C:\n");
    scanf("%f", &C);          // Lê o valor de C
}

// Função que decide o que fazer de acordo com X
void print(){
    switch (X) // Verifica a opção escolhida
    {
    case 1: // Ordenar em ordem crescente
            if(A>B){          // Se A maior que B, troca
                aux=A;
                A=B;
                B=aux;
            }
            if(A>C){          // Se A maior que C, troca
                aux=A;
                A=C;
                C=aux; 
            }
            if(B>C){          // Se B maior que C, troca
                aux=B;
                B=C;
                C=aux; 
            }
       printf("Ordem crescente: %.2f,%.2f,%.2f\n",A,B,C);
       break;

    case 2: // Ordenar em ordem decrescente
            if(A<B){          // Se A menor que B, troca
                aux=A;
                A=B;
                B=aux;
            }
            if(A<C){          // Se A menor que C, troca
                aux=A;
                A=C;
                C=aux; 
            }
            if(B<C){          // Se B menor que C, troca
                aux=B;
                B=C;
                C=aux; 
            }
       printf("Em ordem Decrescente: %.2f,%2f,%.2f\n",A,B,C); 
       // OBS: aqui está com %2f em vez de %.2f (bug de formatação)
       break;

    case 3: // Colocar o maior número no meio
            if(A>B){          // Ordena primeiro
                aux=A;
                A=B;
                B=aux;
            }
            if(A>C){
                aux=A;
                A=C;
                C=aux; 
            }
            if(B>C){
                aux=B;
                B=C;
                C=aux; 
            }
        printf("Maior no meio: %.2f,%.2f,%.2f\n",A,C,B);
        // Aqui imprime: menor, maior, médio
        break;

    default: 
        printf("Opcao Invalida."); // Caso X não seja 1,2 ou 3
        break;
    }
}

// Função principal
int main (void){
    leitura(); // Lê os dados
    print();   // Executa a opção escolhida
}

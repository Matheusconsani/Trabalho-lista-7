#include <stdio.h>  // Biblioteca padrão de entrada e saída

// Declaração de variáveis globais
int a[10], b[10]; // a: armazena os números digitados pelo usuário; b: armazena o dobro dos números
int i, j, p, aux; // i, j: índices de loops; p: número a ser pesquisado; aux: variável auxiliar

// Declaração de funções
void dobro(); 
void ordenar(); 
void pesquisa();

// Função para ler 10 números e calcular o dobro
void dobro(){
    for(i=0;i<10;i++){  // Loop para ler 10 números
        printf("Digite o numero da posicao %d\n", i);  // Pede o número
        scanf("%d", &a[i]);  // Lê o número do usuário e armazena em a[i]
        b[i] = a[i] * 2;     // Calcula o dobro e armazena em b[i]
    }
}

// Função para ordenar o array b em ordem crescente
void ordenar(){
    for(i=0;i<9;i++){         // Loop externo para percorrer os elementos
        for(j=1;j<10;j++){    // Loop interno para comparar elementos
            if(b[i] > b[j]){  // Se o elemento i for maior que j, troca-os
                aux = b[i];   // Guarda temporariamente o valor de b[i]
                b[i] = b[j];  // Substitui b[i] pelo valor menor
                b[j] = aux;   // Coloca o valor maior em b[j]
            }
        }
    }
}

// Função para pesquisar um número no array b
void pesquisa(){
    aux = 92312333;  // Valor alto usado como "flag" para indicar que não encontrou
    printf("\nDigite o numero a ser pesquisado:\n");
    scanf("%d", &p);  // Lê o número a ser pesquisado
    for(i=0;i<10;i++){  // Percorre todo o array
        if(p == b[i]){  // Se o número for encontrado
            printf("O seu numero esta na posicao %d\n", i);  // Imprime a posição
            aux = 0;  // Marca que encontrou
        }
    }
    if(aux == 92312333){  // Se não encontrou nenhum número igual
        printf("O seu numero nao esta no array\n");  // Informa ao usuário
    }
}

// Função principal
int main (void){
    dobro();     // Lê os números e calcula o dobro
    ordenar();   // Ordena o array b
    pesquisa();  // Pesquisa um número no array b
}
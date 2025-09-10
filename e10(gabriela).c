#include<stdio.h>

int main(){
    int a[10], b[10], x, i, j,
        pesq, encon = 0, meio, inicio = 0, fim = 9;

    printf("Entre com 10 valores: ");

    for(i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
        a[i] = a[i] * 2;
        b[i] = a[i];
    }
    
    for(i = 0; i < 10; i++) {
        for(j = i + 1; j < 10; j++) {
            if(b[i] > b[j]) {
                x = b[i];
                b[i] = b[j];
                b[j] = x;
            }
        }
    }
    
    printf("\nValores ordenados: ");
    for(i = 0; i < 10; i++){
        printf("%d ", b[i]);
    }
    
    printf("\n\nDigite um numero a ser pesquisado: ");
    scanf("%d", &pesq);
    
    
    for (; inicio <= fim; ) {
        meio = (inicio + fim) / 2;
        
        if (b[meio] == pesq) {
            encon = 1;
            printf("O valor esta na posicao: %d\n", meio);
            break; 
        } else if (b[meio] < pesq) { 
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    
    if (encon == 0) {
        printf("Valor nao encontrado :(\n");
    }

    return 0;
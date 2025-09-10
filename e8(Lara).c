código sem função 

#include <stdio.h>

int main() {
    
    int notas[80]; 
    int contadores[11] = {0}; 
    float frequenciaRelativa[11]; 
    int i, nota;

    printf("Digite 80 notas (de 0 a 10):\n");
    for (i = 0; i < 80; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%d", &notas[i]);
        
        if (notas[i] >= 0 && notas[i] <= 10) {
            
            contadores[notas[i]]++;
        } else {
            printf("Digite um valor de 0 a  10.\n");
            i--; 
        }
    }
    
    printf("\n--- Frequências ---\n");
    printf("Nota | Frequência Absoluta | Frequência Relativa\n");

    for (i = 0; i <= 10; i++) {
        
        frequenciaRelativa[i] = (float)contadores[i] / 80.0 * 100.0;

        
        printf("%4d | %17d | %21.2f%%\n", i, contadores[i], frequenciaRelativa[i]);
    }

    return 0; 
}

Código com função 

include <stdio.h>

void lerNotas(int notas[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%d", &notas[i]);
        
        if (notas[i] < 0 || notas[i] > 10) {
            printf("Digite um valor entre 0 a 10.\n");
            i--; 
        }
    }
}

void calcularFrequencias(int notas[], int n, int contadores[], float frequenciaRelativa[]) {
   
    for (int i = 0; i <= 10; i++) {
        contadores[i] = 0;}
    
    for (int i = 0; i < n; i++) {
        contadores[notas[i]]++;}
    
    for (int i = 0; i <= 10; i++) {
        frequenciaRelativa[i] = (float)contadores[i] / n * 100.0;}
}

void imprimirTabela(int contadores[], float frequenciaRelativa[]) {
    
    printf("Nota | Frequência Absoluta | Frequência Relativa\n");
    for (int i = 0; i <= 10; i++) {
        printf("%4d | %17d | %21.2f%%\n", i, contadores[i], frequenciaRelativa[i]);}}

int main() {
    int notas[80];
    int contadores[11];
    float frequenciaRelativa[11];

    printf("Digite 80 notas (de 0 a 10):\n");
    lerNotas(notas, 80);  

    calcularFrequencias(notas, 80, contadores, frequenciaRelativa); 

    imprimirTabela(contadores, frequenciaRelativa); 

    return 0;
}
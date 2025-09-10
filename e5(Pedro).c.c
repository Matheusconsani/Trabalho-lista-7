#include<stdio.h>
void buble_crescente(float *A, float *B, float *C);
void buble_descrescente(float *A, float *B, float *C);
void meio(float *A, float *B, float *C);

int main(){
    float A, B, C;
    int X;
     
    printf("Entre com os valores de A, B e C:\n");
    scanf("%f %f %f", &A, &B, &C);

    printf("Escolha os valores de X do 1 ao 3:\n");

    printf("Ordem crescente\n1- Ordem decrescente\n2- Ordem meio\n3\n");
     scanf("%i", &X);
    while(X != 4){
        switch(X){
            case 1: buble_crescente();
             buble_crescente(&A, &B, &C);
             printf("Os valores em ordem crescente são: %.2f %.2f %.2f", A, B, C);
            break;
            case 2: buble_decrescente(); 
             buble_decrescente(&A, &B, &C);
            printf("Os valores em ordem decrescente são: %.2f %.2f %.2f", A, B, C)
            break;
            case 3: meio();
            meio(&A, &B, &C);
            printf("Os valores ordenados com o maior no meio são: %.2f %.2f %.2f", A, B, C);
            break;
            default: printf("Opcao incorreta\n"); break;
        }
        printf("Selecione outra opcao ou digite 4 para sair\n");
        scanf("%i", &X);
    }
   return 0;
}

void buble_crescente(float *A, float *B, float *C){
    float tam;
     
    if(*A > *B){
        tam = *A;
        *A = *B;
        *B = tam;
    }
    if(*B > *C){
        tam = *B;
        *B = *C;
        *C = tam;
    }
     if(*A > *B){
        tam = *A;
        *A = *B;
        *B = tam;
    }

}

void buble_decrescente(float *A, float *B, float *C){
    float tam;

    if(*A < *B){
        tam = *B;
        *B = *A;
        *A = tam;

    }
    if(*B < *C){
        tam = *C;
        *C = *B;
        *B = tam;
    }
     if(*A < *B){
        tam = *B;
        *B = *A;
        *A = tam;

    }
}

void meio(float *A, float *B, float *C){
    float tam;

    if(*A > *B){
        tam = *A;
        *A = *B;
        *B = tam;
    }
    if(*C < *B){
        tam = *C;
        *C = *B;
        *B = tam;
    }
}
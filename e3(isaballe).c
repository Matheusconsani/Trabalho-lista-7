#include<stdio.h>
#define N 100
int x[N], num;
int i=0;
char comand;

void media();
void maior_menor();
void faixa();
void par_impar();

int main(){
    do{
        printf("\nEntre com a quantidade de valores:\n");
        scanf("%d", &num);
        printf("\nEntre com os valores:\n");
        for(i=0; i<num; i++){
            scanf("%d", &x[i]);
        }
        media();
        maior_menor();
        faixa();
        par_impar();

        printf("\n\nDeseja continuar?(S/N)\n");
        scanf(" %c", &comand);

    } while(comand!='N' && comand!='n');
    return 0;
}

void media(){
    int z=0;
    float y;
    for(i=0; i<num; i++){
        z += x[i];
    }
    y = z/num;
    printf("\nA media dos numeros eh: %.2f\n", y);
}

void maior_menor(){
    int maior = x[0], menor = x[0];
    for(i=1; i<num; i++){
        if(x[i]>maior){
            maior = x[i];
        }
        if(x[i]<menor){
            menor = x[i];
        }
    }
    printf("\nMaior numero: %d", maior);
    printf("\nMenor numero: %d\n", menor);
}

void faixa(){
    int contUM=0, contDOIS=0, contTRES=0, contQUATRO=0, contCINCO=0;
    int somaUM=0, somaDOIS=0, somaTRES=0, somaQUATRO=0, somaCINCO=0;
    for(i=0; i<num; i++){
        if(x[i]<0){
            contUM++;
            somaUM += x[i];
        }
        if(x[i]>=0 && x[i]<15){
            contDOIS++;
            somaDOIS += x[i];
        }
        if(x[i]>=15 && x[i]<100){
            contTRES++;
            somaTRES += x[i];
        }
        if(x[i]>=1000){
            contQUATRO++;
            somaQUATRO += x[i];
        }
        if(x[i]>=101 && x[i]<1000){
            contCINCO++;
            somaCINCO +=x[i];
        }
    }
    printf("\nNa faixa 1 (<0):\n%d elemento(s) - total na faixa: %d", contUM, somaUM);
    printf("\nNa faixa 2 (0-14):\n%d elemento(s) - total na faixa: %d", contDOIS, somaDOIS);
    printf("\nNa faixa 3 (15-100):\n%d elemento(s) - total na faixa: %d", contTRES, somaTRES);
    printf("\nNa faixa 4 (>=1000):\n%d elemento(s) - total na faixa: %d", contQUATRO, somaQUATRO);
    printf("\nNa faixa 5 (101-999):\n%d elemento(s) - total na faixa: %d\n", contCINCO, somaCINCO);
}

void par_impar(){
    int contPAR=0, contIMPAR;
    for(i=0; i<num; i++){
        if(x[i]%2==0){
            contPAR++;
            printf("\nO numero %d eh par.", x[i]);
        } else {
            contIMPAR++;
            printf("\nO numero %d eh impar.\n", x[i]);
        }
    }
    printf("\nQuantidade de numeros pares: %d", contPAR);
    printf("\nQuantidade de numeros impares: %d\n", contIMPAR);
}
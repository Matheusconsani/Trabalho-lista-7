#include <stdio.h>   // Biblioteca padrão de entrada e saída
#include <stdlib.h>  // Biblioteca para funções de alocação dinâmica, system e exit

// Declaração de variáveis globais
int i, *ar = NULL, c = 0, v = 0, m = 0, ma = 0, me = 9999999, f[5] = {0}, cont[5] = {0}, pi[2] = {0}, contpi, caso;
char r;  // Variável para armazenar resposta do usuário

// Declaração de funções
int leitura();
void media();
void maior_menor();
void faixa();
void p_i();
void loop();
void print();

// Função para leitura de valores e alocação dinâmica do array
int leitura(){
    while(1){  // Loop infinito até o usuário decidir parar
        printf("Deseja inserir um novo valor? (s/n):\n");
        scanf(" %c", &r);  // Lê a resposta do usuário
        if(r=='n' || r=='N'){  // Se o usuário digitar 'n' ou 'N', interrompe a leitura
            break;
        }
        else if(r=='S' || r=='s'){  // Se o usuário digitar 's' ou 'S', continua
            printf("Digite o valor:\n");
            scanf("%d", &v);  // Lê o valor a ser adicionado
            // Realoca memória para armazenar mais um inteiro no array
            int *n_ar = (int *)realloc(ar, (c + 1) * sizeof(int));
            if (n_ar == NULL) {  // Verifica se a alocação falhou
                printf("Erro na alocacao de memoria!\n");
                free(ar);  // Libera memória já alocada
                return 1;  // Retorna erro
            }
            ar = n_ar;      // Atualiza o ponteiro para o novo bloco de memória
            ar[c] = v;      // Adiciona o valor lido no array
            c++;            // Incrementa o contador de elementos
        }
    }
}

// Função principal de cálculo de médias, maior/menor, faixas e pares/ímpares
void loop(){
    m = 0;  // Zera a variável da média
    for(i=0;i<c;i++){  // Percorre todos os elementos do array
        media();        // Soma valores para calcular média
        maior_menor();  // Atualiza maior e menor valor
        faixa();        // Atualiza contadores e somatórios por faixa
        p_i();          // Atualiza contagem de pares e ímpares
    }
    m = m / c;  // Calcula a média final
    contpi = pi[0] + pi[1];  // Soma total de números inseridos
}

// Função que soma o valor atual para calcular a média
void media(){
    m += ar[i];    
}

// Função que verifica e atualiza o maior e menor valor
void maior_menor(){
    if(ma < ar[i]){
        ma = ar[i];  // Atualiza maior valor
    }
    if(me > ar[i]){
        me = ar[i];  // Atualiza menor valor
    }
}

// Função que calcula as faixas de valores e somatórios
void faixa(){
    if(ar[i] < 0){            // Faixa de números negativos
        f[0]++;
        cont[0] += ar[i];
    }
    else if(ar[i] >= 0 && ar[i] < 14){   // Faixa 0 a 13
        f[1]++;
        cont[1] += ar[i];
    }
    else if(ar[i] >= 15 && ar[i] <= 100){ // Faixa 15 a 100
        f[2]++;
        cont[2] += ar[i];
    }
    else if(ar[i] >= 101 && ar[i] <= 999){ // Faixa 101 a 999
        f[3]++;
        cont[3] += ar[i];
    }
    else if(ar[i] >= 1000){    // Faixa 1000 ou mais
        f[4]++;
        cont[4] += ar[i];
    }
}

// Função que conta números pares e ímpares
void p_i(){
    if(ar[i] % 2 == 0){  // Verifica se é par
        pi[0]++;
    }
    else{                // Caso contrário é ímpar
        pi[1]++;
    }
}

// Função para exibir os resultados
void print(){
    while(1){  // Loop de interação com o usuário
        printf("\n===============Digite a informacao que voce deseja acessar===============\n");
        printf("=============================== 1. Media ================================\n");
        printf("=========================== 2. Maior e Menor ============================\n");
        printf("=============================== 3. Faixa ================================\n");
        printf("========================== 4. Pares e impares ===========================\n");
        printf("============================= 5. Para sair =============================\n");
        printf("\n");
        scanf("%d", &caso);  // Lê a opção desejada
        if(caso >= 5){  // Sai do loop se a opção for 5 ou mais
            break;
        }
        system("cls");   // Limpa a tela (Windows)
        printf("\n");
        switch (caso){
            case 1: printf("A media dos numeros fornecidos e igual a: %d\n", m); break;
            case 2: 
                printf("O maior numero fornecido e: %d\n", ma);
                printf("E o menor numero fornecido e: %d\n", me);
                break;
            case 3: 
                for(i=0;i<5;i++){  // Mostra cada faixa e seus valores
                    printf("a Faixa %d possui %d elementos, e o total dessa faixa e %d:\n", i+1, f[i], cont[i]);
                }
                break;
            case 4:
                printf("Voce forneceu %d numeros, %d pares e %d impares", contpi, pi[0], pi[1]);
                break;
        }
    }
}

// Função principal
int main (void){
    while(1){  // Loop principal do programa
        printf("\nVoce deseja sair do programa (S/N)");
        scanf(" %c", &r);  // Lê resposta do usuário
        if(r=='S' || r=='s'){  // Se sim, encerra o programa
            break;
        }
        else if(r=='N' || r=='n'){  // Se não, continua
            // Reseta variáveis e libera array antigo
            m = 0;
            c = 0;
            v = 0;
            m = 0;
            ma = 0;
            me = 9999999;
            free(ar);   // Libera memória do array
            ar = NULL;  // Evita ponteiro pendente
            leitura();  // Chama função para inserir novos valores
            system("cls"); // Limpa a tela
            loop();     // Calcula médias, faixas e contadores
            print();    // Mostra os resultados
        }
    }
}
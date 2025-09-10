#include <stdio.h>   // Biblioteca padrão de entrada e saída

int i;              // Variável global usada como índice nos loops
float salnv[3];      // Array para armazenar os novos salários após o aumento

// Definição de uma estrutura para armazenar informações dos funcionários
struct func
{
    char nome[10];   // Nome do funcionário (até 9 caracteres + '\0')
    float salat;     // Salário atual do funcionário
}; 
struct func funcionario[3];  // Array de 3 funcionários

// Função para ler dados dos funcionários
void leitura(){
    for(i=0;i<3;i++){  // Loop para 3 funcionários
        printf("Entre com as informacoes do funcionario %d\n", i);
        printf("Nome: ");
        scanf(" %s", &funcionario[i].nome);  // Lê o nome do funcionário
        printf("Salario atual: ");
        scanf("%f", &funcionario[i].salat);  // Lê o salário atual do funcionário
    }
}

// Função para calcular os novos salários e imprimir informações
void calculo(){
  for(i=0;i<3;i++){  // Loop para percorrer os 3 funcionários
    if(funcionario[i].salat<=400){          // Salário até 400 -> aumento 15%
        salnv[i]=funcionario[i].salat*1.15; // Calcula novo salário
        printf("\nFuncionario %d\n", i+1);  // Imprime número do funcionário
        printf("%s\n", funcionario[i].nome); // Imprime nome
        printf("15%% de aumento\n");          // Informa percentual de aumento
        printf("%.2f", funcionario[i].salat); // Imprime salário antigo
        printf("%.2f", salnv[i]);             // Imprime salário novo
    }
    else if(funcionario[i].salat>400 && funcionario[i].salat<=700){ // 12% de aumento
        salnv[i]=funcionario[i].salat*1.12;
        printf("\nFuncionario %d\n", i+1);
        printf("%s\n", funcionario[i].nome);
        printf("12%% de aumento\n");
        printf("%.2f", funcionario[i].salat);
        printf("%.2f", salnv[i]);
    }
    else if(funcionario[i].salat>700 && funcionario[i].salat<=1000){ // 10% de aumento
        salnv[i]=funcionario[i].salat*1.10;
        printf("\nFuncionario %d\n", i+1);
        printf("%s\n", funcionario[i].nome);
        printf("10%% de aumento\n");
        printf("%.2f", funcionario[i].salat);
        printf("%.2f", salnv[i]);
    }
    else if(funcionario[i].salat>1000 && funcionario[i].salat<=1800){ // 7% de aumento
        salnv[i]=funcionario[i].salat*1.07;
        printf("\nFuncionario %d\n", i+1);
        printf("%s\n", funcionario[i].nome);
        printf("7%% de aumento\n");
        printf("%.2f", funcionario[i].salat);
        printf("%.2f", salnv[i]);
    }
    else if(funcionario[i].salat>1800 && funcionario[i].salat<=2500){ // 4% de aumento
        salnv[i]=funcionario[i].salat*1.04;
        printf("\nFuncionario %d\n", i+1);
        printf("%s\n", funcionario[i].nome);
        printf("4%% de aumento\n");
        printf("%.2f\n", funcionario[i].salat);
        printf("%.2f\n", salnv[i]);
    }
    else if(funcionario[i].salat>2500){ // Acima de 2500 -> sem aumento
        salnv[i]=funcionario[i].salat;   // Salário permanece igual
        printf("\nFuncionario %d\n", i+1);
        printf("%s\n", funcionario[i].nome);
        printf("0%% de aumento\n");       // Informa que não há aumento
        printf("%.2f\n", funcionario[i].salat);
        printf("%.2f\n", salnv[i]);
    }
  }
}

// Função principal
int main (void){
    leitura();  // Chama a função de leitura de dados
    calculo();  // Chama a função de cálculo e exibição dos salários
}
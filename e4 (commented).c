#include <stdio.h>   // Inclui a biblioteca padrão de entrada e saída
int i,p;            // Variáveis globais: 'i' para índices e 'p' para pontuação total
char saida;          // Variável para armazenar a escolha do usuário (S/N)

// Declaração de protótipos de funções
void a(); void b(); void c(); void d(); void e(); void f(); void g(); void jogo();

// Estrutura para representar cada bola
struct bola
{
    char dir;   // Direção da bola ('R' para direita, 'L' para esquerda)
    int pos;    // Canaleta de entrada
    int sai;    // Saída da bola
    int pon;    // Pontos obtidos pela bola
}; 
struct bola bola[5];  // Cria um array de 5 bolas

// Função a() para canaleta 0
void a(){
    if(bola[i].dir=='R'){  // Se a bola estiver indo para a direita
        bola[i].dir='L';   // Muda direção para esquerda
        d();               // Chama função d()
    }
    if(bola[i].dir=='L'){  // Se a bola estiver indo para a esquerda
        bola[i].sai=0;     // Saída da bola é 0
        bola[i].pon=10;    // Pontos obtidos 10
    }
}

// Função b() para um ponto intermediário
void b(){
    if(bola[i].dir=='R'){  // Bola indo para a direita
      bola[i].dir='L';     // Muda direção para esquerda
      g();                 // Chama função g()
    }
    if(bola[i].dir=='L'){  // Bola indo para a esquerda
    bola[i].dir='R';       // Muda direção para direita
    d();                   // Chama função d()
    }
}

// Função c() para canaleta 1
void c(){
    if(bola[i].dir=='R'){  // Bola indo para a direita
        bola[i].dir='L';   // Muda direção para esquerda
        b();               // Chama função b()
    }
    if(bola[i].dir=='L'){  // Bola indo para a esquerda
    bola[i].dir='R';       // Muda direção para direita
    a();                   // Chama função a()
    }
}

// Função d() para definir saídas e pontos intermediários
void d(){
    if(bola[i].dir=='R'){  // Bola indo para a direita
    bola[i].sai=1;         // Saída da bola 1
    bola[i].pon=20;        // Pontos obtidos 20
    }
    if(bola[i].dir=='L'){  // Bola indo para a esquerda
    bola[i].sai=0;         // Saída da bola 0
    bola[i].pon=10;        // Pontos obtidos 10
    }
}

// Função e() para canaleta 2
void e(){
   if(bola[i].dir=='R'){  // Bola indo para a direita
    bola[i].dir='L';      // Muda direção para esquerda
    f();                  // Chama função f()
    }
    if(bola[i].dir=='L'){  // Bola indo para a esquerda
    bola[i].dir='R';       // Muda direção para direita
    c();                   // Chama função c()
    }
}

// Função f() para ponto intermediário
void f(){
   if(bola[i].dir=='R'){  // Bola indo para a direita
    bola[i].dir='L';      // Muda direção para esquerda
    g();                  // Chama função g()
    }
    if(bola[i].dir=='L'){  // Bola indo para a esquerda
    bola[i].dir='R';       // Muda direção para direita
    b();                   // Chama função b()
    }   
}

// Função g() para saídas finais
void g(){
   if(bola[i].dir=='R'){  // Bola indo para a direita
    bola[i].sai=2;        // Saída da bola 2
    bola[i].pon=30;       // Pontos obtidos 30
    }
    if(bola[i].dir=='L'){  // Bola indo para a esquerda
    bola[i].sai=1;         // Saída da bola 1
    bola[i].pon=20;        // Pontos obtidos 20
    }    
}

// Função para ler entrada das 5 bolas
void leitura(){
    for(i=0;i<5;i++){                    // Loop para 5 bolas
        bola[i].dir='R';                 // Inicializa direção para direita
        bola[i].pon=0;                   // Inicializa pontuação 0
        printf("\nEm qual canaleta a bolinha vai entrar?");
        scanf("%d", &bola[i].pos);       // Lê canaleta
        if(bola[i].pos >=0 && bola[i].pos <=2){  // Verifica se canaleta é válida
        jogo();                           // Executa o jogo para essa bola
        }
        else{
            printf("\nEssa entrada nao existe."); // Canaleta inválida
            i--;                              // Repete a leitura da bola
        }
    }
}

// Função para iniciar o jogo baseado na posição
void jogo(){
    if(bola[i].pos==0){  // Canaleta 0
        a();
    }
    if(bola[i].pos==1){  // Canaleta 1
        c();
    }
    if(bola[i].pos==2){  // Canaleta 2
        e();
    }
}

// Função para imprimir a pontuação total
void print(){
    p=0;                     // Inicializa pontuação total
    for(i=0;i<5;i++){        // Loop pelas 5 bolas
        p+=bola[i].pon;      // Soma pontos da bola
    }
    printf("\t===>Seus pontos foram %d<===\n",p);  // Imprime total
}

// Função principal
int main (void){
    while(1){   // Loop principal do programa
        printf("\nVoce deseja sair do programa (S/N)");
        scanf(" %c", &saida);  // Lê escolha do usuário
        if(saida=='S' || saida=='s'){  // Se quiser sair
            break;                    // Sai do loop
        }
         if(saida=='N' || saida=='n'){ // Se não quiser sair
        printf("\n");
        leitura();                   // Lê entradas
        print();                      // Mostra pontos
        }
    }
    printf("\nPrograma encerrando....");  // Mensagem final
}
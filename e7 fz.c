#include <stdio.h>
#include <string.h>

#define TOTAL_FUNC 50
#define TAM_NOME 100

struct Adm {
    char nome[TAM_NOME];
    int idade;
};

// Funções
void cadastrar(struct Adm lista[], int total, int* cadastrados);
void mostre(struct Adm lista[], int total);
void classNome(struct Adm lista[], int total);
void classIdade(struct Adm lista[], int total);
void corrigirCadastro(struct Adm lista[], int total);
void pesquisar(struct Adm lista[], int total);
void listarAposentados(struct Adm lista[], int total);
void listarAtivos(struct Adm lista[], int total);

int main() {
    struct Adm lista[TOTAL_FUNC];
    int opcao;
    int cadastrados = 0;

    do {
        printf("\n----- MENU -----\n");
        printf("1) Cadastrar os 50 administrativos\n");
        printf("2) Exibir todos os administrativos\n");
        printf("3) Classificar por nome\n");
        printf("4) Classificar por idade\n");
        printf("5) Corrigir cadastro\n");
        printf("6) Pesquisar por nome ou idade\n");
        printf("7) Listar aposentados (idade >= 60)\n");
        printf("8) Listar ativos (idade < 60)\n");
        printf("0) Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar(lista, TOTAL_FUNC, &cadastrados);
                break;
            case 2:
                if (cadastrados)
                    mostre(lista, TOTAL_FUNC);
                else
                    printf("?? Cadastre os administrativos!\n");
                break;
            case 3:
                if (cadastrados) {
                    classNome(lista, TOTAL_FUNC);
                    mostre(lista, TOTAL_FUNC);
                } else
                    printf("?? Cadastre os administrativos!\n");
                break;
            case 4:
                if (cadastrados) {
                    classIdade(lista, TOTAL_FUNC);
                    mostre(lista, TOTAL_FUNC);
                } else
                    printf("?? Cadastre os administrativos!\n");
                break;
            case 5:
                if (cadastrados)
                    corrigirCadastro(lista, TOTAL_FUNC);
                else
                    printf("?? Cadastre os administrativos!\n");
                break;
            case 6:
                if (cadastrados)
                    pesquisar(lista, TOTAL_FUNC);
                else
                    printf("?? Cadastre os administrativos!\n");
                break;
            case 7:
                if (cadastrados)
                    listarAposentados(lista, TOTAL_FUNC);
                else
                    printf("?? Cadastre os administrativos!\n");
                break;
            case 8:
                if (cadastrados)
                    listarAtivos(lista, TOTAL_FUNC);
                else
                    printf("?? Cadastre os administrativos!\n");
                break;
            case 0:
                printf("? Encerrando, ate mais :)\n");
                break;
            default:
                printf("? Opcao invalida.\n");
        }
    } while(opcao != 0);

    return 0;
}

void cadastrar(struct Adm lista[], int total, int* cadastrados) {
    printf("\n=== Cadastro de %d Administrativos ===\n\n", total);
    for (int i = 0; i < total; i++) {
        printf("Funcionario %d:\n", i + 1);
        getchar(); // limpar buffer
        printf("Nome: ");
        fgets(lista[i].nome, TAM_NOME, stdin);
        lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &lista[i].idade);
    }
    *cadastrados = 1;
    printf("? Cadastro concluído!\n");
}

void mostre(struct Adm lista[], int total) {
    printf("\n=== Lista de Administrativos ===\n");
    for (int i = 0; i < total; i++) {
        printf("%d - Nome: %s | Idade: %d\n", i + 1, lista[i].nome, lista[i].idade);
    }
}

void classNome(struct Adm lista[], int total) {
    struct Adm temp;
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (strcmp(lista[i].nome, lista[j].nome) > 0) {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

void classIdade(struct Adm lista[], int total) {
    struct Adm temp;
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (lista[i].idade > lista[j].idade) {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

void corrigirCadastro(struct Adm lista[], int total) {
    int indice;
    printf("Digite o número do funcionário para corrigir (1 a %d): ", total);
    scanf("%d", &indice);

    if (indice < 1 || indice > total) {
        printf("? Número inválido.\n");
        return;
    }

    indice--; // ajustar índice
    getchar();

    printf("Novo nome: ");
    fgets(lista[indice].nome, TAM_NOME, stdin);
    lista[indice].nome[strcspn(lista[indice].nome, "\n")] = '\0';

    printf("Nova idade: ");
    scanf("%d", &lista[indice].idade);

    printf("? Cadastro corrigido!\n");
}

void pesquisar(struct Adm lista[], int total) {
    int opcao;
    char nomeBusca[TAM_NOME];
    int idadeBusca;
    int encontrou = 0;

    printf("Pesquisar por:\n1.Nome\n2. Idade\nEscolha: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        getchar();
        printf("Digite o nome a buscar: ");
        fgets(nomeBusca, TAM_NOME, stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

        for (int i = 0; i < total; i++) {
            if (strcmp(lista[i].nome, nomeBusca) == 0) {
                printf("Encontrado: %s - Idade: %d\n", lista[i].nome, lista[i].idade);
                encontrou = 1;
            }
        }
        if (!encontrou) printf("? Nenhum funcionário com esse nome.\n");

    } else if (opcao == 2) {
        printf("Digite a idade a buscar: ");
        scanf("%d", &idadeBusca);

        for (int i = 0; i < total; i++) {
            if (lista[i].idade == idadeBusca) {
                printf("Encontrado: %s - Idade: %d\n", lista[i].nome, lista[i].idade);
                encontrou = 1;
            }
        }
        if (!encontrou) printf("? Nenhum funcionário com essa idade.\n");
    } else {
        printf("? Opcao invalida.\n");
    }
}

void listarAposentados(struct Adm lista[], int total) {
    printf("\n=== Administrativos Aposentados (os 60 mais) ===\n");
    int encontrou = 0;
    for (int i = 0; i < total; i++) {
        if (lista[i].idade >= 60) {
            printf("Nome: %s - Idade: %d\n",
             lista[i].nome, lista[i].idade);
            encontrou = 1;
        }
    }
    if (!encontrou) 
    printf("Nenhum aposentado.\n");
}

void listarAtivos(struct Adm lista[], int total) {
    printf("\n=== Administrativos Ativos (os clt) ===\n");
    int encontrou = 0;
    for (int i = 0; i < total; i++) {
        if (lista[i].idade < 60) {
            printf("Nome: %s - Idade: %d\n",
             lista[i].nome, lista[i].idade);
            encontrou = 1;
        }
    }
    if (!encontrou){
        printf("Nenhum em atividade\n");
    }
}

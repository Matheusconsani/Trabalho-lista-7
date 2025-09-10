#include <stdio.h>

void ler_vetor(float v[], int t) {
    for (int i = 0; i < t; i++) {
        scanf("%f", &v[i]);
    }
}

void ler_matriz(float m[][60], int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%f", &m[i][j]);
        }
    }
}

int esta_na_diagonal(float n, float m[][60], int t) {
    for (int i = 0; i < t; i++) {
        if (m[i][i] == n) {
            return 1;
        }
    }
    return 0;
}

int contar_diferentes_diagonal(float v[], float m[][60], int tv, int tm) {
    int c = 0;
    for (int i = 0; i < tv; i++) {
        if (i > 0 && v[i] == v[i - 1]) {
            continue;
        }
        if (esta_na_diagonal(v[i], m, tm)) {
            c++;
        }
    }
    return c;
}

int main() {
    float v[50];
    float m[60][60];
    int r;

    ler_vetor(v, 50);
    ler_matriz(m, 60, 60);
    r = contar_diferentes_diagonal(v, m, 50, 60);

    printf("Quantidade de numeros diferentes do vetor que aparecem na diagonal: %d\n", r);

    return 0;
}
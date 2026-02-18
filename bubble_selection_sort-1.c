#include <stdio.h>
#include <time.h>

long long comparacoes;
long long movimentacoes;

/* Função para preencher vetor em ordem decrescente */
void preencherVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

/* Bubble Sort */
void bubbleSort(int vetor[], int tamanho) {
    comparacoes = 0;
    movimentacoes = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            comparacoes++;
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                movimentacoes++;
            }
        }
    }
}

/* Selection Sort */
void selectionSort(int vetor[], int tamanho) {
    comparacoes = 0;
    movimentacoes = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            comparacoes++;
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
            movimentacoes++;
        }
    }
}

void executarTeste(int tamanho) {
    int vetor[tamanho];
    clock_t inicio, fim;
    double tempo_ms;

    /* Bubble Sort */
    preencherVetor(vetor, tamanho);

    inicio = clock();
    bubbleSort(vetor, tamanho);
    fim = clock();

    tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    printf("Bubble Sort | %d | %.2f ms | %lld | %lld\n",
           tamanho, tempo_ms, comparacoes, movimentacoes);

    /* Selection Sort */
    preencherVetor(vetor, tamanho);

    inicio = clock();
    selectionSort(vetor, tamanho);
    fim = clock();

    tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    printf("Selection Sort | %d | %.2f ms | %lld | %lld\n",
           tamanho, tempo_ms, comparacoes, movimentacoes);
}

int main() {
    printf("Algoritmo | Tamanho | Tempo(ms) | Comparacoes | Movimentacoes\n");

    executarTeste(100);
    executarTeste(1000);
    executarTeste(10000);

    return 0;
}

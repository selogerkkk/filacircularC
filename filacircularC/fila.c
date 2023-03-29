#include <stdio.h>
#include <stdlib.h>

// Estrutura de dados heterogênea
typedef struct
{
  int inicio;
  int *dados;
  int fim;
} FilaCircular;

// Funções para manipular a fila circular
FilaCircular *criarFila(int tamanho)
{
  FilaCircular *fila = (FilaCircular *)malloc(sizeof(FilaCircular));
  fila->inicio = 0;
  fila->dados = (int *)malloc(tamanho * sizeof(int));
  fila->fim = 0;
  return fila;
}

int estaCheia(FilaCircular *fila, int tamanho)
{
  return (fila->fim + 1) % tamanho == fila->inicio;
}

int estaVazia(FilaCircular *fila)
{
  return fila->inicio == fila->fim;
}

void enfileirar(FilaCircular *fila, int elemento, int tamanho)
{
  if (!estaCheia(fila, tamanho))
  {
    fila->dados[fila->fim] = elemento;
    fila->fim = (fila->fim + 1) % tamanho;
  }
  else
  {
    printf("Fila cheia!\n");
  }
}

int desenfileirar(FilaCircular *fila, int tamanho)
{
  if (!estaVazia(fila))
  {
    int elemento = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % tamanho;
    return elemento;
  }
  else
  {
    printf("Fila vazia!\n");
    return -1;
  }
}

void destruirFila(FilaCircular *fila)
{
  free(fila->dados);
  free(fila);
}

void mostrarFila(FilaCircular *fila, int tamanho)
{
  if (!estaVazia(fila))
  {
    printf("Fila:\n");
    for (int i = fila->inicio; i != fila->fim; i = (i + 1) % tamanho)
    {
      printf("%d ", fila->dados[i]);
    }
    printf("\n");
  }
  else
  {
    printf("Fila vazia!\n");
  }
}

int main()
{
  int tamanho = 5;
  FilaCircular *fila = criarFila(tamanho);

  enfileirar(fila, 1, tamanho);
  enfileirar(fila, 71, tamanho);
  enfileirar(fila, 23, tamanho);
  desenfileirar(fila, tamanho);

  enfileirar(fila, 65, tamanho);
  enfileirar(fila, 21, tamanho);
  desenfileirar(fila, tamanho);
  mostrarFila(fila, tamanho);
  destruirFila(fila);

  return 0;
}
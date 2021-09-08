#include <stdlib.h>
#include <stdio.h>

typedef struct processo {
  int numero;
  int tempo;
}Processo;

typedef struct no {
  Processo info;
  struct no *proximo;
}No;

typedef No* Lista;

No* criaNo(Processo valor) {
  No *n = (No *)malloc(sizeof(No));
  n->proximo = NULL;
  n->info = valor;
  return n;
}

Lista iniciaLista() {
  No *l = NULL;
  return l;
}

void inserir(Lista* li, Processo i) {
  No* novo = (No*) malloc(sizeof(No));
  novo->info = i;
  novo->proximo = NULL;
  
  if ((*li) == NULL) (*li) = novo; 
  else {
    No* aux = (*li);
    while (aux->proximo != NULL) aux = aux->proximo;
    aux->proximo = novo;
  }
}

No* remover(Lista* li) {
  if (*li == NULL) return NULL;

  No* pos = *li;
  No* prox = (*li)->proximo;

  *li = (*li)->proximo;
  
  pos->proximo = NULL;
  return pos;
}

void executaProcessos(Lista li) {
  printf("aqui\n");
  while (li != NULL) {
    No* n = remover(&li);
    
    if (n->info.tempo > 20) {
      printf("Executando processo #P%d – %dut \n", n->info.numero, 20);
      n->info.tempo-=20;
      inserir(&li, n->info);
    } else printf("Executando processo #P%d – %dut \n", n->info.numero, n->info.tempo);
  
    free(n);
  }
}

Processo criaProcesso(int numero, int tempo) {
  Processo novo;
  novo.numero = numero;
  novo.tempo = tempo;
  return novo;
}

int main() {
  Processo p1 = criaProcesso(1, 58);
  Processo p2 = criaProcesso(2, 20);
  Processo p3 = criaProcesso(3, 40);
  Processo p4 = criaProcesso(4, 15);
  
  Lista lista = iniciaLista();
  inserir(&lista, p1);
  inserir(&lista, p2);
  inserir(&lista, p3);
  inserir(&lista, p4);

  printf("Fila de Processos à P2 (20) à P3 (40) à P4 (15) à P1 (38)\n");
  executaProcessos(lista);

  return 0;
}
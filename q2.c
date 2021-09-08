#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct no {
  int valor;
  struct node *proximo;
  struct node *anterior;
}No;

typedef No* Lista;

No* criaNo(int valor) {
  No *n = (No *)malloc(sizeof(No));
  n->proximo = NULL;
  n->anterior = NULL;
  n->valor = valor;
  return n;
}

Lista iniciaLista() {
  No *l = NULL;
  return l;
}

void insere() {

}

void remove() {

}

int main() {

  return 0;
}
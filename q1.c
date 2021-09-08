#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int info;
  struct no *proximo;
}No;

typedef No* Lista;

Lista iniciaLista() {
  No *l = NULL;
  return l;
}

int insereFinal(Lista* li, int i) {  
  if ((*li) == NULL) {
    *li = (No*) malloc(sizeof(No));
    (*li)->info = i;
    (*li)->proximo = NULL;
  } else {
    No* aux = (*li);
    while (aux->proximo != NULL) {
      if (aux->info == i) {
        aux = NULL;
        return 0;
      }
      aux = aux->proximo;
    } 
    if (aux != NULL) {
      aux->proximo = (No*) malloc(sizeof(No));
      aux->proximo->info = i;
      aux->proximo->proximo = NULL;
    } 
  }
  return 1;
}

void imprimeLista(Lista *li){
  No* aux = *li;
  while(aux != NULL){
    printf(" -> %d", aux->info);
    aux = aux->proximo;
  }
  printf("\n");
}

void intercala(Lista *li_1, Lista *li_2){
  No *aux_1, *aux_2, *aux;
  aux_1 = (*li_1);
  aux_2 = (*li_2);

  while(aux_1 != NULL) {
    aux = aux_1->proximo;
    aux_1->proximo = aux_2;
    aux_1 = aux;

    aux = aux_2->proximo;
    aux_2->proximo = aux_1;
    aux_2 = aux;
  }
}

void imprimeListaReversaInterno(No* n){
  if (n->proximo != NULL) imprimeListaReversaInterno(n->proximo);
  printf(" -> %d", n->info);
}

void imprimeListaReverso(Lista *li){
  imprimeListaReversaInterno(*li);
  printf("\n");
}

int main(){
  int numInteiros, num;

  Lista L1 = iniciaLista();
  Lista L2 = iniciaLista();

  printf("Quantos números inteiros cada lista terá? ");
  scanf("%d", &numInteiros);
  printf("\n=== LISTA 1 ===\n");
  for(int i = 0; i<numInteiros; i++){
    printf("Digite um número: ");
    scanf("%d", &num);
    if(!insereFinal(&L1, num)){
      printf("Repita\n");
      i--;
    }
  }
  printf("\n=== LISTA 2 ===\n");
  for(int i = 0; i<numInteiros; i++){
    printf("Digite um número: ");
    scanf("%d", &num);
    if(!insereFinal(&L2, num)){
      printf("Repita\n");
      i--;
    }
  }

  printf("L1\n");
  imprimeLista(&L1);

  printf("L2\n");
  imprimeLista(&L2);

  intercala(&L1, &L2);
  printf("RESULTANTE \n");
  imprimeListaReverso(&L1);

  return 0;
}
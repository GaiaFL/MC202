#include "heap.h"

p_fp criar_heap(int quant){
  p_fp novo;
  novo = malloc(sizeof(Heap));/*Aloca heap*/
  if(novo == NULL){
    exit(1);
  }
  novo->caixas = malloc(quant*sizeof(Item));/*Aloca vetor de items*/
  if(novo->caixas == NULL){
    exit(1);
  }
  novo->tam = 0;
  return novo;
}

void destruir(p_fp heap){
  free(heap->caixas);
  free(heap);
}

Item criar_item(int x, char *c){
  Item novo;
  novo.peso = x;
  strcpy(novo.nome, c);
  return novo;
}

void troca(Item *a, Item *b){
  Item temp = *a;
  *a = *b;
  *b = temp;
}

Item remover(p_fp heap){
  Item x = heap->caixas[0];
  heap->tam--;
  troca(&heap->caixas[0], &heap->caixas[heap->tam]);
  return x;
}

void sobe_no_heap_max(p_fp heap, int pos){
  if(pos>0 && heap->caixas[Pai(pos)].peso < heap->caixas[pos].peso){/*pai maior*/
    troca(&heap->caixas[pos], &heap->caixas[Pai(pos)]);
    sobe_no_heap_max(heap, Pai(pos));
  }
}

void sobe_no_heap_min(p_fp heap, int pos){
  if(pos>0 && heap->caixas[Pai(pos)].peso > heap->caixas[pos].peso){/*pai menor*/
    troca(&heap->caixas[pos], &heap->caixas[Pai(pos)]);
    sobe_no_heap_min(heap, Pai(pos));
  }
}

void desce_no_heap_max(p_fp heap, int pos){
  int maior_filho;
  if(F_ESQ(pos) < heap->tam){
    maior_filho = F_ESQ(pos);
    if(F_DIR(pos) < heap->tam && heap->caixas[F_ESQ(pos)].peso < heap->caixas[F_DIR(pos)].peso){
      maior_filho = F_DIR(pos);
    }if(heap->caixas[pos].peso < heap->caixas[maior_filho].peso){
      troca(&heap->caixas[pos], &heap->caixas[maior_filho]);
      desce_no_heap_max(heap, maior_filho);
    }
  }
}

void desce_no_heap_min(p_fp heap, int pos){
  int maior_filho;
  if(F_ESQ(pos) < heap->tam){
    maior_filho = F_ESQ(pos);
    if(F_DIR(pos) < heap->tam && heap->caixas[F_ESQ(pos)].peso > heap->caixas[F_DIR(pos)].peso){
      maior_filho = F_DIR(pos);
    }if(heap->caixas[pos].peso > heap->caixas[maior_filho].peso){
      troca(&heap->caixas[pos], &heap->caixas[maior_filho]);
      desce_no_heap_min(heap, maior_filho);
    }
  }
}

void insere_max(p_fp heap, Item item){
  heap->caixas[heap->tam] = item;
  heap->tam++;
  sobe_no_heap_max(heap, heap->tam-1);
}

void insere_min(p_fp heap, Item item){
  heap->caixas[heap->tam] = item;
  heap->tam++;
  sobe_no_heap_min(heap, heap->tam-1);
}

void imprime(p_fp heap1, p_fp heap2){
  if( heap1->tam == heap2->tam){/*Imprime a primeira posição de ambos heaps*/
    printf("%s: %d\n", heap1->caixas[0].nome, heap1->caixas[0].peso);
    printf("%s: %d\n", heap2->caixas[0].nome, heap2->caixas[0].peso);
  }else{
    if(heap1->tam > heap2->tam){/*Imprime a primeira posição do heap de maior tamanho*/
      printf("%s: %d\n", heap1->caixas[0].nome, heap1->caixas[0].peso);
    }else{
      printf("%s: %d\n", heap2->caixas[0].nome, heap2->caixas[0].peso);
    }
  }
}

int pegarmediana(p_fp heap1, p_fp heap2){
  int x;
  if(heap1->tam == heap2->tam){
    x = (heap1->caixas[0].peso + heap2->caixas[0].peso)/2;
  }else{
    if(heap1->tam > heap2->tam){
      x = heap1->caixas[0].peso;
    }else{
      x = heap2->caixas[0].peso;
    }
  }
  return x;
}

void tamanhos(p_fp heap1, p_fp heap2){
  Item elemento;
  if(abs(heap1->tam - heap2->tam) > 1){
    if(heap1->tam > heap2->tam){
      elemento = remover(heap1);
      insere_max(heap2, elemento);
      desce_no_heap_min(heap1, 0);
    }else{
      elemento = remover(heap2);
      insere_min(heap1, elemento);
      desce_no_heap_max(heap2, 0);
    }
  }
}

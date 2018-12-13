#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define Pai(i) ((i-1)/2)
#define F_ESQ(i) (2*i+1)
#define F_DIR(i) (2*i+2)

typedef struct{
  int peso;
  char nome[MAX];
} Item;

typedef struct{
  Item *caixas;
  int tam;
} Heap;
typedef Heap *p_fp;

/*
  Aloca na memória um novo heap.
  Entrada: quant: tamanho do heap;
  Saída: Novo heap
*/
p_fp criar_heap(int quant);

/*
  Libera da memória o heap alocado.
  Entrada: heap: vetor que quer desalocar;
*/
void destruir(p_fp heap);

/*
  Insere o nome e o peso da nova caixa que vai ser inserida no heap.
  Entrada: x: representa o peso da caixa;
          c: string que representa o nome do produto da caixa;
  Saída: A caixa com suas informações já setadas
*/
Item criar_item(int x, char *c);

/*
  Troca de posição entre dois items do heap.
  Entrada: a: endereço do primeiro item no heap;
          b: endereço do segundo item no heap;
*/
void troca(Item *a, Item *b);

/*
  Remove o item da primeira posição do heap.
  Entrada: heap: vetor de items;
  Saída: o item da primeira posição
*/
Item remover(p_fp heap);

/*
  Organiza a ordem do heap de máximo após a inserção de um novo item.
  Entrada: heap: vetor de items;
          pos: posição do pai do item, se existir, no heap;
*/
void sobe_no_heap_max(p_fp heap, int pos);

/*
  Organiza a ordem do heap de mínimo após a inserção de um novo item.
  Entrada: heap: vetor de items;
          pos: posição do pai do item, se existir, no heap;
*/
void sobe_no_heap_min(p_fp heap, int pos);

/*
  Organiza a ordem do heap de máximo após a remoção do item da primeira posição.
  Entrada: heap: vetor de items;
          pos: a posição do filho do item, se existir, que apresentar maior prioridade(peso);
*/
void desce_no_heap_max(p_fp heap, int pos);

/*
  Organiza a ordem do heap de mínimo após a remoção do item da primeira posição.
  Entrada: heap: vetor de items;
          pos: a posição do filho do item, se existir, que apresentar maior prioridade(peso);
*/
void desce_no_heap_min(p_fp heap, int pos);

/*
  Insere um novo item no heap de máximo.
  Entrada: heap: vetor de items onde ocorrerá a inserção;
          item: item(caixa) que será inserido no heap;
*/
void insere_max(p_fp heap, Item item);

/*
  Insere um novo item no heap de mínimo
  Entrada: heap: vetor de items onde ocorrerá a inserção;
          item: item(caixa) que será inserido no heap;
*/
void insere_min(p_fp heap, Item item);

/*
  Imprime as primeiras posições dos heaps, de acordo com a diferença de tamanho.
  Entrada: heap1: heap de máximo;
          heap2: heap de mínimo;
*/
void imprime(p_fp heap1, p_fp heap2);

/*
  Calcula a mediana após a inserção de um novo item.
  Entrada: heap1: heap de mínimo;
          heap2: heap de máximo;
  Saída: nova mediana dos heaps
*/
int pegarmediana(p_fp heap1, p_fp heap2);

/*
  Verifica se a diferença de tamanho entre os dois heaps é maior do que um item.
  Se for, garante a remoção de itens do heap de maior tamanho e a inserção
  destes no heap de menor.
  Entrada: heap1: heap de mínimo;
          heap2: heap de máximo;
*/
void tamanhos(p_fp heap1, p_fp heap2);

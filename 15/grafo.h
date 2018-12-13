#include <stdlib.h>
#include <stdio.h>

typedef struct No{
  int v;/*Posição da pessoa*/
  struct No *prox;
}No;
typedef No *p_no;

typedef struct{
  p_no *adjacencia;/*Lista de posições com seus relacionamentos*/
  int n;/*Número de pessoas no grafo*/
}Grafo;
typedef Grafo *p_grafo;

/*
  Aloca memória para grafo.
  Entrada: tam: tamanho do vetor do grafo;
  Saída: Grafo alocado na memória
*/
p_grafo criar_grafo(int tam);

/*
  Insere relacionamento entre duas posições na lista ligada de uma deles.
  Entrada: lista: lista ligada de determinada posição do vetor adjacencia;
          int v:posição da outra pessoa no vetor;
  Saída:Nó com posição de uma das pessoas e ponteiro apontado para lista
*/
p_no insere_na_lista(p_no lista , int v);

/*
  Insere relacionamento entre duas pessoas na posição de cada uma.
  Entrada: g: grafo;
          u: posição de uma delas no vetor;
          v: posição da outra;
*/
void insere_aresta(p_grafo g, int u, int v);

/*
  Libera da memória lista ligada de determinada posição do vetor de adjacencia.
  Entrada: lista: lista ligada;
  */
void libera_lista(p_no lista);

/*
  Desaloca da memória a estrutura do grafo.
  Entrada: g: grafo;
*/
void destruir_grafo(p_grafo g);

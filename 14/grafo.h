#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int v;
  struct No *prox;
  int flag;/*Guarda a situação da posição*/
}No;
typedef No *p_no;

typedef struct{
  p_no *adjacencia;
  int n;
}Grafo;
typedef Grafo *p_grafo;

/*
  Aloca memória para grafo.
  Entrada: tam: tamanho do vetor do grafo;
  Saída: Grafo alocado na memória
*/
p_grafo criar_grafo(int tam);

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

/*
  Insere relacionamento entre duas posições na lista ligada de uma deles.
  Entrada: lista: lista ligada de determinada posição do vetor adjacencia;
          int v:posição da outra pessoa no vetor;
  Saída:Nó com posição e situação de uma das pessoas e ponteiro apontado para lista
*/
p_no insere_na_lista(p_no lista , int v) ;

/*
  Insere relacionamento entre duas pessoas na posição de cada uma.
  Entrada: g: grafo;
          u: posição de uma delas no vetor;
          v: posição da outra;
*/
void insere_aresta(p_grafo g, int u, int v);

/*
  Verifica se há ligação entre duas pessoas, dada suas posições no vetor.
  Entrada: g: grafo;
          u: posição de uma delas;
          v: posição da outra;
  Saída:Retorna '1' se tiver relacionamento entre as duas pessoas.Caso contrário, retorna '0';
*/
int tem_aresta(p_grafo g, int u, int v);

/*
  Imprime a posição das pessoas entediadas.
  Entrada: g: grafo;
*/
void imprime_arestas(p_grafo g);

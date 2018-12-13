#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  struct No *dir, *esq;
  int chave;
  int prio;/*prioridade do nó*/
}No;
typedef No *p_no;

/*
  Rotaciona o nó esquerdo para a direita.
  Entrada: no: nó atual;
  Saída: subárvore esquerda já rotacionada
*/
p_no rotacione_dir(p_no no);

/*
  Rotaciona o nó direito para a esquerda.
  Entrada: no: nó atual;
  Saída: subárvore direita já rotacionada
*/
p_no rotacione_esq(p_no no);

/*
  Insere um novo nó na árvore, setando sua chave, prioridade e posição na árvore.
  Caso a nova inserção faça a propriedade de heap máxima ser perdida, haverá
  rotação das subárvores que contenham o novo nó.
  Entrada: no: nó onde acontecerá a inserção do novo nó;
          x: a chave do novo nó;
  Saída: novo nó com suas informações setadas
*/
p_no inserir(p_no no, int x);

/*
  Verifica se o nó com a chave especificada está contido na árvore.
  Entrada: raiz: árvore de busca;
           x: chave do nó procurado;
  Saída: '0' se a chave não estiver contida na árvore, '1' se estiver
*/
int procurar(p_no raiz, int x);

/*
  Compara os conjuntos númericos de duas árvore e insere a diferença simétrica
  em outro conjunto.
  Entrada: n1: árvore com conjunto númerico;
           n2: árvore com conjunto númerico;
           raiz: conjunto vazio onde será inserido a diferença simétrica;
  Saída: Conjunto da diferença simétrica
*/
p_no comparar(p_no n1, p_no n2, p_no raiz);

/*
  Desaloca da memória a árvore binária.
  Entrada: no: árvore binária;
  Saída: árvore com seus nós setados para NULL
*/
p_no liberar_arvore(p_no no);

/*
  Copia uma árvore para uma árvore vazia.
  Entrada: no: árvore que será clonada;
  Saída: clone da árvore de entrada
*/
p_no clonar(p_no no);

/*
  Imprime a árvore em ordem descrescente de chave.
  Entrada: no: árvore que será impressa;
*/
void imprime(p_no no);

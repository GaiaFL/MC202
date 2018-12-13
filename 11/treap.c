#include "treap.h"

p_no rotacione_dir(p_no no){/*Rotaciona para a direita*/
  p_no y = no->esq;
  no->esq = y->dir;
  y->dir = no;
  return y;
}

p_no rotacione_esq(p_no no){/*Rotaciona para a esquerda*/
  p_no y = no->dir;
  no->dir = y->esq;
  y->esq = no;
  return y;
}

p_no inserir(p_no no, int x){/*Insere novo nó*/
  p_no novo;
  if(no == NULL){
    novo = malloc(sizeof(No));
    if(novo == NULL){
      exit(1);
    }
    novo->esq = NULL;
    novo->dir = NULL;
    novo->chave = x;
    novo->prio = rand();
    return novo;
  }
  if(x < no->chave){
    no->esq = inserir(no->esq, x);/*Insere no nó esquerdo*/
    if(no->esq->prio > no->prio)/*Se a propriedade de heap máxima for quebrada*/
      no = rotacione_dir(no);
  }else{
    if(x > no->chave){
      no->dir = inserir(no->dir, x);/*Insere no nó direito*/
      if(no->dir->prio > no->prio)/*Se a propriedade de heap máxima for quebrada*/
        no = rotacione_esq(no);
    }
  }
  return no;
}

int procurar(p_no raiz, int x){/*Verifica se o nó com a chave já está na árvore*/
  if(raiz == NULL){/*Se não achar a chave, devolve falso*/
    return 0;
  }
  if(raiz->chave == x){/*Se achar a chave, devolve verdadeiro*/
    return 1;
  }
  if(raiz->chave < x){/*Se a chave for maior do que a chave do nó atual, procura no nó direito*/
    return procurar(raiz->dir, x);
  }else{/*Se a chave for menor, procura no nó esquerdo*/
    return procurar(raiz->esq, x);
  }
}

p_no comparar(p_no n1, p_no n2, p_no raiz){/*Encontra a diferença simétrica das duas árvores*/
  if(n2 != NULL){
    raiz = comparar(n1, n2->esq, raiz);
    raiz = comparar(n1, n2->dir, raiz);
    if(procurar(n1, n2->chave) == 0){/*Se a chave não estiver na árvore, adiciona no conjunto vazio*/
      raiz = inserir(raiz, n2->chave);
    }
  }
  return raiz;
}

p_no liberar_arvore(p_no no){/*Destrói árvore*/
  if(no == NULL){
    return NULL;
  }
  no->esq = liberar_arvore(no->esq);/*Libera nós esquerdos*/
  no->dir = liberar_arvore(no->dir);/*Libera nós direitos*/
  if(no->esq == NULL && no->dir == NULL){
    free(no);
    no = NULL;
  }
  return no;
}

p_no clonar(p_no no){/*Clona uma árvore binária para uma vazia*/
  p_no temp;
  if(no == NULL){
    return no;
  }
  temp = malloc(sizeof(No));
  if(temp == NULL){
    exit(1);
  }
  temp->chave = no->chave;
  temp->prio = no->prio;
  temp->esq = clonar(no->esq);
  temp->dir = clonar(no->dir);
  return temp;
}

void imprime(p_no no){/*Imprime na ordem descrescente das chaves*/
  if(no == NULL)
    return;
  imprime(no->dir);
  printf("%d ", no->chave);
  imprime(no->esq);
}

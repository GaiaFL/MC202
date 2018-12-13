#ifndef PILHA_H
#define PILHA_H

typedef struct{
  int *v;
  int topo;
}Pilha;
typedef Pilha *p_pilha;

/*
  Cria o baralho vazio para armazenamento

  Entrada: tamanho: a quantidade de cartas;

  Saída: Baralho vazio
*/
p_pilha criarpilha(int tamanho);

/*
  Armazena a carta no baralho(pilha)

  Entrada: p: pilha;
          x: carta em seu valor no tipo int;
*/
void empilhar(p_pilha p, int x);

/*
  Retirna a carta do topo do baralho(pilha)

  Entrada: p: pilha;

  Saída: Carta do topo da pilha
*/
int desempilhar(p_pilha p);

/*
  Destrói pilha

  Entrada: p: pilha;
*/  
void liberar_pilha(p_pilha p);

#endif

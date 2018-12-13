#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"
#include "jogador.h"

int main(){
  int num,  n_cartas, n_jogadores, i, *resultados, deck;
  char carta[2], acao[2];
  p_fila mesa;
  p_pilha baralho;
  scanf("%d %d", &n_cartas, &n_jogadores);
  mesa = criarfila();/*inicializa a fila vazia*/
  baralho = criarpilha(n_cartas);/*inicializa a pilha vazia*/
  n_jogadores++;
  resultados = criarvetor(n_jogadores);/*cria o vetor de armazenamento dos jogadores*/
  for(i=0; i<n_cartas; i++){/*empilhar as cartas*/
    scanf("%s", carta);
    num = numera_carta(carta);
    empilhar(baralho, num);
  }
  for(i=0; i<n_jogadores;i++){/*primeira mão*/
    num = desempilhar(baralho);
    enfileira(mesa, num);
  }
  for(i=0; i<n_jogadores; i++){/*segunda mao*/
    deck = mesa->ini->mao;
    num = desempilhar(baralho);
    if(num == 11){
      mesa->ini->as++;
    }
    deck = soma(deck, num);
    if(deck == 21){
      resultados[mesa->ini->play] = deck;/*armazena o resultado na posição do jogador*/
      desenfileira(mesa);
    }
    else{
      mesa->ini->mao = deck;
      troca(mesa);
    }
  }
  scanf("%s", acao);
  while(acao[0] != '#'){/*Rodada de escolha*/
    if(mesa->ini != NULL){
      deck = mesa->ini->mao;
      if(acao[0] == 'H'){
        num = desempilhar(baralho);
        if(num == 11){
          mesa->ini->as++;
        }
        deck = soma(deck, num);
        if(deck >= 21){
          if(mesa->ini->as > 0){
            while(mesa->ini->as != 0 && deck > 21){
              deck -= 10;
              mesa->ini->as--;
            }
            if(deck >= 21){
              resultados[mesa->ini->play] = deck;
              desenfileira(mesa);
            }else{
              mesa->ini->mao = deck;
              troca(mesa);
            }
          }else{
            resultados[mesa->ini->play] = deck;
            desenfileira(mesa);
          }
        }else{
          mesa->ini->mao = deck;
          troca(mesa);
        }
      }else if(acao[0] == 'S'){
        resultados[mesa->ini->play] = deck;
        desenfileira(mesa);
      }else{
        num = numera_carta(acao);
        empilhar(baralho, num);
      }
    }
    scanf("%s", acao);
  }
  resto(mesa, resultados);/*armazena os jogadores que não pediram stand*/
  imprimir(resultados, n_jogadores);/*imprime o vetor dos resultados*/
  liberar_fila(mesa);
  liberar_vetor(resultados);
  liberar_pilha(baralho);
  return 0;
}

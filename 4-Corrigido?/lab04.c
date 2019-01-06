#include "acao.h"
#include "portfolio.h"
#include <stdio.h>
int main(){
  char nome[MAX_SIZE_NAME], sobrenome[MAX_SIZE_NAME];
  int i, acoes;
  acao b;
  portfolio a;
  scanf("%s %s", nome, sobrenome);
  a = criar_portfolio(nome, sobrenome);/*Cria portfolio*/
  scanf("%d\n", &acoes);
  for(i = 0; i < acoes; i++){
    a = adicionar_acao(a, b);/*Adiciona a ação com suas variações já setadas no portfolio*/
    a.n_acoes++;/*Incrementa o número de ações adicionadas no portfolio*/
  }
  criar_relatorio(a);/*Cria relatório final do portfolio*/
  return 0;
}

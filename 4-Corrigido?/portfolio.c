#include <stdio.h>
#include <string.h>
#include "portfolio.h"
#include "acao.h"

portfolio criar_portfolio(char nome[], char sobrenome[]){/*Seta as informações no portfolio*/
  portfolio c;
  strcpy(c.nome, nome);
  strcpy(c.sobrenome, sobrenome);
  c.n_acoes = 0;
  return c;
}

portfolio adicionar_acao(portfolio p, acao a){/*Adiciona no portfolio a ação*/
  int i, variacoes;
  char nome[MAX_SIZE_NAME];
  double investimento, variacao;
  scanf("%s %lf", nome, &investimento);
  a = criar_acao(nome, investimento);/*Cria ação*/
  scanf("%d", &variacoes);
  for(i = 0; i < variacoes; i++){
    scanf("%lf", &variacao);
    a = adicionar_variacao(a, variacao);/*Adiciona as variações na ação*/
    a.n_variacoes++;
  }
  p.acoes[p.n_acoes] = a;/*Adiciona a ação no portfolio*/
  return p;
}

void criar_relatorio(portfolio p){/*Cria relatório final sobre o portfolio*/
  int i, acoes = p.n_acoes;
  printf("Relatorio de %s %s\n", p.nome, p.sobrenome);
  for(i = 0; i < acoes; i++){
    reportar_acao(p.acoes[i]);/*Reporta ações*/
  }
}

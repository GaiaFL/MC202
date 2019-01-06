#include <stdio.h>
#include <string.h>
#include "portfolio.h"
#include "acao.h"

acao criar_acao(char nome[], double investimento){/*Seta as informações da ação*/
  acao c;
  strcpy(c.nome, nome);
  c.investimento = investimento;
  c.n_variacoes = 0;
  return c;
}

acao adicionar_variacao(acao a, double variacao){/*Adiciona a variação na memória da ação*/
  a.variacoes[a.n_variacoes] = variacao;
  return a;
}

void reportar_acao(acao a){/*Reporta ação*/
  double novoinvest = a.investimento, porcento = 1.0, variacao;
  int i, variacoes = a.n_variacoes;
  for(i = 0; i < variacoes; i++){
    variacao = a.variacoes[i]/100;/*Calcula o decimal variação*/
    novoinvest = novoinvest * (porcento+variacao);/*Adiciona no investimento a variação*/
  }
  if(a.investimento > novoinvest){/*Vê se o valor investido é maior do que o final*/
    printf("%s %.2f PERDA\n", a.nome, novoinvest);
  }else{
    printf("%s %.2f GANHO\n", a.nome, novoinvest);
  }
}

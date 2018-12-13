#include "hash.h"

data criar_dado(char x, char y, char c[], char d[]){/*Seta informação no novo dado*/
  data novo;
  novo.chave1 = x;
  strcpy(novo.chave2, c);
  novo.coautor1 = y;
  strcpy(novo.coautor2, d);
  novo.flag = 0;/*Seta posição como 'ocupada'*/
  return novo;
}

void coautores(p_hash hash, int x, data *vetor){/*Cria pares de coautores e adiciona esse dado no hash*/
  int chave, h, g;
  char nome1, nome2, sobrenome1[MAX], sobrenome2[MAX];
  data novo;
  for(h = 0; h<x; h++){
    for(g = h+1; g<x; g++){
      nome1 = vetor[h].coautor1;/*Primeiro coautor*/
      strcpy(sobrenome1, vetor[h].coautor2);
      chave = strlen(sobrenome1);
      nome2 = vetor[g].coautor1;/*Segundo coautor*/
      strcpy(sobrenome2, vetor[g].coautor2);
      novo = criar_dado(nome1, nome2, sobrenome1, sobrenome2);/*Cria novo dado*/
      inserir(hash, chave, novo);/*Insere dado no hash*/
    }
  }
}

char consultar(p_hash hash){/*Faz a consulta da coautoria dos autores*/
  char resposta, separador, nome1, nome2, sobrenome1[MAX], sobrenome2[MAX];
  scanf(" %c. %[^.,]%c", &nome1, sobrenome1, &separador);
  scanf(" %c. %[^.,]%c", &nome2, sobrenome2, &separador);
  resposta = buscar(hash, nome1, nome2, sobrenome1, sobrenome2);/*Primeira pesquisa*/
  if(resposta == 'N')/*Se a resposta da primeira pesquisa foi negativa, procura mais uma vez, invertendo a posição dos nomes agora*/
    resposta = buscar(hash, nome2, nome1, sobrenome2, sobrenome1);/*Segunda pesquisa*/
  return resposta;/*Retorna resposta da pesquisa*/
}


int main(){
  int artigos, consultas, i, chave, j;
  char nome1, nome2, sobrenome1[MAX], sobrenome2[MAX], separador, resposta;
  data novo, *sobrenomes;
  p_hash autores = criar_hash();/*Cria hash*/
  scanf("%d %d", &artigos, &consultas);
  for(i=0; i<artigos; i++){
    j = 0;
    sobrenomes = malloc(MAX*sizeof(data));/*Cria vetor auxiliar que guardará dados*/
    scanf(" %c. %[^.,]%c", &nome1, sobrenome1, &separador);
    chave = strlen(sobrenome1);
    if(separador != '.'){
      while(separador != '.' ){/*Se o autor tiver coautores*/
        scanf(" %c. %[^.,]%c", &nome2, sobrenome2, &separador);
        novo = criar_dado(nome1, nome2, sobrenome1, sobrenome2);/*Seta informação do novo dado*/
        inserir(autores, chave, novo);/*Insere par de autores no hash*/
        sobrenomes[j] = novo;/*Insere par de autores no vetor auxiliar*/
        j++;
      }
    }else{/*Se o autor não tiver coautores*/
      nome2 = '\0';
      *sobrenome2 = '\0';
      novo = criar_dado(nome1, nome2, sobrenome1, sobrenome2);
      inserir(autores, chave, novo);
    }
    if (j > 1) {/*Se há mais de um coautor, cria pares entre coautores*/
      coautores(autores, j, sobrenomes);
    }
    free(sobrenomes);/*Libera vetor auxiliar*/
  }
  for(i=0; i<consultas; i++){
    resposta = consultar(autores);/*Busca informação sobre coautoria*/
    printf("%c\n", resposta);/*Imprime resposta*/
  }
  liberar_hash(autores);/*Libera hash*/
  return 0;
}

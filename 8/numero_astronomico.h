#ifndef NUMERO_ASTRONOMICO_H
#define NUMERO_ASTRONOMICO_H
typedef struct No{
  int numero;
  struct No *prox, *ant;
}No;
typedef No *p_no;

typedef struct lista{
  No *ini, *fim;
}lista;
typedef lista *listinha;

/*
  Cria a cabeça da calculadora(lista).

  Saída:retorna a cabeça já setada com ponteiros pra NULL
*/

listinha criar_calculadora();

/*
  Insere um novo digito no começo da lista
  Utilizada caso necessite a criação de uma casa de maior unidade na lista

  Entrada:calculadora: lista atual
          x: valor armazenado pro digito

*/
void insere_ini(listinha calculadora, int x);

/*
  Insere um novo digito no final da lista

  Entrada:calculadora: lista atual
          num: char que vai ser armazenado como digito
*/
void insere_fim(char num, listinha calculadora);

/*
  Realiza a operação de soma do número já armazenado e o novo digitado pelo usuário

  Entrada:calculadora: número armazenado
          calculadora2: novo número pra adição
*/
void soma(listinha calculadora, listinha calculadora2);

/*
  Ao fim da adição, verifica se a soma de cada digíto é um número entre 0 e 9.
  Senão, determina qual vai ser o resto e quanto vai ser adicionado no digíto
  ao lado

  Entrada: calculadora: soma recente
*/
void confere(listinha calculadora);

/*
  Imprime o valor recente armazenado na calculadora

  Entrada: calculadora: resultado da operação recente
*/
void imprimir(listinha calculadora);

/*
  Libera memória utilizada pela lista ligada

  Entrada: calculadora: número armazenado
*/
void destruir_calculadora(listinha calculadora);
#endif

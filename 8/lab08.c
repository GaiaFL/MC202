#include "numero_astronomico.h"
#include <stdio.h>

int main(){
  listinha calculadora, calculadora2;
  char numero;
  int operacoes = 0;/*contagem dos números de operacoes que são feitas*/
  calculadora = criar_calculadora();/*criação da lista permanente*/
  calculadora2 = criar_calculadora();/*criação da lista provisória*/
  scanf("%c", &numero);/*leitura do digíto*/
  while(numero != '#'){/*até a condição de término ser concretizada*/
    if(operacoes == 0){/*primeiro número*/
      if(numero > 47 && numero < 58){/*só armazena dígítos entre 0 e 9*/
        insere_fim(numero, calculadora);
      }
    }else{/*números restantes*/
      if(numero > 47 && numero < 58){
        insere_fim(numero, calculadora2);
      }
    }
    scanf("%c", &numero);
    if(numero == '+'){
      if(operacoes > 0){/*verifica se outro número foi digitado pra realizar a soma*/
        soma(calculadora, calculadora2);
        destruir_calculadora(calculadora2);
        calculadora2 = criar_calculadora();
        confere(calculadora);
      }
      imprimir(calculadora);
      operacoes++;/*aumenta o valor da variável*/
    }if(numero == '#'){
      soma(calculadora, calculadora2);
      destruir_calculadora(calculadora2);
      calculadora2 = criar_calculadora();
      confere(calculadora);
    }
  }
  imprimir(calculadora);/*imprime o resultado final*/
  destruir_calculadora(calculadora);/*libera a calculadora*/
  return 0;
}

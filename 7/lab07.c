#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **criar(int linhas, int colunas){/*cria matriz de caracterese*/
  int i;
  char **matrix;
  matrix = malloc(linhas*sizeof(char*));
  for(i=0; i<linhas; i++){
    matrix[i] = malloc(colunas*sizeof(char));
  }
  if(matrix == NULL){/*verifica se há memória para a matriz*/
    exit(1);
  }
  return matrix;
}

void preencher(char **matrix, int linhas, int colunas){/*preenche a matriz de caracteres*/
  int i, j;
  for(i=0; i<linhas; i++){
    for(j=0; j<colunas; j++){/*o espaço antes do 'c' ignora o \n do final da linha*/
      scanf(" %c", &matrix[i][j]);/*precisa do & por ser um caracter*/
    }
  }
}

int **criar2(int linhas, int colunas){/*cria uma matriz binária de mesmo tamanho da original*/
  int **resp, i, j;
  resp = malloc(linhas*sizeof(int*));
  for(i=0; i<linhas; i++){
    resp[i] = malloc(colunas*sizeof(int));
    for(j=0; j<colunas; j++)
      resp[i][j] = 0;/*inicializa todas as posições com 0*/
  }
  if(resp == NULL){/*verifica se há memória pra matriz binária*/
    exit(1);
  }
  return resp;
}

void imprimir(char **matrix, int linhas, int colunas){/*imprime a matriz de char na forma final*/
  int i, j;
  for(i = 0; i < linhas; i++){
    for(j = 0; j < colunas; j++){
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }
}

int livre(char **matrix, int linha, int coluna){/*verifica se o caminho do labirito está livre*/
  if(matrix[linha][coluna] == 'X'){
    return 0;/*retorna falso se não estiver*/
  }
  return 1;/*retorna verdadeiro se a posição estiver livre*/
}

int caminho(char **matrix, int **resp, int linhas, int colunas, int atualL, int atualC, int saidaL, int saidaC){/*recursão do labirinto*/
  resp[atualL][atualC] = 1;/*inicializa a posição da matriz binária como um*/
  if(atualL == saidaL && atualC == saidaC){/*caso base: saída do labirinto*/
    resp[atualL][atualC] = 1;
    return 1;/*retorna verdadeiro se chegou na posição final*/
  }if(atualL - 1 >= 0 && resp[atualL-1][atualC] == 0){/*pra cima*/
    if(livre(matrix, atualL-1, atualC)){/*vê se é obstáculo ou passagem livre*/
      if(caminho(matrix, resp, linhas, colunas, atualL-1, atualC, saidaL, saidaC)){
        return 1;/*retorna verdadeiro se dá pra fazer caminho*/
      }
    }
  }if(atualL + 1 < linhas && resp[atualL+1][atualC] == 0){/*pra baixo*/
    if(livre(matrix, atualL+1, atualC)){
      if(caminho(matrix, resp, linhas, colunas, atualL+1, atualC, saidaL, saidaC)){
          return 1;
      }
    }
  }if(atualC - 1 >= 0 && resp[atualL][atualC-1] == 0){/*pra esquerda*/
    if(livre(matrix, atualL, atualC-1)){
      if(caminho(matrix, resp, linhas, colunas, atualL, atualC-1, saidaL, saidaC)){
        return 1;
      }
    }
  }if(atualC + 1 < colunas && resp[atualL][atualC+1] == 0){/*pra direita*/
    if(livre(matrix, atualL, atualC+1)){
      if(caminho(matrix, resp, linhas, colunas, atualL, atualC+1, saidaL, saidaC)){
        return 1;
      }
    }
  }
  resp[atualL][atualC] = 0;/*se a posição na matriz de caracter não tiver nenhuma passagem, a binária zera sua posição atual*/
  return 0;/*retorna falso se a posição naõ tem passagem*/
}

void substituir(char **matrix, int **resp, int linhas, int colunas){/*muda a matriz de char pra sua forma final*/
  int i, j;
  for(i = 0; i < linhas; i++){
    for(j = 0; j < colunas; j++){
      if(resp[i][j] == 1){/*se a posição da binária for 1, é o caminho final da matriz de char*/
        matrix[i][j] = '*';
      }else{
        matrix[i][j] = ' ';/*se a posição da binária for 0, é vazio na matriz de char*/
      }
    }
  }
}

void liberar(char **matrix, int **resp, int linhas){/*libera ambas matrizes da memória*/
  int i;
  for(i = 0; i < linhas; i++){
    free(matrix[i]);
    free(resp[i]);
  }
  free(matrix);
  free(resp);
}


int main(){
  int LM, CM, LE, CE, LS, CS, **solu;
  char **matriz;
  scanf("%d %d %d %d %d %d", &LM, &CM, &LE, &CE, &LS, &CS);/*armazena as informações sobre: tamanho da matriz, posição da entrada e da saída do labirinto*/
  matriz = criar(LM, CM);
  solu = criar2(LM, CM);
  preencher(matriz, LM, CM);
  caminho(matriz, solu, LM, CM, LE, CE, LS, CS);
  substituir(matriz, solu, LM, CM);
  imprimir(matriz, LM, CM);
  liberar(matriz, solu, LM);
  return 0;
}

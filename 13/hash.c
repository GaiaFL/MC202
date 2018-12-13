#include "hash.h"

p_hash criar_hash(){/*Aloca hash na memória*/
  int i;
  p_hash hash = malloc(sizeof(Hash));
  if(hash == NULL){
    exit(1);
  }
  hash->table = malloc(TAM*sizeof(data));/*Aloca vetor do hash na memória*/
  if(hash->table == NULL){
    exit(1);
  }
  for(i=0; i<TAM; i++){/*Seta todas as posições do vetor como livres(-1)*/
    hash->table[i].flag = -1;
  }
  return hash;
}

int hash1(int x){/*Primeira função de hash*/
  return x%TAM;
}

int hash2(int x){/*Segunda função de hash para potência 2*/
  return (2*x) + 1;
}

void inserir(p_hash hash, int x, data novo){/*Insere novo dado no hash*/
  int pos1, pos2, index, i = 1;
  pos1 = hash1(x);
  if(hash->table[pos1].flag == 0){/*Verifica se a posição já está ocupada*/
    pos2 = hash2(x);
    index = (pos1 + i*pos2)%TAM;
    while(hash->table[index].flag == 0){/*Loop para encontrar uma posição livre*/
      i++;
      index = (pos1 + i*pos2)%TAM;
    }
    hash->table[index] = novo;
  }else{
    hash->table[pos1] = novo;
  }
}

int eh_autor(p_hash hash, char x, char y, char c[], char d[], int pos){
  if(hash->table[pos].flag == 0){/*Verifica se a posição já tem algum dado*/
    if(hash->table[pos].chave1 == x && strcmp(hash->table[pos].chave2, c) == 0){/*Verifica o nome e o sobrenome do autor*/
      if(hash->table[pos].coautor1 == y && strcmp(hash->table[pos].coautor2, d) == 0){/*Verifica o nome e o sobrenome do coautor*/
        return 1;/*Retorna True*/
      }
    }
  }
  return 0;/*Retorna False*/
}

char buscar(p_hash hash, char x, char y, char c[], char d[]){/*Busca dado sobre possível coautoria*/
  int pos1, pos2, index, chave, i=1;
  chave = strlen(c);
  pos1 = hash1(chave);
  if(eh_autor(hash, x, y, c, d, pos1)){
    return 'S';/*Retorna True*/
  }else{
    pos2 = hash2(chave);
    index = (pos1 + i*pos2)%TAM;
    while(index != pos1){/*Loop da posição inicial calculada até achar o dado com a informação requisitada*/
      if(eh_autor(hash, x, y, c, d, index)){
        return 'S';/*Retorna True*/
      }
      i++;
      index = (pos1 + i*pos2)%TAM;
    }
  }
  return 'N';/*Retorna False*/
}

void liberar_hash(p_hash hash){
  free(hash->table);/*Libera vetor do hash*/
  free(hash);/*Libera hash*/
}

#include "grafo.h"

typedef struct Fila{
  No *ini, *fim;
}Fila;
typedef Fila *p_fila;

int *criar_vetor(int tam){/*Cria vetor auxiliar que armazena o número dos participantes de determinado grupo*/
  int *aux;
  aux = calloc(tam, sizeof(int));
  if(aux == NULL)
    exit(1);
  return aux;
}

p_fila criar_fila(){/*Cria fila que armazenará próxima possível posição a percorrer*/
  p_fila f;
  f = malloc(sizeof(Fila));
  if(f == NULL){
    exit(1);
  }
  f->ini = f->fim = NULL;
  return f;
}

void enfileira(p_fila f, int x){/*Enfileira posição(ões) conectada(s) com a posição atual*/
  p_no novo;
  novo = malloc(sizeof(No));
  if(novo == NULL){
    exit(1);
  }
  novo->v = x;/*Guarda número da posição*/
  novo->prox = NULL;
  if(f->ini == NULL){
    f->ini = novo;
  }else{
    f->fim->prox = novo;
  }
  f->fim = novo;
}

int desenfileira(p_fila f){/*Retira da fila a posição que deve ser percorrida*/
  p_no primeiro;
  int x;
  primeiro = f->ini;
  x = f->ini->v;
  f->ini = f->ini->prox;
  free(primeiro);
  return x;
}

void destroi_fila(p_fila f){/*Destrói fila de posições*/
  free(f);
}

void busca_em_largura (p_grafo g, int s) {/*Verifica as posições conectadas com a posição 's' dada e o maior caminho percorrido desta para alguma daquelas*/
  int v, i, max = 0;
  int *dist;
  p_no temp;
  p_fila f;
  dist  = malloc(g->n * sizeof(int)); /*Armazena as distâncias da posição 's' até seus conectados*/
  if(dist == NULL){
    exit(1);
  }
  f = criar_fila ();
  for (v = 0; v < g->n; v++) {
    dist[v] = -1;/*Seta '-1' para a distância inicial*/
  }
  enfileira(f,s);
  dist[s] = 0;/*Começa com a posição de 's' para 's', equivalente à zero*/
  while (f->ini != NULL) {
    v = desenfileira(f);/*Desenfileira possível nova posição para percorrer*/
    for (temp = g->adjacencia[v]; temp != NULL; temp = temp->prox)/*Percorre a lista ligada da posição desenfileirada 'v'*/
      if(dist[temp->v] < 0) {/*Se não foi setado nenhum valor para a distância da posição*/
        dist[temp->v] = dist[v] + 1;/*A distância de tal posição é equivalente à posição de seu nó-pai mais um*/
        enfileira(f, temp->v);/*Enfleira a posição nos possíveis caminhos à percorrer*/
      }
  }
  for(i=0; i<g->n; i++){
    if(dist[i] == -1)/*Se a posição não foi percorrida, ou seja, não está ligada com 's'*/
      printf("%d ", i);/*Printa ela*/
    if(dist[i] > max)/*Verifica qual o maior caminho feito de 's' para as outras posições*/
      max = dist[i];
  }
  printf("- %d\n", max);/*Printa o valor desse caminho*/
  destroi_fila(f);/*Desaloca fila*/
  free(dist);/*Desaloca vetor das distâncias*/
}

void destruir_vetor(int *aux){/*Destrói o vetor auxiliar*/
  free(aux);
}

int main(){
  int n_alunos, grupos, i, j, k, n_participantes, pessoa, *aux;
  p_grafo pessoas;
  scanf("%d %d", &n_alunos, &grupos);/*Lê o número de alunos e grupos pesquisados*/
  pessoas = criar_grafo(n_alunos);/*Aloca memória do grafo*/
  for(i=0; i<grupos; i++){
    scanf("%d", &n_participantes);/*Lê o número de participantes do grupo*/
    aux = criar_vetor(n_participantes);/*Aloca vetor auxiliar*/
    for(j=0; j<n_participantes; j++){
      scanf("%d", &pessoa);/*Lê posição da pessoa do grupo*/
      aux[j] = pessoa;/*Armazena no vetor auxiliar*/
    }
    for(j=0; j<n_participantes; j++){/*Faz a combinação entre as pessoas do vetor auxiliar*/
      for(k=j+1; k<n_participantes; k++){
        insere_aresta(pessoas, aux[j], aux[k]);
      }
    }
    destruir_vetor(aux);/*Desaloca vetor auxiliar*/
  }
  for(i=0; i<n_alunos; i++){/*Faz a busca para toda posição do grafo*/
    busca_em_largura(pessoas, i);
  }
  destruir_grafo(pessoas);/*Desaloca grafo*/
  return 0;
}

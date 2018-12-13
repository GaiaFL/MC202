#include "grafo.h"

double *criar_vetor(int tam){/*Cria vetor auxiliar que vai guardas as idades*/
  double *aux = malloc(tam * sizeof(double));
  if(aux == NULL)
    exit(1);
  return aux;
}

void destruir_vetor(double *aux){/*Destrói o vetor auxiliar de idades*/
  free(aux);
}

int triangular(double x, double y, double z){/*Verifica se o grupo está entediado, a partir da média entre as idades*/
  double soma = (x+y+z)/3;
  if(soma > 2*x || soma > 2*y || soma > 2*z)
    return 1;
  return 0;
}

void entediar(p_grafo g, int x, int y, int z){/*Atualiza a situação de um grupo entediado*/
  g->adjacencia[x]->flag = g->adjacencia[y]->flag = g->adjacencia[z]->flag = 1;/*Entediado*/
}

void agrupar(p_grafo g, double *aux, int tam){/*Cria triângulos de pessoas e atualiza a situação dos grupos*/
  int i, j, k, eh_ligado1, eh_ligado2, status;
  for(i=0; i<tam; i++){
    for(j=i+1; j<tam; j++){
      eh_ligado1 = tem_aresta(g, i, j);/*Verifica se a pessoa da posição 'i' está ligada com a de posição 'j' da lista*/
      if(eh_ligado1){/*Se estiverem*/
        for(k=j+1; k<tam; k++){/*Procura uma pessoa da posição 'k' que esteja ligada a ambas anteriores*/
          eh_ligado1 = tem_aresta(g, i, k);
          eh_ligado2 = tem_aresta(g, j, k);
          if(eh_ligado1 && eh_ligado2){
            status = triangular(aux[i], aux[j], aux[k]);/*Verifica se o grupo está entediado ou não*/
            if(status){/*Se estiverem entediados, atualiza a situação*/
              entediar(g, i, j, k);
            }
          }
        }
      }
    }
  }
}

int main(){
  p_grafo pessoas;
  int n, rel, i, pessoa, laco;
  double *idades, idade;
  scanf("%d %d", &n, &rel);
  pessoas = criar_grafo(n);/*Cria grafo*/
  idades = criar_vetor(n);/*Cria vetor de double*/
  for(i=0; i<n; i++){
    scanf("%lf", &idade);
    idades[i] = idade;/*Guarda as idades no vetor de double*/
  }
  for(i=0; i<rel; i++){
    scanf("%d %d", &pessoa, &laco);/*Guarda a posição das duas pessoas que possuem um relacionamento*/
    insere_aresta(pessoas, pessoa, laco);/*Insere o relacionamento na lista*/
  }
  agrupar(pessoas, idades, n);/*Cria grupos e atualiza a situação das pessoas*/
  imprime_arestas(pessoas);/*Imprime as pessoas entediadas*/
  destruir_grafo(pessoas);/*Desaloca grafo*/
  destruir_vetor(idades);/*Desaloca vetor de idades*/
  return 0;
}

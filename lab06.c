#include <stdio.h>
#include "universidade.h"
#include <stdlib.h>

int main(){
  int i, P, A, j, D;
  char nome[MAX_NOME], sobrenome[MAX_NOME], disciplina[MAX_CODIGO];
  double salario, nota, min, max, media;
  p_professor * a; /*necessário criar ponteiro de ponteiro pra acessar a struct*/
  p_aluno * c;
  scanf("%d\n", &P);
  a = malloc(P*sizeof(p_professor)); /*define o tamanho da variável de armazenamento do tipo professor*/
  for(i=0; i<P; i++){
    scanf("%s %s %lf %s\n", nome, sobrenome, &salario, disciplina);
    a[i]= criarProfessor(nome, sobrenome, salario, disciplina);/*se deixar a variável que recebe o retorno como ponteiro, a variável que recebe seria o pedaço desse ponteiro, não o próprio*/
  }
  scanf("%d\n", &A);
  c = malloc(10*sizeof(p_aluno));/*define o tamanho da variável de armazenamento do tipo aluno*/
  for(i=0; i<A; i++){
    scanf("%s %s", nome, sobrenome);
    c[i] = criarAluno(nome, sobrenome);
    scanf("%d", &D);
    c[i]->qtd_disciplinas = 0;
    for(j=0;j<D;j++){
      scanf("%s %lf", disciplina, &nota);
      adicionarDisciplina(c[i], disciplina, nota);
      c[i]->qtd_disciplinas++;
    }
  }

  for(i=0; i<P; i++){
    min = max = 0.0;
    obterNotasExtremas(c, A, a[i]->disciplina, &min, &max);
    media = (min + max)/2;
    reajusteSalario(a[i], media);
    imprimirProfessor(a[i]);
    destruirProfessor(a[i]);
  }
  for(i=0; i<A; i++){
    destruirAluno(c[i]);
  }
  free(a);
  free(c);
  return 0;
}

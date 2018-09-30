#include <stdlib.h>
#include "universidade.h"
#include <stdio.h>
int main(){
  int i, P, A, D, j;
  char nome[MAX_NOME], sobrenome[MAX_NOME], disciplina[MAX_CODIGO];
  double salario, nota, min, max, media;
  p_professor * Profs; /*criação de ponteiro para vetores*/
  p_aluno * Alunos;
  scanf("%d", &P);
  Profs = malloc(P*sizeof(Professor)); /*alocamento a partir do tamanho da struct em bytes*/
  for(i=0; i<P; i++){
    scanf("%s %s", nome, sobrenome);
    scanf("%lf %s", &salario, disciplina);
    Profs[i] = criarProfessor(nome, sobrenome, salario, disciplina);
  }
  scanf("%d", &A);
  Alunos = malloc(A*sizeof(Aluno)); /*alocamento a partir da struct*/
  for(i=0; i<A; i++){
    scanf("%s %s", nome, sobrenome);
    Alunos[i] = criarAluno(nome, sobrenome);
    scanf("%d", &D);
    Alunos[i]->qtd_disciplinas = 0; /*inicialização de qtd_disciplinas como 0, pra poder usá-la na função de disciplinas*/
    for(j=0; j<D; j++){
      scanf("%s %lf", disciplina, &nota);
      adicionarDisciplina(Alunos[i], disciplina, nota);
      Alunos[i]->qtd_disciplinas++; /*incrementação da mesma*/
    }
  }
  for(i=0; i<P; i++){
    min = max = 0.00; /*variáveis pra utilização nas notas*/
    obterNotasExtremas(Alunos, A, Profs[i]->disciplina, &min, &max);
    media = (min+max)/2;
    reajusteSalario(Profs[i], media);
    imprimirProfessor(Profs[i]);
  }
  for(i=0; i<P; i++){
    destruirProfessor(Profs[i]); /*retira o professor do ponteiro principal Profs*/
  }
  for(j=0; j<A; j++){
    destruirAluno(Alunos[j]); /*retira o aluno do ponteiro principal Alunos*/
  }
  free(Profs); /*retira ambas variáveis do alocamento*/
  free(Alunos);
  return 0;
}

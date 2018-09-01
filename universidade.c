#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "universidade.h"

p_professor criarProfessor(char nome[], char sobrenome[], double salario, char disciplina[]){
  p_professor b = malloc(10*sizeof(p_professor));/*aloca a memória de uma struct*/
  strcpy(b->nome, nome); /*por ser strings, precisam ser copiadas para o ponteiro*/
  strcpy(b->sobrenome, sobrenome);
  b->salario = salario; /*diferente tipo de declaração por ser double*/
  strcpy(b->disciplina, disciplina);
  return b;
}

void destruirProfessor(p_professor professor){
  free(professor);
}

p_aluno criarAluno(char nome[], char sobrenome[]){
  p_aluno b = malloc(10*sizeof(p_aluno));
  strcpy(b->nome, nome);
  strcpy(b->sobrenome, sobrenome);
  return b;
}

void adicionarDisciplina(p_aluno aluno, char disciplina[], double nota){
  strcpy(aluno->disciplinas[aluno->qtd_disciplinas], disciplina);
  aluno->notas[aluno->qtd_disciplinas] = nota;
}

void destruirAluno(p_aluno aluno){
  free(aluno);
}

void obterNotasExtremas(p_aluno alunos[], int qtd_alunos, char disciplina[], double *nota_min, double *nota_max){
 int i, j;
 for(i=0; i<qtd_alunos; i++){
   for(j=0; j<alunos[i]->qtd_disciplinas; j++){
     if(strcmp(alunos[i]->disciplinas[j], disciplina) == 0){
       if(alunos[i]->notas[j]< *nota_min || *nota_min == 0.0){
         *nota_min = alunos[i]->notas[j];
       }else if(alunos[i]->notas[j] > *nota_max){
         *nota_max = alunos[i]->notas[j];
       }
     }
   }
 }
}

void reajusteSalario(p_professor professor, double media_notas){
  if(media_notas == 10.0){
    professor->salario += professor->salario*0.15;
  }else if(media_notas >= 9.0){
    professor->salario += professor->salario*0.10;
  }else if(media_notas >= 8.5){
    professor->salario += professor->salario*0.05;
  }
}

void imprimirProfessor(p_professor professor){
  printf("%s %s %.2f\n", professor->nome, professor->sobrenome, professor->salario);
}

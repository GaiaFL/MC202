#include <stdio.h>
#define MAX 312
void ler_matriz(int vetor[], int tam, int vetor2[][MAX]){
  int i, linha;
  for(i=0;i<tam;i++)
   scanf(" %d", &vetor[i]);
  for(i=0;i<tam;i++){
   linha = vetor[i];
   vetor2[linha-1][i] = 1;
  }
}
void ler_matriz2(double vetor[][MAX], int tam){
  int i, j;
  for(i=0;i<tam;i++)
   for(j=0;j<tam;j++)
    scanf(" %lf", &vetor[i][j]);
}
void mulp(double vetor[][MAX],int vetor2[][MAX],double result[][MAX],int tam){
  int i, j, k;
  for(i=0;i<tam;i++)
   for(j=0;j<tam;j++){
    result[i][j] = 0;
    for(k=0;k<tam;k++)
     result[i][j] += vetor[k][j] * vetor2[i][k];
   }
}
void impressao(double result[][MAX], int tam){
  int i, j;
  for(i=0;i<tam;i++){
   for(j=0;j<tam;j++)
    if(j==tam-1){
     printf("%.1f", result[i][j]);
   }else{
    printf("%.1f ", result[i][j]);
    }
   printf("\n");
  }
}
int main(){
  int ordem, p[MAX], C[MAX][MAX], i, j;
  double B[MAX][MAX], A[MAX][MAX];
  scanf("%d", &ordem);
  for(i=0;i<ordem;i++)
   for(j=0;j<ordem;j++)
    C[i][j]= 0; /*necessário preencher a matriz da multiplicação*/ 
  ler_matriz(p,ordem,C);
  ler_matriz2(B,ordem);
  mulp(B,C,A,ordem);
  impressao(A,ordem);
  return 0;
}

# include <stdio.h>
#define MAX 40
void ler_vetor(int vetor[], int tam){
  int i;
  for(i=0;i<tam;i++)
   scanf(" %d", &vetor[i]); /*atribui elemento pra cada posição*/
}
int compara(int element, int vetor2[], int tam){
  int j;
  for(j=0;j<tam;j++){
    if(element==vetor2[j]) /*confere se há repetição entre os dois vetores*/
     return -1;
  }
  return 0;
}
void imprime(int vetor[], int tam){
  int i;
  for(i=0;i<tam;i++)
   if(vetor[i]!= -2)
    printf("%d ", vetor[i]);
  printf("\n");
}

int main(){
  int m, n, i, A[MAX], B[MAX], num, diferenca[80];/*80 é a soma máxima dos dois vetores*/
  int rest = 0;
  scanf("%d %d", &m, &n);
  ler_vetor(A, m);
  ler_vetor(B, n);
  num = m+n;
  for(i=0;i<num;i++)/*preenche o vetor resposta*/
   diferenca[i] = -2;
  for(i=0;i<m;i++){
   if(compara(A[i],B,n)==0){
    diferenca[rest] = 0 + A[i];
    rest +=1;
   }
  }
  for(i=0;i<n;i++)
   if(compara(B[i],A,m)==0){
    diferenca[rest] = 0 + B[i];
    rest +=1;
   }
  imprime(diferenca, num);
  return 0;
}

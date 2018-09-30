# include <stdio.h>

float obter_maximo(float vetor[], int n){
  int i;
  float maximo = vetor[0];
  for(i=0;i<n;i++){
    if (maximo<vetor[i])//como é só uma condição, não precisa de colchetes
     maximo = vetor[i];
  }
  return maximo;
}
int main(){
  int alunos;
  float nota1, nota2, nota3, F;
  float media1 = 0, media2 = 0;
  float mediasT[alunos], mediasP[alunos];
  float maiornota;
  float T, P;
  scanf("%d", &alunos);
  int i;
  for(i=0;i<alunos;i++){
    scanf("%f %f %f", &nota1, &nota2, &nota3);
    P = ((nota1+nota2+nota3)/3)*1.1;
    mediasP[i] = P;
  }
  for(i=0;i<alunos;i++){
    scanf("%f %f", &nota1, &nota2);
    T = ((nota1+nota2)/2);
    mediasT[i] = T;
  }
  maiornota = obter_maximo(mediasT, alunos);
  for(i=0;i<alunos;i++){
    mediasT[i] = (10*mediasT[i])/maiornota;
  }
  for(i=0;i<alunos;i++){
    F = (mediasT[i]+mediasP[i])/2;
    printf("Nota final: %.2f\n", F);
  }
  P = obter_maximo(mediasP, alunos);
  T = obter_maximo(mediasT, alunos);
  printf("MAX P: %.2f\n", P);
  printf("MAX T: %.2f\n", T);
  for(i=0;i<alunos;i++){
    media1 += mediasP[i];
    media2 += mediasT[i];
  }
  media1 = media1/alunos;
  media2 = media2/alunos;
  printf("Media P: %.2f\n", media1);
  printf("Media T: %.2f\n", media2);
}

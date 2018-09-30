#include <stdio.h>
#include <string.h>
#define MAX 20
void ler_matriz(char matriz[MAX][MAX], int m, int n) {
    int i, j;
    char letra;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf(" %c", &letra);
            matriz[i][j] = letra;
        }
    }
}
void criar_matriz_ponto(char matriz[MAX][MAX], int m, int n){
  int i, j;
  char ponto = ".";
  for(i=0;i<m;i++){
    for(j=0;i<n;j++){
      matriz[i][j] = ponto;
    }
  }
}
void marcar_ocorrencia_horizontal(char palavra[],char A[MAX][MAX],char B[MAX][MAX],int m, int n, int i, int j){
 if (A[i][j] == palavra[j]){
  marcar_ocorrencia_horizontal(palavra, A, B, m, n, i, j+1);
  for(j=0;j<n;j++){
    B[i][j] = palavra[j];
  }
 }
}
void marcar_ocorrencia_vertical(char palavra[],char A[MAX][MAX],char B[MAX][MAX],int m, int n, int i, int j){
 if (A[i][j] == palavra[i]){
  marcar_ocorrencia_vertical(palavra, A, B, m, n, i+1, j);
  for(i=0;i<n;i++){
    B[i][j] = palavra[i];
  }
 }
}
void marcar_ocorrencia_diagonal(char palavra[],char A[MAX][MAX],char B[MAX][MAX],int m, int n, int i, int j){
 if(A[i][j+1] == palavra[j]){
  marcar_ocorrencia_diagonal(palavra, A, B, m, n, i+1, j+1);
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      B[i][j] = palavra[i];
    }
  }
 }
}
void marcar_ocorrencias(char palavra[],char A[MAX][MAX],char B[MAX][MAX],int m, int n)
{
    int i, j;
    for(i = 0;i<m;i++) {
        for(j=0;j<n;j++) {
            marcar_ocorrencia_horizontal(palavra, A, B, m, n, i, j);
            marcar_ocorrencia_vertical(palavra, A, B, m, n, i, j);
            marcar_ocorrencia_diagonal(palavra, A, B, m, n, i, j);
        }
    }
}
void copiar_inverso(char palavra[], char inverso[]){
  int i = 0;
  int tam = strlen(palavra);
  int j = tam - 1;
  while(i<tam){
    inverso[j] = palavra[i];
    i += 1;
    j -= 1;
  }
}
void imprimir_matriz(char B[MAX][MAX],int m,int n){
  int i, j;
  for(i=0; i<m; i++){
    for(j=0; j<n; j++){
      printf("%c ", B[i][j]);
    }
    printf("\n");
  }
}

int main() {
    int i;
    int m, n, p;
    char A[m][n];
    char B[m][n];
    char palavra[MAX], inverso[MAX];
    /* lê e cria matrizes */
    scanf("%d %d", &m, &n);
    ler_matriz(A, m, n);
    criar_matriz_ponto(B, m, n);

    /* lê e marca cada palavra */
    scanf("%d", &p);

    for (i = 0; i < p; i++) {
        scanf("%s", palavra);
        marcar_ocorrencias(palavra, A, B, m, n);
        copiar_inverso(palavra, inverso);
        marcar_ocorrencias(inverso, A, B, m, n);
    }

    /* imprime matriz resultante */
    imprimir_matriz(B, m, n);
}

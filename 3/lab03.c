#include <stdio.h>
int string_igual(char a[], char b[]){
  int i;
  for(i=0;i<3;i++){
   if(a[i] != b[i])
    return 0;
  }
  return 1;
}
void une(char ant[], char novo[]){
  int i=0, j;
  while(ant[i] != '\0')
   i+=1;
  for(j=0;j<97;j++){
   ant[i] = novo[j];
   i+=1;
  }
}
void subs(char ant[], int pos, int tam){
  int i, j=0;
  int n = pos+tam;
  for(i=pos;i<n;i++){
    ant[j] = ant[i];
    j++;
  }
  while(ant[j] != '\0'){
    ant[j] = '\0';
    j++;
  }
}
int compara(char ant[], char nova[]){
  int i=0;
  while(ant[i] != '\0'){
    if(ant[i] != nova[i])
     return 0;
    i++;
  }
  return 1;
}
void imprime(char a[]){
  int i = 0;
  while(a[i] != '\0'){
    printf("%c", a[i]);
    i++;
  }
  printf("\n");
}
int main(){
  char comando[3], comando1[97], palavra[100];
  int i=0;
  while (i<100) {
    palavra[i] = '\0';
    i++;
  }
  while(1){
   scanf("%s", comando);
  if(string_igual(comando, "CAT")){
   scanf("%s", comando1);
   une(palavra, comando1);
   imprime(palavra);
 }else if(string_igual(comando, "SUB")){
   int x, tam;
   scanf("%d %d", &x, &tam);
   subs(palavra, x, tam);
   imprime(palavra);
 }else if(string_igual(comando, "CMP")){
   scanf("%s", comando1);
   if(compara(palavra,comando1) == 1){
     printf("IGUAL\n");
   }else{
    printf("DIFERENTE\n");
    }
 }else if(string_igual(comando, "END")){
    break;
  }
 }
  return 0;
}

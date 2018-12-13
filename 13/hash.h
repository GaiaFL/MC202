#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 16
#define TAM 2048

typedef struct{
  char chave1;/*Inicial do primeiro autor*/
  char chave2[MAX];/*Sobrenome do primeiro autor*/
  char coautor1;/*Inicial do segundo autor*/
  char coautor2[MAX];/*Sobrenome do segundo autor*/
  int flag;/*Controla se a posição está ocupada ou não*/
}data;

typedef struct{
  data *table;/*Vetor com informações*/
}Hash;
typedef Hash *p_hash;

/*
  Aloca a memória de um hash, bem como do vetor de sua estrutura.
  Saída: Hash setado
*/
p_hash criar_hash();

/*
  Primeira função que calcula a provável posição do dado no vetor.
  Entrada: x:inteiro que representa a chave do dado;
  Saida: Possível posição do dado no vetor
*/
int hash1(int x);

/*
  Segunda função que calcula a provável posição do dado no vetor.
  Entrada: x: inteiro que representa a chave do dado;
  Saída: Possível posição do dado no vetor
*/
int hash2(int x);

/*
  Insere o dado na posição livre calculada a partir de sua chave.
  Entrada: hash: onde vai ser adicionado o novo dado;
          x: chave do dado;
          novo: dado com as informações de dois autores;
*/
void inserir(p_hash hash, int x, data novo);

/*
  Verifica se há coautoria a partir de dois nomes e a posição calculada.
  Entrada: hash: vetor com os dados;
          x: nome do primeiro autor;
          y: nome do segundo autor;
          c: sobrenome do primeiro autor;
          d: sobrenome do segundo autor;
          pos: possível posição onde está guardada a coautoria;
  Saída: Retorna '1' se a posição tiver o dado, '0' se não
*/
int eh_autor(p_hash hash, char x, char y, char c[], char d[], int pos);

/*
  Procura se há coautoria no hash entre dois autores requisitados.
  Entrada: hash: vetor com os dados;
          x: nome do primeiro autor;
          y: nome do segundo autor;
          c: sobrenome do primeiro autor;
          d: sobrenome do segundo autor;
  Saída: Retorna 'S' se a informação foi encontrada, 'N' se não
*/
char buscar(p_hash hash, char x, char y, char c[], char d[]);

/*
  Desaloca o hash e seu vetor da memória.
  Entrada: hash: estrutura com vetor de dados armazenados;
*/
void liberar_hash(p_hash hash);

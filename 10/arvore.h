typedef struct No{
  char *valor;
  struct No *esq, *dir;
}No;
typedef No *p_no;

/*
  Cria um novo nó vazio
  Entrada: esq: nó esquerdo do nó novo;
          dir: nó direito no nó novo;
  Saída: Novo nó na árvore
*/
p_no criar_arvore(p_no esq, p_no dir);

/*
  Coloca, recursivamente, os elementos da expressão matemática nos nós da árvore
  Entrada: no: nó atual;
  Saída: nó com seu valor setado
*/
p_no montagem(p_no no);

/*
  Verifica se o nó não_é vazio
  Entrada: no: nó atual;
  Saída: '0', se for vazio, ou '1' se não for
*/
int n_eh_vazio(p_no no);

/*
  Verifica se o valor armazenado no nó é uma constante ou um número
  Entrada: *x: vetor de char;
  Saída: '0', se não for número, ou '1' se for
*/
int eh_numero(char *x);

/*
  Realiza a operação matemática dos valores armazenados nos nós
  Entrada: x: valor do nó da esquerda;
          y: valor do nó da direita;
          operador: char que representa o operador
  Saída: novo vetor de char pra ser armazenado no nó
*/
char *operacao(int x, int y, char operador);

/*
  Realiza a otimização da árvore na sequência inordem
  Entrada: no: no atual
*/
void inordem(p_no no);

/*
  Imprime a ordem na sequência inordem
  Entrada: no: nó atual
  */
void imprime_inordem(p_no no);

/*
  Libera a árvore da memória
  Entrada: no: atual
  Saída: retorna a raiz sem seus filhos
*/  
p_no liberar_arvore(p_no no);

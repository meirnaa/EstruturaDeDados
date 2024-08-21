/* TAD: matriz m por n */
/* Tipo exportado */
typedef struct matriz Matriz;

/* Funções exportadas */

/* Função cria
** Aloca e retorna uma matriz de dimensão m por n
*/
Matriz* criar(int m, int n);

void listar(Matriz* mat);

/* Função libera
** Libera a memória de uma matriz previamente criada.
*/
void liberar(Matriz* mat);

/* Função acessa
** Retorna o valor do elemento da linha i e coluna j da matriz
*/
float acessar(Matriz* mat, int i, int j);

/* Função atribui
** Atribui o valor dado ao elemento da linha i e coluna j da matriz
*/
void atribuir(Matriz* mat, int i, int j, float v);

/* Função linhas
** Retorna o número de linhas da matriz
*/
int linhas(Matriz* mat);

/* Função colunas
** Retorna o número de colunas da matriz
*/
int colunas(Matriz* mat);
int verificar_simetria(Matriz* mat);
Matriz* transposta(Matriz* mat);
void enter_to_continue();

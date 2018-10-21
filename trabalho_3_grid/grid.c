/* Trabalho Grid - Matriz quadrada - preenchimento de 0's e 1's */

#include <stdlib.h>
#include <stdio.h>

#define ordem_da_matriz 9 // a ordem deve ser impar, para termos um elemento central

int main(){

  int **matriz;

  matriz = (int **)calloc(ordem_da_matriz, sizeof(int *)); //alocacao das linhas da matriz

  for(int i=0; i<ordem_da_matriz; i++){
    matriz[i] = (int *) calloc(ordem_da_matriz, sizeof(int)); //alocacao das colunas da matriz
  }//end for aloca colunas

  //matriz ja esta toda preenchida por zeros. Agora o elemento central[ordem_da_matriz/2][ordem_da_matriz/2] deve ser 1

  matriz[ordem_da_matriz/2][ordem_da_matriz/2] = 1; // elemento na posicao [4][4] se a ordem = 9

  /* Testes
  printf("%d\n", matriz[ordem_da_matriz/2][ordem_da_matriz/2]);
  for(int i=0; i<ordem_da_matriz; i++){
    for(int j =0; j<ordem_da_matriz; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  */

  

  return 0;
}

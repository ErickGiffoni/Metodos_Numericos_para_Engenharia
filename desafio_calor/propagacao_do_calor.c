#include <stdio.h>
#include <stdlib.h>

#define tamanho 10

int main (){
  int i,j;

  int **matriz = (int **)calloc(tamanho,sizeof(int *));
  for(i=0; i<tamanho; i++){
    matriz[i] = (int *)calloc(tamanho,sizeof(int));
  }//alocacao da matriz


  for(i=1; i<tamanho-1; i++){ //percorrer a coluna 0
    matriz[i][0] = 20;
  }
  for(i=1; i<tamanho-1; i++){ //percorrer a coluna 99
    matriz[i][tamanho-1] = 10;
  }
  for(i=1; i<tamanho-1; i++){ //percorrer a linha 0
    matriz[0][i] = 40;
  }
  for(i=1; i<tamanho-1; i++){ //percorrer a linha 99
    matriz[tamanho-1][i] = 10;
  }

  for(i=0;i<tamanho;i++){
    for(j=0;j<tamanho;j++){
      printf("\t%d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}

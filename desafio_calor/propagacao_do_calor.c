#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

printf("Inicial:\n\n");
  for(i=0;i<tamanho;i++){
    for(j=0;j<tamanho;j++){
      printf("\t%d ", matriz[i][j]);
    }
    printf("\n");
  }

  printf("\nFinal:\n\n");

  int tamanho1 = tamanho;
  tamanho1 -= 2;
  int counter = 0;
  srand(time(NULL));
  do{
    i = rand() % tamanho1+1;
    j = rand() % tamanho1+1;
    matriz[i][j] = (matriz[i-1][j]+matriz[i][j-1]+matriz[i+1][j]+matriz[i][j+1])/4;
    counter++;
  }while(counter<=pow(tamanho,2));

  for(i=0;i<tamanho;i++){
    for(j=0;j<tamanho;j++){
      printf("\t%d ", matriz[i][j]);
    }
    printf("\n");
  }

  // FIM //
  free(matriz);

  return 0;
}

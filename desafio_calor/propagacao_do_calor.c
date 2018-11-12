#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define tamanho 20

int main (){
  int i,j;

  double **matriz = (double **)calloc(tamanho,sizeof(double *));
  for(i=0; i<tamanho; i++){
    matriz[i] = (double *)calloc(tamanho,sizeof(double));
  }//alocacao da matriz


  for(i=1; i<tamanho-1; i++){ //percorrer a coluna 0
    matriz[i][0] = 20.0;
  }
  for(i=1; i<tamanho-1; i++){ //percorrer a coluna 99
    matriz[i][tamanho-1] = 10.0;
  }
  for(i=1; i<tamanho-1; i++){ //percorrer a linha 0
    matriz[0][i] = 40.0;
  }
  for(i=1; i<tamanho-1; i++){ //percorrer a linha 99
    matriz[tamanho-1][i] = 10.0;
  }

printf("Inicial:\n\n");
  for(i=0;i<tamanho;i++){
    for(j=0;j<tamanho;j++){
      printf("\t%.3lf ", matriz[i][j]);
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
    for(i=0;i<tamanho;i++){
      for(j=0;j<tamanho;j++){
        printf("\t%.3lf ", matriz[i][j]);
      }
      printf("\n");
    }
    system("clear");
    counter++;
  }while(1);

  // system("cls");

  for(i=0;i<tamanho;i++){
    for(j=0;j<tamanho;j++){
      printf("\t%.3lf ", matriz[i][j]);
    }
    printf("\n");
  }

  // FIM //
  free(matriz);

  return 0;
}

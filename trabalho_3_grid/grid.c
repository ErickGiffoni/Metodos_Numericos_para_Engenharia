/* Trabalho Grid - Matriz quadrada - preenchimento de 0's e 1's */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define ordem_da_matriz 9 // a ordem deve ser impar, para termos um elemento central

int main(){

  int elemento;
  int random_number;

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

  /* Condicao principal -> Preencher 10% de ordem_da_matriz^2 vezes */

float condicao_principal = (10.0/100.0) * pow(ordem_da_matriz, 2);
float verifica_condicao_principal = 0;


    //escolher um elemento na matriz de forma aleatoria -> condicao 2

    condicao2:
    if(verifica_condicao_principal <= condicao_principal){

      do{ // escolher um elemnto na matriz de forma aleatoria
        srand(time(NULL));

        elemento = rand() % ordem_da_matriz; // random number from 0 up to 8 if order = 9

      }while(matriz[elemento][elemento] != 0); // repete ate que ache um elemento na matriz que nao seja o central, que e igual a 1

      // escolher um numero de 1 a 4 aleatoriamente -> condicao 3
    condicao3:
      srand(time(NULL));

      random_number = rand() % 4 + 1; //random number from 1 up to 4

      switch(random_number){
        case 1: // go right
          if(elemento == ordem_da_matriz-1){ // elemento na beirada da linha
            if(matriz[elemento][elemento-elemento] == 0){
              goto condicao3;

            }
            else{ // matriz = 1
              matriz[elemento][elemento] = 1;
              verifica_condicao_principal ++;
              goto condicao2;

            } // end else matriz = 1

          }// end if elemento na beirada da linha
          else{
            if(matriz[elemento][elemento+1] == 0){ // o proximo a direita e 0 ?
              goto condicao3;
            }// end if o proximo a direita e 0 ?
            else{
              matriz[elemento][elemento] = 1;
              verifica_condicao_principal ++;
              goto condicao2;
            }// end else o proximo a direita nao e 0
          } // end caso 1

          break;
        case 2: // go up

          if(elemento == 0){ // estamos na primeira linha ?
            if(matriz[elemento+ordem_da_matriz-1][elemento] == 0){ //olhamos a posicao [8][0], mesma coluna
              goto condicao3;
            }// end if olhamos a posicao [8][0], mesma coluna
            else{
              matriz[elemento][elemento] = 1;
              verifica_condicao_principal ++;
              goto condicao2;
            }// olhamos a posicao [8][0], mesma coluna e é 1

          }// end if estamos na primeira linha
          else{
            if(matriz[elemento+1][elemento] == 0){// elemento de cima e 0 ?
              goto condicao3;
            }// end if  elemento de cima e 0
            else{ // == 1
              matriz[elemento][elemento] = 1;
              verifica_condicao_principal ++;
              goto condicao2;
            }// end else elemento de cima nao e 0
          }// end caso 2

          break;
        case 3: // go left

          if(elemento == 0){ // estamos na primeira coluna ?

          }// end if estamos na primeira coluna
          else{

          }//end caso 3

          break;
        case 4: // go down

          if(elemento == ordem_da_matriz-1){ // estamos na ultima linha ?

          } // end if estamos na ultima linha ?
          else{

          }//end caso 4

          break;
        default:
          printf("Erro na aleatoriedade dos numeros\n\n");
          break;
        }// end switch random_number

    }// end if condicao_principal atendida
    else{
      printf("10%% da ordem da matriz ao quadrado totalmente preenchido\n\n");
    }

/* IMPRIMA EM UM ARQUIVO.DAT */

  FILE *arquivo;
do{
  arquivo = fopen("arquivo.dat", "w");
}while (arquivo == NULL);

  for(int i = 0; i< ordem_da_matriz; i++){ //preencher o arquivo com os dados da posicao na matriz que estiver =1
    for(int j =0; j< ordem_da_matriz; j++){
      if(matriz[i][j] == 1){
        fprintf(arquivo, "%d %d\n", i, j);
      }
      else continue;
    }
  }//end for preenche arquivo

  fclose(arquivo);

  /* FIM */

  free(matriz); // desalocacao da matriz

  return 0;
}

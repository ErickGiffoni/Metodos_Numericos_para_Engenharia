/* Trabalho Grid - Matriz quadrada - preenchimento de 0's e 1's */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

//#define ordem_da_matriz 9 // a ordem deve ser impar, para termos um linha central

int main(){

  int ordem_da_matriz;
  printf("Informe a ordem da matriz quadrada desejada\nDeve ser um numero impar : ");
  scanf("%d", &ordem_da_matriz);

  int linha, coluna;
  int random_number;

  int **matriz;

  int dez_por_cento = (0.1) * pow(ordem_da_matriz, 2);
    printf("%d\n\n",dez_por_cento);
  int porcentagem = 0;

  matriz = (int **)calloc(ordem_da_matriz, sizeof(int *)); //alocacao das linhas da matriz

  for(int i=0; i<ordem_da_matriz; i++){
    matriz[i] = (int *) calloc(ordem_da_matriz, sizeof(int)); //alocacao das colunas da matriz
  }//end for aloca colunas

  //matriz ja esta toda preenchida por zeros. Agora o linha central[ordem_da_matriz/2][ordem_da_matriz/2] deve ser 1

  matriz[ordem_da_matriz/2][ordem_da_matriz/2] = 1; // linha na posicao [4][4] se a ordem = 9

  /* Testes
  //printf("%d\n", matriz[ordem_da_matriz/2][ordem_da_matriz/2]);
  for(int i=0; i<ordem_da_matriz; i++){
    for(int j =0; j<ordem_da_matriz; j++){
      //printf("%d ", matriz[i][j]);
    }
    //printf("\n");
  }
  */

  /* Condicao //principal -> Preencher 10% de ordem_da_matriz^2 vezes */

  FILE *arquivo;
  do{
  arquivo = fopen("arquivo.dat", "w");
  }while (arquivo == NULL);

    //escolher um linha na matriz de forma aleatoria -> condicao 2

    condicao2:
    if(porcentagem <= dez_por_cento){
    //if(1){

      do{ // escolher um elemnto na matriz de forma aleatoria

        srand(time(NULL));
        linha = rand() % ordem_da_matriz; // random number from 0 up to 8 if order = 9

        coluna = rand() % ordem_da_matriz;

      }while(matriz[linha][coluna] != 0); // repete ate que ache um linha na matriz que nao seja o central, que e igual a 1

      // escolher um numero de 1 a 4 aleatoriamente -> condicao 3
    condicao3:
    if(porcentagem <= dez_por_cento){
    //if(1){

      random_number = rand() % 4 + 1; //random number from 1 up to 4
      ////printf("rand\t%d\n",random_number);

      switch(random_number){
        case 1: // go right
          if(coluna == ordem_da_matriz-1){ // linha na beirada da linha
            if(matriz[linha][0] == 0){
              coluna=0;
              goto condicao3;
            }
            else{ // matriz = 1
              matriz[linha][coluna] = 1;
              porcentagem++;printf("%d\n",porcentagem);
              fprintf(arquivo, "%d %d\n", linha, coluna);

              goto condicao2;

            } // end else matriz = 1

          }// end if linha na beirada da linha
          else{
            if(matriz[linha][coluna+1] == 0){ // o proximo a direita e 0 ?
              coluna=coluna+1;
              goto condicao3;
            }// end if o proximo a direita e 0 ?
            else{
              matriz[linha][coluna] = 1;
              porcentagem++;printf("%d\n",porcentagem);
              fprintf(arquivo, "%d %d\n", linha, coluna);

              goto condicao2;
            }// end else o proximo a direita nao e 0
          } // end caso 1

          break;
        case 2: // go up

          if(linha == 0){ // estamos na primeira linha ?
            if(matriz[ordem_da_matriz-1][coluna] == 0){ //olhamos a posicao [8][0], mesma coluna
              linha=ordem_da_matriz-1;
              goto condicao3;
            }// end if olhamos a posicao [8][0], mesma coluna
            else{
              matriz[linha][coluna] = 1;
              porcentagem++;printf("%d\n",porcentagem);
              fprintf(arquivo, "%d %d\n", linha, coluna);

              goto condicao2;
            }// olhamos a posicao [8][0], mesma coluna e é 1

          }// end if estamos na primeira linha
          else{
            if(matriz[linha-1][coluna] == 0){// linha de cima e 0 ?
              linha=linha-1;

              goto condicao3;
            }// end if  linha de cima e 0
            else{ // == 1
              matriz[linha][coluna] = 1;
              porcentagem++;printf("%d\n",porcentagem);
              fprintf(arquivo, "%d %d\n", linha, coluna);

              goto condicao2;
            }// end else linha de cima nao e 0
          }// end caso 2

          break;
        case 3: // go left

          if(coluna == 0){
            if(matriz[linha][ordem_da_matriz-1] == 0){
              coluna=ordem_da_matriz-1;

              goto condicao3;
            }
            else{
              matriz[linha][coluna] = 1;
              porcentagem++;printf("%d\n",porcentagem);
              fprintf(arquivo, "%d %d\n", linha, coluna);

              goto condicao2;
            }
          }
          else{
            if(matriz[linha][coluna-1] == 0){
              coluna=coluna-1;
              goto condicao3;
            }
            else{
              matriz[linha][coluna] = 1;
              porcentagem++;printf("%d\n",porcentagem);
              fprintf(arquivo, "%d %d\n", linha, coluna);

              goto condicao2;
            }
          }

          break;
        case 4: // go down

          if(linha == ordem_da_matriz-1){
            if(matriz[0][coluna] == 0){
              linha=0;
              goto condicao3;
            }
            else{
              matriz[linha][coluna] = 1;
              porcentagem++;printf("%d\n",porcentagem);
              fprintf(arquivo, "%d %d\n", linha, coluna);

              goto condicao2;
            }
          }
          else{
            if(matriz[linha+1][coluna] == 0){// linha de cima e 0 ?
              linha=linha+1;
              goto condicao3;
            }
            else{
              matriz[linha][coluna] = 1;
              porcentagem++;printf("%d\n",porcentagem);
              fprintf(arquivo, "%d %d\n", linha, coluna);

              goto condicao2;
            }
          }

          break;
        default:
          //printf("Erro na aleatoriedade dos numeros\n\n");
          break;
        }

    }
  }

    else{
      //printf("10%% da ordem da matriz ao quadrado totalmente preenchido\n\n");
    }

/* IMPRIMA EM UM ARQUIVO.DAT */
/*
  FILE *arquivo;
do{
  arquivo = fopen("arquivo.dat", "w");
}while (arquivo == NULL);
  for(int i = 0; i< ordem_da_matriz; i++){ //preencher o arquivo com os dados da posicao na matriz que estiver =1
    for(int j =0; j< ordem_da_matriz; j++){
      if(matriz[i][j] == 1){
        //printf("%d %d\n", i, j);
      }
      else continue;
    }
  }
*/
  fclose(arquivo);

  /* FIM */

  free(matriz); // desalocacao da matriz

  return 0;
}
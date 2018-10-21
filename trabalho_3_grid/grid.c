/* Trabalho Grid - Matriz quadrada - preenchimento de 0's e 1's */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

  /* Condicao principal -> Preencher 10% de ordem_da_matriz^2 vezes */

float condicao_principal = (10f/100f) * pow(ordem_da_matriz, 2);
float verifica_condicao_principal = 0;

do{ // Preencher 10% de ordem_da_matriz^2 vezes


    //escolher um elemnto na matriz de forma aleatoria -> condicao 2

    int bool_condicao2 = 1; // true

    do{ // condicao 2

      do{ // escolher um elemnto na matriz de forma aleatoria
        srand(time(NULL));

        int elemento = rand() % ordem_da_matriz; // random number from 0 up to 8 if order = 9

      }while(matriz[elemento][elemento] != 0;) // repete ate que ache um elemento na matriz que nao seja o central, que e igual a 1

      // escolher um numero de 1 a 4 aleatoriamente -> condicao 3

      srand(time(NULL));

      int random_number = rand() % 4 + 1; //random number from 1 up to 4

      switch(random_number){
        case 1: // go right


          break;
        case 2: // go up

          break;
        case 3: // go left

          break;
        case 4: // go down

          break;
        default:
          printf("Erro na aleatoriedade dos numeros\n\n");
          break;
        }// end switch random_number


      }while(bool_condicao2)//end of do while condicao 2


}while(verifica_condicao_principal <= condicao_principal)// end do while condicao principal -> Preencher 10% de ordem_da_matriz^2 vezes

  /* FIM */

  free(matriz); // desalocacao da matriz

  return 0;
}

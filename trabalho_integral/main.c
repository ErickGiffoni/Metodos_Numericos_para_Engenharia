#include <stdio.h>
#include "integral.h"


int main (){

  for(int i =0; i<7; i++){
    printf("1- %.20lf \t\t\t2- %.20lf\n\n", integral_n(i), integral_n_1(i));
  }//end for imprime resultudados
  printf("******************************************\n");

  return 0;
}

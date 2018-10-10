#include <stdio.h>
#include "integral.h"


int main (){

  printf("\n\t\tNumerical Methods for Engineering\n\n\te^-1 * integral from 0 to 1 e^x * x^n | n = {0,1,2,3,4,5,6,7}\n\n");
  printf("\tFirst Method : \t\t\t\t\tSecond Method: \n\n");
  for(int i =0; i<=7; i++){
    printf("1- %.30lf \t\t2- %.30lf\n\n", integral_n(i), integral_n_1(i));
  }//end for imprime resultudados

  printf("***************************************************************************************\n\n");

  return 0;
}

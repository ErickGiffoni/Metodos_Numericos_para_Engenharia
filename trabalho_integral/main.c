#include <stdio.h>
#include "integral.h"


int main (){

  printf("\n\t\t\tNumerical Methods for Engineering\n\n\te^-1 * integral from 0 to 1 e^x * x^n | n = {0,1,2,3,4,5,6,7}\n\n");
  printf("\t\tFirst Method : \t\t\t\t\t\tSecond Method: \n\n");
  for(int i =7; i>=0; i--){
    printf("1- %.40f \t\t2- %.40f\n\n", integral_n(7-i), integral_n_1(i+13));
    if(i==0){
      for(int j=12; j>=7; j--){
        printf("\t\t\t\t\t\t\t   %.40f\n\n", integral_n_1(j));
      }
    }
  }//end for imprime resultudados

  printf("***************************************************************************************\n\n");

  return 0;
}

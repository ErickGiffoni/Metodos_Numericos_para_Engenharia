#include "integral.h"
#include <math.h>
// funcao recursiva para a integral :
//      eˆ-1 * integral(0,1){ x^n * e^x * dx }

double integral_n(int n){
  double result = 0.0;
  if (n<0){
    //result = 1.0 - n*integral_n(n+1);
    //result =
    return -1; //pensar
  }//end if n<0
  else if (n>0){
    result = 1.0 - n*integral_n(n-1);
  }// end if n> 0
  else{
    result = 1.0 - exp(-1.0);
  }

}
double integral_n_1(int n){
  double result = 0.0;
  if (n<0){
    result =
  }//end if n<0
  else if (n>0){

  }// end if n> 0
  else{

  }

}

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
    return result;
  }// end if n> 0
  else{
    result = 1.0 - exp(-1.0);
    return result;
  }//end else

}
double integral_n_1(int n_1){
  double result = 0.0;
  if (n_1<0){
    //result = //pensar
    return -1;
  }//end if n<0
  else if (n_1>0){
    result = ( 1.0 - integral_n(n_1 + 1) )/(double)n_1+1; //chamando a integral_n p dar certo
    return result;
  }// end if n> 0
  else{
    result = 1.0 - exp(-1.0);
  }//end else

}

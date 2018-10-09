#ifndef INTEGRAL_LUIS_H
#define INTEGRAL_LUIS_H

#include <stdio.h>
#include <math.h>


double equacao_1(double in_1, int n){
  double in;

  in=1-(double)n*in_1;
  return in;
}

double equacao_2(double in, int n){
  double in_1;

  in_1=(1-in)/(double)n;
  return in_1;
}

#endif

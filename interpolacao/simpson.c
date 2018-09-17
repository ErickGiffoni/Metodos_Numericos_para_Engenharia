#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// implementar retangulo

// implementar trapezio

// implementar/importar Lagrange


double f(double x);

int main (int argc , char * argv[]){

  // variables

  double a = atof(argv[1]); // integrar de a a b
  double b = atof(argv[2]); // a deve ser menor que b

  double h = atof(argv[3]); // altura deve ser menor que b-a
  //double h = (b-a) / numero_de_pontos;

  double xk = a;

  //double x[]; // vetor com os valores da funcao em x, vindos de Lagrange
  double simpson = 0.0;

  //simpson

  while ( xk <= b){
    simpson += (f(xk) + 4*f((2*xk + h)/2.0) + f(xk + h));
    xk += h;
  }
  simpson *= h/6.0; // divide por 1/6 ao final


  printf("a integral de exp(-x*x) entre %f e %f é : %f\n\n", a, b, simpson);

  return 0;
}

double f(double x){
  return exp(-x*x);
}

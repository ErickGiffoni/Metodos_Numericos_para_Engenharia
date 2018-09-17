#include <stdio.h>
#include <stdlib.h>

//Método de Lagrange para interpolacao de polinomios, entretanto so lemos o
// arquivo rsrsrs

int main(){

  double x[6], y[6];
  FILE *fp = fopen("lag.dat", "r");
  int k=0;
  while(k<6){
    fscanf(fp, "%lf %lf\n", &x[k], &y[k]);
    printf("%lf %lf\n", x[k], y[k]);
    k++;
  }
  fclose(fp);
  for(k=0; k<6; k++){
    printf("%lf %lf\n", x[k], y[k]);
  }

  return 0;
}

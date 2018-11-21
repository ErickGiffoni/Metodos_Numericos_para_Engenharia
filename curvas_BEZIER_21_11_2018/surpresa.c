#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* CURVAS BEZIER */

#define number double

typedef struct point{
  number x,y;
}Point;

int main(){

  Point p1,p2,p3;
  printf("enter p1 coordinates: ");
  scanf("%lf %lf", &p1.x, &p1.y);
  printf("enter p2 coordinates: ");
  scanf("%lf %lf", &p2.x, &p2.y);
  printf("enter p3 coordinates: ");
  scanf("%lf %lf", &p3.x, &p3.y);
  number h = 0.1;
  number t;
  Point pt;
  FILE *arq = fopen("surpresa.dat", "w");
  for(t=0; t<=1; t+=h){
    pt.x = pow(1-t,2)*p1.x + 2*t*(1-t)*p2.x + t*t*p3.x;
    pt.y = pow(1-t,2)*p1.y  + 2*t*(1-t)*p2.y + t*t*p3.y;
    printf("P(%lf) = %.5lf %.5lf\n", t, pt.x, pt.y);
    fprintf(arq, "%.5lf %.5lf\n", pt.x, pt.y);
  }
  fclose(arq);

  //FILE *gnu = fopen("surpresa.gpl", "w");
  //fprintf(gnu, "gnuplot plot 'surpresa.dat' w p pt 5 pallete\n");
  //fclose(gnu);
  //system("surpresa.gpl");

  return 0;
}

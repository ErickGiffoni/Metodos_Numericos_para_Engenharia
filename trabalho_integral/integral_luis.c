#include "integral_luis.h"
#include <stdio.h>

#define REF 0.1123865040693008414398016137627719268881004001098859195

int main(){

    double in_equacao2, in_equacao1=0;
    int n=7, max;

    in_equacao2=REF;

    for(n=7; n>0; n--){
        in_equacao1=equacao_1(in_equacao1, (7-n));
        in_equacao2=equacao_2(in_equacao2, n);
        printf("%lf\t%lf\n", in_equacao1,  in_equacao2);
    }


    return 0;
}

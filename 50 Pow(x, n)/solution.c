#include <stdio.h>


double myPow(double x, int n){
    double out = 1;
    int power = n >= 0 ? n : -n;

    int i = 1;
    while(i <= power && out <= 10000 && out >= -10000){
        out *= x;
        i++;
    }
    if(out > 10000) out = 10000;
    if(out < -10000) out = -10000;
    if(out == 0) return 0;
    return n < 0 ? 1 / out : out;
}


int main(){

    double temp = 2.0000;
    int power = -200000000;
    printf("%f ^ %d = %f\n", temp, power, myPow(temp, power));

    return 0;
}
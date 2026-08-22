#include <stdio.h>
#include <stdbool.h>


bool checkDivisibility(int n){
    int sum = 0, product = 1;
    int divisor = 1;
    while(n / divisor > 0){
        int digit = (n / divisor) % 10;
        sum += digit;
        product *= digit;
        divisor *= 10;
    }
    return !(n % (sum + product));
}


int main(){
    printf("Is divisible : %s\n", checkDivisibility(99) ? "True" : "False");
    return 0;
}
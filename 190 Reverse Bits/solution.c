#include <stdio.h>
#include <stdlib.h>


char* int_to_bit(int n){
    char* out = (char*) malloc(32 * sizeof(char));
    int index = 0;
    while(index < 32){
        out[index++] = n % 2 + '0';
        n /= 2;
    }
    return out;
}


int reverseBits(int n){
    char* temp = int_to_bit(n);
    int out = 0;
    int power = 1;

    for(int i = 31; i >= 0; i--){
        out += (temp[i] - '0') * power;
        power *= 2;
    }

    free(temp);
    return out;
}



int main(){
    int n = 43261596;
    printf("Original number : %d\n", n);
    printf("Reversed bits integer representation : %d\n", reverseBits(n));
    return 0;
}
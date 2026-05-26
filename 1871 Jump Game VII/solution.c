#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isLastIndex(int len, int index, int minJump, int maxJump, char* s, int* isOk){
    if(index == len - 1) {
        isOk[index] = 2;
        return true;
    }
    for(int i = (index + maxJump < len ? index + maxJump : len - 1); i >= index + minJump; i--){
        if(s[i] == '0'){
            if(!isOk[i]){
                isLastIndex(len, i, minJump, maxJump, s, isOk);
                if(isOk[i] == 2){
                    isOk[index] = 2;
                    return true;
                }
            }else if(isOk[i] == 2){
                isOk[index] = 2;
                return true;
            }
        }
    }
    isOk[index] = 1;
    return false;
}


bool canReach(char* s, int minJump, int maxJump){
    int len = strlen(s);
    int* isOk = (int*) calloc(len, sizeof(int));
    bool temp = isLastIndex(len, 0, minJump, maxJump, s, isOk);
    free(isOk);
    return temp;
}


int main(){

    char* temp = "011111000111000001011111010";
    int min_jump = 6;
    int max_jump = 8;
    printf("Can reach end for %s : %s\n", temp, canReach(temp, min_jump, max_jump) ? "true" : "false");

    return EXIT_SUCCESS;
}
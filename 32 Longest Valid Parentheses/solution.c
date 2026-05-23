#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s, int start, int end){
    int count = 0;
    for(int i = start; i < end; i++) {
        count += s[i] == '(' ? 1 : -1;
        if(count < 0) return false;
    }
    return count == 0;
}

int longestValidParentheses(char* s){
    int len = strlen(s);
    if(len < 1) return 0;

    int window_size = len;
    while(window_size >= 2){
        for(int i = 0; i < len; i++){
            if(i + window_size > len) break;
            if(isValid(s, i, i + window_size)) return window_size;
        }
        window_size--;
    }
    return 0;
}

int main(){

    char* temp = "(()";
    printf("Longest valid parenthesis substring for %s : %d\n", temp, longestValidParentheses(temp));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int minimumPushes(char* word){
    int push_map[26];

    int len = strlen(word), used_count = 0, push_count = 0;
    for(int i = 0; i < 26; i++) push_map[i] = 0;
    
    for(int i = 0; i < len; i++){
        if(used_count < 26){
            push_map[word[i] - 'a'] = (int) (used_count / 8) + 1;
            used_count++;
        }
        push_count += push_map[word[i] - 'a'];
    }

    for(int i = 0; i < len; i++){
        printf("%c : %d\n", word[i], push_map[word[i] - 'a']);
    }
    return push_count;
}



int main(){

    char* s = "xycdefghij";
    printf("Min pushed for %s : %d\n", s, minimumPushes(s));

    return 0;
}
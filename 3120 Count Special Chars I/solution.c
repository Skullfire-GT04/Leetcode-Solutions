#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int numberOfSpecialChars(char* word){
    int len = strlen(word);
    int count = 0;
    int* found = (int*) calloc(26, sizeof(int));

    for(int i = 0; i < len; i++){
        int index = isupper(word[i]) ? word[i] - 'A' : word[i] - 'a';
        if(isupper(word[i])){
            if(!found[index]){
                found[index] = 2;
                continue;
            }else{
                if(found[index] == 3){
                    count++;
                    found[index] = 4;
                }else{continue;}
            }
        }else{
            if(!found[index]){
                found[index] = 3;
                continue;
            }else{
                if(found[index] == 2){
                    count++;
                    found[index] = 4;
                }else{continue;}
            }
        }
    }
    free(found);
    return count;
}


int main(){
    char* temp = "aaAbcBC";
    printf("Number of special chars in %s : %d\n", temp, numberOfSpecialChars(temp));
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* validSequence(char* word1, char* word2, int* returnSize){
    int word1_len = strlen(word1);
    int word2_len = strlen(word2);

    int* out = NULL;
    int count = 0, used_missing_char = 0;

    while(count < word2_len){
        // 1. When we find matching char but the remaining characters are too little to fill return size
        // 2. When we find two or more characters which are missing
        // 3. If the character we are looking for is the last one and we still haven't used the missing character
        int last_used_index = out ? out[count - 1] : -1;
        int index = -1;
        for(int i = last_used_index + 1; i < word1_len - (word2_len - (count + 1)); i++){
            if(word1[i] == word2[count]){
                index = i;
                break;
            }
        }
        if(index >= 0 || (index < 0 && !used_missing_char)){
            count++;
            out = (int*) realloc(out, sizeof(int) * count);
            if(count == word2_len && !used_missing_char) {
                out[count - 1] = last_used_index + 1;
                used_missing_char = 1;
            }
            else{
                out[count - 1] = index >= 0 ? index : last_used_index + 1;
            }
            if(index < 0) used_missing_char = 1;
        }else{
            free(out);
            *returnSize = 0;
            return NULL;
        }
    }

    *returnSize = count;
    return out;
}



int main(){
    int size = 0;
    char* word1 = "ccbccccbcc";
    char* word2 = "b";

    int* seq = validSequence(word1, word2, &size);
    for(int i = 0; i < size; i++){
        printf("%d ", seq[i]);
    }
    printf("\n");

}
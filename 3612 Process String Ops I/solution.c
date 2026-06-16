#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* processStr(char* s){

    char* out = NULL;
    int count = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '*'){
            if(!count) continue;
            --count;
            if(!count) out = NULL;
            else{ 
                out[count] = '\0';
                out = (char*) realloc(out, count);
            }
        }
        else if(s[i] == '#'){
            if(!count) continue;
            count *= 2;
            out = (char*) realloc(out, count);
            for(int i = count / 2; i < count; i++){
                out[i] = out[i - (count / 2)];
            }
        }
        else if(s[i] == '%'){
            if(!count) continue;
            for(int i = 0; i < count / 2; i++){
                char temp = out[i];
                out[i] = out[count - (i + 1)];
                out[count - (i + 1)] = temp;
            }
        }else{
            out = (char*) realloc(out, ++count);
            out[count - 1] = s[i];
        }
    }
    out = (char*) realloc(out, count + 1);
    out[count] = '\0';
    return out;
}


int main(){
    char* s = "z*#";

    printf("Ops(%s) : %s\n", s, processStr(s));
    return 0;
}
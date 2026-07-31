#include <stdio.h>
#include <string.h>


int minimumPushes(char* word){
    int n = strlen(word), push_count = 0;
    int used = 0;

    int count_map[26];
    int push_map[26];

    for(int i = 0; i < 26; i++){
        count_map[i] = 0;
        push_map[i] = 0;
    }

    for(int i = 0; i < n; i++){
        count_map[word[i] - 'a']++;
    }
    while(used < 26){
        int curr_max = 0;
        for(int i = 0; i < 26; i++){
            if(count_map[i] > count_map[curr_max]){
                curr_max = i;
            }
        }
        count_map[curr_max] = -1;
        push_map[curr_max] = (int)(used / 8) + 1;
        used++;
    }

    for(int i = 0; i < 26; i++){
        if(count_map[i] == -1) printf("%c : %d\n", i + 'a', push_map[i]);
    }

    for(int i = 0; i < n; i++){
        push_count += push_map[word[i] - 'a'];
    }

    return push_count;
}




int main(){

    char* word = "aabbccddeeffgghhiiiiii";
    printf("Minimum pushed to types %s : %d\n", word, minimumPushes(word));

    return 0;
}
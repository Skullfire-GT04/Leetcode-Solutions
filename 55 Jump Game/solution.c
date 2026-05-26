#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool canJump(int* nums, int numsSize){
    bool* temp = (bool*) calloc(numsSize, sizeof(bool));
    temp[numsSize - 1] = true;
    for(int i = numsSize - 1; i >= 0; i--){
        for(int j = i + 1; j <= (i + nums[i] < numsSize ? i + nums[i] : numsSize - 1); j++){
            if(temp[j]){
                temp[i] = true;
                break;
            }
        }
    }
    bool can_jump = temp[0];
    free(temp);
    return can_jump;
}


int main(){

    int temp[] = {3, 2, 1, 0, 4};
    printf("Can jump to the end : %s\n", canJump(temp, 5) ? "true" : "false");

    return 0;
}
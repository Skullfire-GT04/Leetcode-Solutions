#include <stdio.h>


int jump(int* nums, int numsSize){

    int min_jumps[numsSize];

    for(int i = 0; i < numsSize; i++) min_jumps[i] = -1;

    for(int i = numsSize - 1; i >= 0; i--){
        if(i == numsSize - 1) {
            min_jumps[i] = 0;
            continue;
        }
        int min_jump = -1;
        for(int j = i; j <= nums[i] + i && j < numsSize; j++){
            if(min_jumps[j] >= 0){
                if(min_jump < 0) {
                    min_jump = min_jumps[j] + 1;
                    continue;
                }
                if(min_jumps[j] + 1 < min_jump) min_jump = min_jumps[j] + 1;
            }
        }
        min_jumps[i] = min_jump;
    }

    for(int i = 0; i < numsSize; i++){
        printf("%d ", min_jumps[i]);
    }
    printf("\n");

    return min_jumps[0];
}


int main(){

    int nums[] = {2, 3, 0, 1, 4};
    printf("Minimum number of jumps : %d\n", jump(nums, 5));

    return 0;
}

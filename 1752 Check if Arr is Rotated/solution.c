#include <stdio.h>
#include <stdbool.h>

bool check(int* nums, int numsSize){
    bool found_cliff = false;
    for(int i = 0; i < numsSize; i++){
        if(i + 1 < numsSize && nums[i] > nums[i + 1]){
            if(found_cliff) return false;
            found_cliff = true;
            if(i + 2 < numsSize && nums[i + 1] > nums[i + 2]) return false;
            else{
                if(nums[0] < nums[i + 1]) return false;
            }
        }
        if(i == numsSize - 1 && found_cliff){
            if(nums[0] < nums[i]) return false;
        }
    }
    return true;
}


int main(){

    int temp[] = {5, 1, 5, 1};
    
    printf("Is sorted and rotated : %d\n", check(temp, 5));

    return 0;
}
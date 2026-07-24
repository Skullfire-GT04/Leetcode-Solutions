#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void recursiveAdd(int* nums, int numsSize, int index, int* items, bool* used_items, int itemsSize, int*** out, int* count){
    if(index >= numsSize){
        (*count)++;
        (*out) = (int**) realloc(*out, sizeof(int*) * (*count));
        int* numsCopy = (int*) malloc(sizeof(int) * numsSize);
        for(int i = 0; i < numsSize; i++) numsCopy[i] = nums[i];
        (*out)[(*count) - 1] = numsCopy;
        return;
    }

    for(int i = 0; i < itemsSize; i++){
        if(!used_items[i]){
            used_items[i] = true;
            nums[index] = items[i];
            recursiveAdd(nums, numsSize, index + 1, items, used_items, itemsSize, out, count);
            used_items[i] = false;
        }
    }

}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** out = NULL;
    int count = 0;
    bool* used = (bool*) malloc(sizeof(bool) * numsSize);
    for(int i = 0; i < numsSize; i++) used[i] = false;
    int* temp = (int*) malloc(sizeof(int) * numsSize);
    recursiveAdd(temp, numsSize, 0, nums, used, numsSize, &out, &count);

    *returnSize = count;
    (*returnColumnSizes) = malloc(sizeof(int) * count);
    for(int i = 0; i < count; i++){
        (*returnColumnSizes)[i] = numsSize;
    }
    return out;
}


int main(){

    int nums[] = {1, 2, 3};
    int returnSize = 0;
    int* returnSizes;

    int** permutations = permute(nums, 3, &returnSize, &returnSizes);
    printf("Total permutations : %d\n", returnSize);

    for(int i = 0; i < returnSize; i++){
        printf("[");
        for(int j = 0; j < returnSizes[i]; j++){
            printf("%d", permutations[i][j]);
            if(j != returnSizes[i] - 1)
            printf(", ");
        }
        printf("]\n");
    }

    return 0;
}
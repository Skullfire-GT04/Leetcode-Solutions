#include <stdio.h>
#include <stdlib.h>


int jumpTillCompletion(int* valid_jumps, int d, int index, int* pre_computed_jumps, int* arrSize, int* original_arr){
    if(!valid_jumps[index]){
        return 1;    
    }
    if(pre_computed_jumps[index]){
        return pre_computed_jumps[index];
    }
    int max_jumps = 1;
    for(int j = index - 1; j >= (index - d >= 0 ? index - d : 0); j--){
        if(original_arr[j] >= original_arr[index]) break;
        int temp = jumpTillCompletion(valid_jumps, d, j, pre_computed_jumps, arrSize, original_arr);
        max_jumps = max_jumps < temp + 1 ? temp + 1 : max_jumps;
    }
    for(int j = index + 1; j <= (index + d < *arrSize ? index + d : *arrSize - 1); j++){
        if(original_arr[j] >= original_arr[index]) break;
        int temp = jumpTillCompletion(valid_jumps, d, j, pre_computed_jumps, arrSize, original_arr);
        max_jumps = max_jumps < temp + 1 ? temp + 1 : max_jumps;
    }
    pre_computed_jumps[index] = max_jumps;
    return max_jumps;
}


int maxJumps(int* arr, int arrSize, int d){
    int* valid_jumps = (int*) calloc(arrSize, sizeof(int));

    for(int i = 0; i < arrSize; i++){
        int j = i;
        for(int j = i - 1; j >= (i - d >= 0 ? i - d : 0); j--){
            if(arr[j] >= arr[i]) break;
            valid_jumps[i]++;
        }
        for(int j = i + 1; j <= (i + d < arrSize ? i + d : arrSize - 1); j++){
            if(arr[j] >= arr[i]) break;
            valid_jumps[i]++;
        }
        
    }
    int max_jumps = 1;
    int* max_jumps_from_here = (int*) calloc(arrSize, sizeof(int));
    
    for(int i = 0; i < arrSize; i++){
        if(valid_jumps[i]){
            int temp = jumpTillCompletion(valid_jumps, d, i, max_jumps_from_here, &arrSize, arr);
            max_jumps = max_jumps < temp ? temp : max_jumps;
        }
    }
    printf("Index      : ");
    for(int i = 0; i < arrSize; i++) printf("%d ", i);
    printf("\nValid Jumps: ");
    for(int i = 0; i < arrSize; i++) printf("%d ", valid_jumps[i]);
    printf("\nTotal Jumps: ");
    for(int i = 0; i < arrSize; i++) printf("%d ", max_jumps_from_here[i]);
    printf("\n");

    free(valid_jumps);
    free(max_jumps_from_here);
    return max_jumps;
}

int main(){

    int temp[] = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
    printf("Max jumps : %d\n", maxJumps(temp, 11, 2));

    return 0;
}
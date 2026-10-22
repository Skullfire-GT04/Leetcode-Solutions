#include <stdio.h>
#include <stdlib.h>


void printIntervals(int** intervals, size_t size){    
    printf("[ ");
    for(int i = 0; i < size; i++){
        printf("[%d, %d]", intervals[i][0], intervals[i][1]);
        if(i + 1 < size) printf(", ");
    }
    printf(" ]\n");
}


void insertInterval(int*** intervals, int* size, int start, int end){
    *intervals = (int**) realloc(*intervals, sizeof(int*) * (*size + 1));
    (*size)++;
    (*intervals)[*size - 1] = (int*) malloc(sizeof(int) * 2);
    (*intervals)[*size - 1][0] = start;
    (*intervals)[*size - 1][1] = end;
}



int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColSize){
    int** out = (int**) malloc(sizeof(int*));
    int size = 0;
    
    int not_overlapping = 0, at_end = 0;
    if(!intervalsSize){
        not_overlapping = 1;
        at_end = 1;
    }
    else if(intervals[0][0] > newInterval[1]){
        not_overlapping = 1;
        insertInterval(&out, &size, newInterval[0], newInterval[1]);
    }
    else if(intervals[intervalsSize - 1][1] < newInterval[0]){
        not_overlapping = 1;
        at_end = 1;
    }
    
    if(not_overlapping){
        for(int i = 0; i < intervalsSize; ++i){
            insertInterval(&out, &size, intervals[i][0], intervals[i][1]);
        }
        if(at_end){
            insertInterval(&out, &size, newInterval[0], newInterval[1]);
        }
    }else{
        int index = 0;
        while(!(intervals[index][0] >= newInterval[0]) && !(intervals[index][0] <= newInterval[0] && intervals[index][1] >= newInterval[0])){
            insertInterval(&out, &size, intervals[index][0], intervals[index][1]);
            index++;
        }
        int start = newInterval[0] < intervals[index][0] ? newInterval[0] : intervals[index][0];
        while(index < intervalsSize && intervals[index][1] < newInterval[1]) index++;

        if(index < intervalsSize){
            int end;
            if(intervals[index][0] <= newInterval[1]){
                end = intervals[index][1];
                index++;
            }else{
                end = newInterval[1];
            }
            insertInterval(&out, &size, start, end);
            while(index < intervalsSize){
                insertInterval(&out, &size, intervals[index][0], intervals[index][1]);
                index++;
            }
        }
        else{
            insertInterval(&out, &size, start, newInterval[1]);
        }
    }
    
    *returnSize = size;
    *returnColSize = (int*) malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        (*returnColSize)[i] = 2;
    }
    return out;
}



int main(){

    int** intervals = (int**) malloc(sizeof(int*) * 5);
    for(int i = 0; i < 5; i++){
        intervals[i] = (int*) malloc(sizeof(int) * 2);
    }
    intervals[0][0] = 1;
    intervals[0][1] = 2;
    intervals[1][0] = 3;
    intervals[1][1] = 5;
    intervals[2][0] = 6;
    intervals[2][1] = 7;
    intervals[3][0] = 8;
    intervals[3][1] = 10;
    intervals[4][0] = 12;
    intervals[4][1] = 16;

    int* intervalColSize = (int*) malloc(sizeof(int) * 5);
    for(int i = 0; i < 5; i++) intervalColSize[i] = 2;


    int* new_interval = (int*) malloc(sizeof(int) * 2);
    new_interval[0] = 4;
    new_interval[1] = 8;

    int* returnSize = (int*) malloc(sizeof(int));
    int* returnColSize;

    printf("Intervals before insertion:\n");
    printIntervals(intervals, 5);

    int** newIntervals = insert(intervals, 5, intervalColSize, new_interval, 2, returnSize, &returnColSize);

    printf("Intervals after insertion:\n");
    printIntervals(newIntervals, *returnSize);
   

    return 0;
}
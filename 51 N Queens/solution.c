#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define NUM_QUEENS 9


void print_answer(char*** board, int n, int count){
    for(int i = 0; i < count; i++){
        printf("Answer : %d\n", i + 1);
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                printf(" %c ", board[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}


bool calc_attack_squares(char** board, int row, int col, int n){

    // attacking the row
    for(int i = 0; i < n; i++){
        if(i == col) continue;
        if(board[row][i] == 'Q') return false;
        board[row][i] = 'A';
    }

    // attacking the column
    for(int i = 0; i < n; i++){
        if(i == row) continue;
        if(board[i][col] == 'Q') return false;
        board[i][col] = 'A';
    }

    // attacking the diagonals

    // the upper left diagonal
    int temp_row = row - 1;
    int temp_col = col - 1;
    while(temp_row >= 0 && temp_col >= 0) {
        if(board[temp_row][temp_col] == 'Q') return false;
        board[temp_row--][temp_col--] = 'A';
    }

    // the upper right diagonal
    temp_row = row - 1;
    temp_col = col + 1;
    while(temp_row >= 0 && temp_col < n) {
        if(board[temp_row][temp_col] == 'Q') return false;
        board[temp_row--][temp_col++] = 'A';
    }

    // the lower left diagonal
    temp_row = row + 1;
    temp_col = col - 1;
    while(temp_row < n && temp_col >= 0){
        if(board[temp_row][temp_col] == 'Q') return false;
        board[temp_row++][temp_col--] = 'A';
    }

    // the lower right diagonal
    temp_row = row + 1;
    temp_col = col + 1;
    while(temp_row < n && temp_col < n){
        if(board[temp_row][temp_col] == 'Q') return false;
        board[temp_row++][temp_col++] = 'A';
    }

    return true;
}


void place_queens(char**** answers, int* answer_count, char** board, int max_count, int curr_count, int n, int next_row){
    if(next_row > n) return;
    if(curr_count == max_count){
        char** answer = (char**) malloc(sizeof(char*) * n);
        for(int i = 0; i < n; i++) answer[i] = (char*) malloc(sizeof(char) * n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'Q')
                    answer[i][j] = board[i][j];
                else answer[i][j] = '.';
            }
        }
        
        *answers = (char***) realloc(*answers, (*answer_count + 1) * sizeof(char**));
        (*answers)[*answer_count] = answer;
        (*answer_count)++;
        return;
    }

    for(int i = 0; i < n; i++){
        board[next_row][i] = 'Q';
        if(calc_attack_squares(board, next_row, i, n)){
            place_queens(answers, answer_count, board, max_count, curr_count + 1, n, next_row + 1);
        }
        board[next_row][i] = '.';
    }
}


char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char*** out = (char***) malloc(sizeof(char**));
    int count = 0;

    char** board = (char**) malloc(sizeof(char*) * n);
    for(int i = 0; i < n; i++) board[i] = (char*) malloc(sizeof(char) * n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            board[i][j] = '.';
        }
    }
    place_queens(&out, &count, board, n, 0, n, 0);
    *returnSize = count;
    free(board);
    return out;
}



int main(){
    
    int returnSize = 0;

    int** cols_size = (int**) malloc(sizeof(int*) * NUM_QUEENS);
    for(int i = 0; i < NUM_QUEENS; i++){
            cols_size[i] = (int*) malloc(sizeof(int) * NUM_QUEENS);
            for(int j = 0; j < NUM_QUEENS; j++){
                cols_size[i][j] = NUM_QUEENS;
            }
        }
        
    char*** answer= solveNQueens(NUM_QUEENS, &returnSize, cols_size);
    print_answer(answer, NUM_QUEENS, returnSize);

    return 0;
}
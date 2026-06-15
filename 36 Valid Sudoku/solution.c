#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



bool isValidSudoku(char** boards, int boardSize, int* boardColSize){

    int validator_row[10];
    int validator_col[10];

    for(int i = 0; i < 10; i++){
        validator_col[i] = 0;
        validator_row[i] = 0;
    }
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(boards[i][j] != '.'){
                int temp = boards[i][j] - '0';
                validator_row[temp]++;
            }
            if(boards[j][i] != '.'){
                int temp = boards[j][i] - '0';
                validator_col[temp]++;
            }
        }
        for(int k = 1; k < 10; k++){
            if(validator_col[k] > 1 || validator_row[k] > 1) return false;
            validator_row[k] = 0;
            validator_col[k] = 0;
        }
    }

    int validator_block[10];

    for(int i = 0; i < 10; i++) validator_block[i] = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            for(int row = i * 3; row < (i + 1) * 3; row++){
                for(int col = j * 3; col < (j + 1) * 3; col++){
                    if(boards[row][col] != '.'){
                        int temp = boards[row][col] - '0';
                        validator_block[temp]++;
                    }
                }
            }

            for(int k = 1; k < 10; k++){
                if(validator_block[k] > 1) return false;
                validator_block[k] = 0;
            }

        }
    }

    return true;
}


int main(){

    char board_rpr[][10] = {{'8','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};

int temp[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

char** board = (char**) malloc(sizeof(char*) * 10);
for(int i = 0; i < 10; i++){
    board[i] = (char*) malloc(sizeof(char) * 10);
}
for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
        board[i][j] = board_rpr[i][j];
    }
}

printf("Board is valid ? %s\n", isValidSudoku(board, 10, temp) ? "true" : "false");

return 0;
}
#include <stdio.h>
#include <stdlib.h>


void print_board(char** board){
    printf("_____________________\n");
    for(int i = 0; i < 9; i++){
        printf("| ");
        for(int j = 0; j < 9; j++){
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("---------------------\n");
}


int* get_valid_options(char** board, int row, int col){
    int* out = (int*) malloc(sizeof(int));
    out[0] = 0;

    if(board[row][col] != '.') return out;
    
    int temp[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < 9; i++){
        if(board[row][i] != '.') temp[board[row][i] - '0']++;
        if(board[i][col] != '.') temp[board[i][col] - '0']++;
    }

    int block_row = (row / 3) * 3;
    int block_col = (col / 3) * 3;

    for(int i = block_row; i < block_row + 3; i++){
        for(int j = block_col; j < block_col + 3; j++){
            if(board[i][j] != '.') temp[board[i][j] - '0']++;
        }
    }

    for(int i = 1; i < 10; i++){
        if(!temp[i]){
            out[0]++;
            out = (int*) realloc(out, sizeof(int) * (out[0] + 1));
            out[out[0]] = i;
        }
    }
    return out;
}


int backtrackSolve(char** board, int row, int col){
    if(row >= 9) return 1;
    int new_col = col + 1;
    int new_row = row;
    if(new_col >= 9){
        new_col = 0;
        new_row++;
    }
    if(board[row][col] != '.') {return backtrackSolve(board, new_row, new_col);}

    int* options = get_valid_options(board, row, col);

    if(options[0] < 1) {
        free(options);
        return 0;
    }

    int index = 1;
    
    while(index < options[0] + 1){
        board[row][col] = options[index] + '0';
        if(backtrackSolve(board, new_row, new_col)) break;
        index++;
    }

    if(index >= options[0] + 1){
        board[row][col] = '.';
        free(options);
        return 0;
    }
    free(options);
    return 1;
}


void solveSudoku(char** board, int boardSize, int* boardColSize){
    backtrackSolve(board, 0, 0);
}


int main(){

    char board_rpr [][9] = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}}
    ;

    char** board = (char**) malloc(sizeof(char*) * 9);
    for(int i = 0; i < 9; i++){
        board[i] = (char*) malloc(sizeof(char) * 9);
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            board[i][j] = board_rpr[i][j];
        }
    }

    int temp[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

    printf("Before solving:\n");
    print_board(board);

    solveSudoku(board, 9, temp);

    printf("\nAfter solving:\n");
    print_board(board);

    return 0;
}
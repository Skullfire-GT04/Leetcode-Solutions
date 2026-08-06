

class TotalQueens{

    public static void change_squares(char[][] board, int row, int col, char delta){
        int n = board.length;
        int curr_row = row + 1, curr_col = col + 1;
        while(curr_row < n && curr_col < n){
            board[curr_row++][curr_col++] = delta;
        }
        curr_row = row + 1;
        curr_col = col - 1;
        while(curr_row < n && curr_col >= 0){
            board[curr_row++][curr_col--] = delta;
        }
        curr_row = row - 1;
        curr_col = col + 1;
        while(curr_row >= 0 && curr_col < n){
            board[curr_row--][curr_col++] = delta;
        }
        curr_row = row - 1;
        curr_col = col - 1;
        while(curr_row >= 0 && curr_col >= 0){
            board[curr_row--][curr_col--] = delta;
        }
        for(int i = 0; i < n; i++){
            if(i == col) continue;
            board[row][i] = delta;
        }
        for(int i = 0; i < n; i++){
            if(i == row) continue;
            board[i][col] = delta;
        }
    }

    public static void place_queens(char[][] board, int[] answer_count, int next_row, int curr_count){
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
        System.out.println();

        if(curr_count == board.length){
            answer_count[0]++;
            return;
        }
        for(int i = 0; i < board.length; i++){
            if(board[next_row][i] != 'a'){
                char[][] copy_board = new char[board.length][board[0].length];
                for(int j = 0; j < board.length; j++){
                    for(int k = 0; k < board.length; k++){
                        copy_board[j][k] = board[j][k];
                    }
                }
                copy_board[next_row][i] = 'q';
                change_squares(copy_board, next_row, i, 'a');
                place_queens(copy_board, answer_count, next_row + 1, curr_count + 1);
            }
        }
    }

    public static int totalQueens(int n){
        int[] answer_count = {0};
        char[][] board = new char[n][n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = '.';
            }
        }
        place_queens(board, answer_count, 0, 0);

        return answer_count[0];
    }

    static void inc(int[] num) {num[0]++;}

    public static void main(String[] args){
        int n = 4;
        System.out.println(totalQueens(n));

        // char[][] board = new char[n][n];

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         board[i][j] = 'a';
        //     }
        // }
        // change_squares(board, 0, 1, 'b');
        // for(int i = 0; i < board.length; i++){
        //     for(int j = 0; j < board[0].length; j++){
        //         System.out.print(board[i][j]);
        //     }
        //     System.out.println();
        // }
    }
    
}

import java.util.ArrayList;

class Solution{

    public static int getAliveCount(int[][] board, int row, int col, int num_rows, int num_cols){
        int out = 0;

        if(col - 1 >= 0){
            if(row - 1 >= 0){
                if(board[row - 1][col - 1] == 1) out++;
            }
            if(board[row][col - 1] == 1) out++;
            if(row + 1 < num_rows){
                if(board[row + 1][col - 1] == 1) out++;
            }
        }
        if(col + 1 < num_cols){
            if(row - 1 >= 0){
                if(board[row - 1][col + 1] == 1) out++;
            }
            if(board[row][col + 1] == 1) out++;
            if(row + 1 < num_rows){
                if(board[row + 1][col + 1] == 1) out++;
            }
        }
        if(row - 1 >= 0){
            if(board[row - 1][col] == 1) out++;
        }
        if(row + 1 < num_rows){
            if(board[row + 1][col] == 1) out++;
        }
        
        return out;
    }


    public static void gameOfLife(int[][] board){
        int n = board.length;
        int m = board[0].length;

        ArrayList<Integer[]> change_coords = new ArrayList<>();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int alive_count = getAliveCount(board, i, j, n, m);

                if(board[i][j] == 1){
                    if(alive_count < 2 || alive_count > 3){
                        change_coords.add(new Integer[]{i, j});
                    }
                }
                else{
                    if(alive_count == 3) change_coords.add(new Integer[]{i, j});
                }
            }
        }
        for(Integer[] coords : change_coords){
            board[coords[0]][coords[1]] = board[coords[0]][coords[1]] == 1 ? 0 : 1;
        }
    }


    public static void main(String[] args){
        
        int[][] temp = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 1, 1},
            {0, 0, 0}
        };

        gameOfLife(temp);

        for(int[] row : temp){
            for(int cell : row){
                System.out.print(cell + " ");
            }
            System.out.println();
        }

    }

}
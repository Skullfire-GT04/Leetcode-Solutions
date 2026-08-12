class MaxAreaOfNonOverlappingSquares {

    public static boolean isValid(int row, int col, int[][] mat, int size){
        for(int i = row; i < row + size; i++){
            for(int j = col; j < col + size; j++){
                if(mat[i][j] == 0) return false;
            }
        }
        return true;
    }

    public static int maxArea(int[][] mat) {
        int width = mat[0].length, height = mat.length;
        int max_square_size = Math.min(width, height);
        int total_area = width * height;
        while(2 * (max_square_size * max_square_size) > total_area) max_square_size--;
        int[] rect1 = {0, 0};
        boolean found_rect1 = false, found_rect2 = false;
        int curr_size = max_square_size;
        while((!found_rect1 && !found_rect2) && curr_size > 0){
            int row = 0, column = 0;
            while(row <= height - curr_size){
                if(isValid(row, column, mat, curr_size)){
                    found_rect1 = true;
                    rect1[0] = row;
                    rect1[1] = column;
                    break;
                }
                column++;
                if(column > width - curr_size){
                    column = 0;
                    row++;
                }
                
            }
            if(!found_rect1){
                curr_size--;
                continue;
            }
            
            column = 0;
            while(row <= height - curr_size){
                if(isValid(row, column, mat, curr_size)){
                    boolean does_not_overlap = true;
                    outer: for(int i = row; i < row + curr_size; i++){
                        for(int j = column; j < column + curr_size; j++){
                            if(overlaps(rect1[0], rect1[1], curr_size, curr_size, i, j)){
                                does_not_overlap = false;
                                break outer;
                            }
                        }
                    }
                    if(does_not_overlap){
                        found_rect2 = true;
                        break;
                    }
                }
                column++;
                if(column > width - curr_size){
                    column = 0;
                    row++;
                }
            }
            if(!found_rect2) {
                curr_size--;
                found_rect1 = false;
            }
        }
        return curr_size > 0 ? curr_size * curr_size : 0;
    }

    public static boolean overlaps(int x1, int y1, int width1, int height1, int x2, int y2){
        return (x2 >= x1 && x2 < x1 + width1) && (y2 >= y1 && y2 < y1 + height1); 
    }

    public static void main(String[] args) {
        
        int[][] mat = {{0,0,0,1,1},{0,1,0,0,1},{1,1,0,1,1},{1,0,1,1,1},{0,0,1,1,0}};
        System.out.println(maxArea(mat));
    }

}

import java.util.ArrayList;
import java.util.List;

class Solution{

    public static List<Integer> spiralOrder(int[][] matrix){
        List<Integer> out = new ArrayList<>();
        int row = 0, col = 0;
        int right_limit = matrix[0].length;
        int lower_limit = matrix.length;
        int left_limit = -1;
        int upper_limit = 0;
        String direction = "right";
        while(out.size() != matrix[0].length * matrix.length){
            out.add(matrix[row][col]);
            switch (direction) {
                case "right":
                    col++;
                    if(col >= right_limit){
                        direction = "down";
                        col--;
                        right_limit--;
                        row++;
                    }
                    break;
                case "down":
                    row++;
                    if(row >= lower_limit){
                        direction = "left";
                        row--;
                        lower_limit--;
                        col--;
                    }
                    break;
                case "left":
                    col--;
                    if(col <= left_limit){
                        direction = "up";
                        col++;
                        left_limit++;
                        row--;
                    }
                    break;
                case "up":
                    row--;
                    if(row <= upper_limit){
                        direction = "right";
                        row++;
                        upper_limit++;
                        col++;
                    }
                default:
                    break;
            }
        }
        return out;
    }

    public static void main(String[] args){
        int[][] nums = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        List<Integer> temp = spiralOrder(nums);
        System.out.println("Matrix in spiral order:");
        for(int i : temp){
            System.out.print(i + " ");
        }
        System.out.println();
    }

}


public class solution {
    
    public static int maxProduct(int[] nums){
        int[] maxes = new int[2];
        maxes[0] = -1;
        maxes[1] = -1;
        for(int i = 0; i < 2; i++){
            int curr_max = -1;
            for(int j = 0; j < nums.length; j++){
                boolean used = false;
                for(int k : maxes) {
                    if(k == j) {
                        used = true;
                        break;
                    }
                }
                if(used) continue;
                if(curr_max < 0) curr_max = j;
                else if(nums[j] > nums[curr_max]) curr_max = j;
            }
            maxes[i] = curr_max;
        }

        return (nums[maxes[0]] - 1) * (nums[maxes[1]] - 1);
    }

    public static void main(String[] args){
        int[] nums = {3, 7};
        System.out.println("Max product : " + maxProduct(nums));
    }

}

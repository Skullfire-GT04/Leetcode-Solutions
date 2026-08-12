import java.util.HashMap;


class LengthOfLongestGoodSubArray{


    public static int maxSubarrayLength(int[] nums, int k){
        int l = 0, r = 0;
        int max_len = 0;
        HashMap<Integer, Integer> count_map = new HashMap<>();
        while(r < nums.length){
            if(!count_map.containsKey(nums[r])){
                count_map.put(nums[r], 0);
            }
            count_map.replace(nums[r], count_map.get(nums[r]) + 1);
            if(count_map.get(nums[r]) > k){
                while(count_map.get(nums[r]) > k){
                    count_map.replace(nums[l], count_map.get(nums[l]) - 1);
                    l++;
                }
            }
            r++;
            max_len = Math.max(max_len, r - l);
        }
        return max_len;
    }


    public static void main(String[] args){
        int[] nums = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
        System.out.println(maxSubarrayLength(nums, 1));
    }
    
}

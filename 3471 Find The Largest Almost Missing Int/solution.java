import java.util.HashMap;


class AlmostMissingInteger{

    public static int largestInteger(int[] nums, int k){
        HashMap<Integer, Integer> count_map = new HashMap<>();
        int l = 0, r = k - 1;
        int max_num = -1;
        while(r < nums.length){
            HashMap<Integer, Integer> seen_map = new HashMap<>();
            for(int index = l; index <= r; index++){
                if(seen_map.containsKey(nums[index])) continue;
                if(!count_map.containsKey(nums[index])){
                    count_map.put(nums[index], 0);
                }
                count_map.replace(nums[index], count_map.get(nums[index]) + 1);
                seen_map.put(nums[index], 1);
            }
            r++;
            l++;
        }
        if(!count_map.isEmpty()){
            for(int num : nums){
                if(count_map.get(num) == 1){
                    max_num = Math.max(max_num, num);
                }
            }
        }
        return max_num;
    }

    public static void main(String[] args){
        int[] nums = {0, 0};
        int k = 2;
        System.out.println("Largest almost missing integer : " + largestInteger(nums, k));
    }

}
import java.util.HashMap;

class Solution{
    public boolean isGood(int[] nums){
        HashMap<Integer, Integer> itemMap = new HashMap<>();

        int max = nums[0];
        for(Integer i : nums){
            if(i > max) max = i;
            if(itemMap.containsKey(i)){
                itemMap.put(i, itemMap.get(i) + 1);
            }else{
                itemMap.put(i, 1);
            }
        }

        if(nums.length != max + 1) return false;
        if(itemMap.get(max) != 2) return false;
        for(int i = 1; i < max; i++){
            if(itemMap.get(i) == null || itemMap.get(i) > 1) return false;
        }
        
        return true;   
    }
}
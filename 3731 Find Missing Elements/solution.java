import java.util.*;


class Solution{

    public static List<Integer> findMissingElements(int[] nums){
        List<Integer> out = new ArrayList<>();
        HashMap<Integer, Integer> elem_map = new HashMap<>();
        int curr_min = nums[0], curr_max = nums[0];
        for(int i : nums){
            if(i < curr_min) curr_min = i;
            if(i > curr_max) curr_max = i;
            elem_map.put(i, 1);
        }
        
        for(int i = curr_min; i <= curr_max; i++){
            if(!elem_map.containsKey(i)) out.add(i);
        }
        return out;
    }

    public static void main(String[] args){
        int[] nums = {7, 8, 6, 9};
        List<Integer> missing_elements = findMissingElements(nums);
        System.out.println("Missing elements :");
        for(int i : missing_elements) System.out.print(i + " ");
        System.out.println();
    }

}


class solution {

    public static int removeElement(int[] nums, int val){
        int count = nums.length;
        int swap_ptr = 0, comp_ptr = 0;
        while(comp_ptr < nums.length){
            if(nums[comp_ptr] != val){
                if(comp_ptr != swap_ptr){
                    int temp = nums[comp_ptr];
                    nums[comp_ptr] = nums[swap_ptr];
                    nums[swap_ptr] = temp;
                }
                swap_ptr++;
            }else count--;
            comp_ptr++;
        }
        return count;
    }

    public static void main(String[] args){
        int[] nums = {1, 2, 2, 3, 4, 2, 5, 6, 12, 2, 1};
        int k = removeElement(nums, 2);
        System.err.println("Remaining Elements : " + k);
        for(int i : nums){
            System.out.print(i + " ");
        }
        System.out.println();
    }

}

#include <vector>
#include <math.h>
#include <iostream>


class Solution{

    public:
    std::vector<int> pivotArray(std::vector<int> nums, int pivot){
        std::vector<int> out(nums.size(), -1);

        int left = 0, right = nums.size() - 1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                out[left] = nums[i];
                left++;
            }
            else if(nums[i] > pivot){
                out[right] = nums[i];
                right--;
            }
        }
        while(left <= right){
            out[left] = pivot;
            left++;
        }
        if(right != n - 1){
            for(int i = 1; i <= ceil((n - right) / 2); i++){
                if(i + right == n - i) continue;
                int temp = out[i + right];
                out[i + right] = out[n - i];
                out[n - i] = temp;
            }
        }
        return out;
    }
};


int main(){

    std::vector<int> temp = {2};

    for(int i : Solution().pivotArray(temp, 2)){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
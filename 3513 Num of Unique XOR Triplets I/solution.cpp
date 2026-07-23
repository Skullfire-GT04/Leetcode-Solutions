#include <iostream>
#include <vector>
#include <math.h>


class Solution{

    private:

    int msb(int num){
        int out = 0;
        while(pow(2, (float)out) <= num){
            out++;
        }
        return out - 1;
    }
    public:

    int uniqueXorTriplets(std::vector<int>& nums){

        int max_num = 0;
        for(int num : nums){
            if(num > max_num) max_num = num;
        }

        if(max_num >= 3){            
            return pow(2, (float) msb(max_num) + 1);
        }else{
            if(max_num == 2) return 2;
            else return 1;
        }
    }   
};


int main(){

    std::vector<int> nums = {1};
    std::cout << "Number of unique XOR triplets : " << Solution().uniqueXorTriplets(nums) << std::endl;

    return 0;
}
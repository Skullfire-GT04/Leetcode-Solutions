#include <iostream>
#include <vector>


class Solution{
    public:
    int getCommon(std::vector<int>& nums1, std::vector<int>& nums2){
        int l = 0, r = 0;
        int n = nums1.size(), m = nums2.size();
        while(l < n && r < m){
            if(nums1[l] == nums2[r]) return nums1[l];
            else{
                if(nums1[l] < nums2[r]) l++;
                else r++;
            }
        }
        return -1;
    }
};


int main(){

    std::vector<int> temp1 = {1, 2, 3, 4};
    std::vector<int> temp2 = {2, 4};

    std::cout << Solution().getCommon(temp1, temp2) << std::endl;

    return 0;
}
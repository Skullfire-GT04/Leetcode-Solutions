#include <iostream>
#include <vector>
#include <algorithm>


class Solution{

    public:
    int minimumCost(std::vector<int>& cost){
        std::sort(cost.begin(), cost.end());
        int len = cost.size();
        int total_cost = 0;
        int count = 0;
        for(int i = len - 1; i >= 0; i--){
            if(count != 2) {
                total_cost += cost[i];
                count++;
            }else count = 0;
        }
        return total_cost;
    }
};



int main(){

    std::vector<int> temp = {6, 5, 7, 9, 2, 2};

    std::cout << Solution().minimumCost(temp) << std::endl;

    return 0;
}
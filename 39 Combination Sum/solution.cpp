#include <vector>
#include <iostream>


class Solution{

    void recursiveAdd(std::vector<int>& curr_combination, int current_sum, int target, int start_index, std::vector<std::vector<int>>& out, std::vector<int>& items){
        if(current_sum == target){
            out.push_back(std::vector<int>{});
            for(int num : curr_combination){
                out[out.size() - 1].push_back(num);
            }
            return;
        }

        for(int i = start_index; i < items.size(); i++){
            if(items[i] + current_sum <= target){
                curr_combination.push_back(items[i]);
                recursiveAdd(curr_combination, current_sum + items[i], target, i, out, items);
                curr_combination.pop_back();
            }
        }
    }

    public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target){
        std::vector<std::vector<int>> out;

        std::vector<int> combination;
        recursiveAdd(combination, 0, target, 0, out, candidates);

        return out;
    }
};




int main(){

    std::vector<int> nums = {2, 3, 5};
    auto output = Solution().combinationSum(nums, 8);

    std::cout << "Total number of combinations : " << output.size() << std::endl;
    for(auto combination : output){
        std::cout << "{ ";
        for(int i = 0; i < combination.size(); i++){
            std::cout << combination[i];
            if(i != combination.size() - 1) std::cout << ", ";
        }
        std::cout << " }" << std::endl;
    }

    return 0;
}
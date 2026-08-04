#include <vector>
#include <iostream>


class Solution {
    public:
    std::vector<int> countTasks(std::vector<int>& tasks, std::vector<int>& shifts) {
        std::vector<int> out;
        int curr_task = 0;
        std::vector<int> tasks_copy;
        bool looped = false;
        for(int i : tasks) tasks_copy.push_back(i);

        for(int time_rewarded : shifts){
            if(looped){
                for(int i = 0; i < tasks.size(); i++)
                    tasks_copy[i] = tasks[i];
                looped = false;
                }
            while(curr_task < tasks.size()){
                if(time_rewarded - tasks_copy[curr_task] >= 0){
                    time_rewarded -= tasks_copy[curr_task];
                    curr_task++;
                }else{
                    tasks_copy[curr_task] -= time_rewarded;
                    break;
                }
            }

            if(curr_task >= tasks.size()) {
                out.push_back(0);
                curr_task = 0;
                looped = true;
            }
            else out.push_back(tasks.size() - curr_task);
        }
        return out;
    }
};


int main(){
    std::vector<int> tasks = {2,6,2,2,7};
    std::vector<int> shifts = {1,5,6,5,6};

    std::cout << "Tasks left for each shift:" << std::endl;
    for(auto count : Solution().countTasks(tasks, shifts)){
        std::cout << count <<  ", ";
    }
    std::cout << std::endl;

    return 0;
}
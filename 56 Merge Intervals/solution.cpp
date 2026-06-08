#include <iostream>
#include <vector>


class Solution{

    private:

    void merge(std::vector<std::vector<int>>& arr, std::vector<std::vector<int>> left, std::vector<std::vector<int>> right){
        int l = 0, r = 0, i = 0;
        int n = left.size(), m = right.size();
        while(l < n && r < m){
            if(left[l][0] < right[r][0]){
                arr[i++] = left[l++];
            }else arr[i++] = right[r++];
        }
        while(l < n) arr[i++] = left[l++];
        while(r < m) arr[i++] = right[r++];
    }

    void sortIntervals(std::vector<std::vector<int>>& intervals){
        if(intervals.size() <= 1) return;
        int size = intervals.size();
        std::vector<std::vector<int>> left, right;

        for(int i = 0; i < size; i++){
            if(i < size / 2) left.push_back(intervals[i]);
            else right.push_back(intervals[i]);
        }

        sortIntervals(left);
        sortIntervals(right);
        merge(intervals, left, right);
    }

    void getCombinedRange(std::vector<std::vector<int>>& intervals, int& index, int& last_lower, int& last_upper){
        if(intervals[index][0] >= last_lower && intervals[index][0] <= last_upper){
            if(intervals[index][1] > last_upper) last_upper = intervals[index][1];
            index++;
            if(index >= intervals.size()) return;
            getCombinedRange(intervals, index, last_lower, last_upper);
        }else return;
    }

    public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals){
        std::vector<std::vector<int>> out;

        // sorting the intervals
        sortIntervals(intervals);

        for(auto vec : intervals) std::cout << vec[0] << " " << vec[1] << std::endl;

        int index = 0, n = intervals.size();
        while(index < n){
            int lower = intervals[index][0];
            int upper = intervals[index][1];
            getCombinedRange(intervals, index, lower, upper);
            out.push_back(std::vector<int>{lower, upper});
        }
        return out;
    }
};


int main(){

    std::vector<std::vector<int>> temp = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    temp = Solution().merge(temp);
    for(auto vec : temp){
        std::cout << "Start : " << vec[0] << " " << "End : " << vec[1] << std::endl;
    }

    return 0;
}
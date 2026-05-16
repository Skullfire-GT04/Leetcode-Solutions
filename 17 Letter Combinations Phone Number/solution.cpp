#include <iostream>
#include <vector>
#include <string>
#include <string.h>


class Solution{

    private:
    std::vector<std::string> digit_map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    std::vector<std::string> recursivePermute(std::string start, std::string remaining){
        if(remaining.empty()) return std::vector<std::string>{start};
        std::vector<std::string> out;

        std::string adder = digit_map[remaining[0] - '0' - 2];

        std::string remainder;
        for(int j = 1; j < remaining.size(); j++) remainder += remaining[j];

        for(char c : adder){
            std::string copy = start;
            copy += c;
            for(auto tmp : recursivePermute(copy, remainder)){
                out.push_back(tmp);
            }
        }
        return out;
    }

    public:
    std::vector<std::string> letterCombinations(std::string digits){
        std::vector<std::string> out;
        for(int i = 0; i < digit_map[digits[0] - '0' - 2].size(); i++){
            std::string start_string;
            start_string += digit_map[digits[0] - '0' - 2][i];
            std::string remaining;
            for(int j = 1; j < digits.size(); j++) remaining += digits[j];
            for(auto tmp : recursivePermute(start_string, remaining)){
                out.push_back(tmp);
            }
        }
        return out;
    }
};


int main(){
    for(auto str : Solution().letterCombinations("3")){
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
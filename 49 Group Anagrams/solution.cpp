#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>



class Solution{

    private:
    std::string count_and_sort_str(std::string str){
        std::string out;
        std::unordered_map<char, int> count_map;
        for(int i = 0; i < str.size(); i++){
            if(count_map.find(str[i]) == count_map.end()){
                count_map[str[i]] = 0;
            }
            count_map[str[i]]++;
        }
        std::string temp = "abcdefghijklmnopqrstuvwxyz";

        for(int i = 0; i < temp.size(); i++){
            if(count_map.find(temp[i]) == count_map.end()) continue;
            out += temp[i] + std::to_string(count_map[temp[i]]);
        }
        return out;
    }


    public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
        std::vector<std::vector<std::string>> out;

        std::unordered_map<std::string, std::string> sorted_map;
        std::unordered_map<std::string, std::vector<std::string>> group_map;
        std::unordered_map<std::string, int> count_map;
        for(auto s : strs){
            if(count_map.find(s) == count_map.end()){
                count_map[s] = 0;
            }
            count_map[s]++;
        }

        for(auto s : strs){
            sorted_map[s] = this->count_and_sort_str(s);
        }
        for(auto [k, v] : sorted_map){
            if(group_map.find(v) == group_map.end()){
                std::vector<std::string> temp;
                group_map[v] = temp;
            }
            group_map[v].push_back(k);
        }
        for(auto [k, v] : group_map){
            std::vector<std::string> temp;
            for(auto s : v){
                for(int i = 0; i < count_map[s]; i++){
                    temp.push_back(s);
                }
            }
            out.push_back(temp);
        }
        return out;
    }
};





int main(){

    std::vector<std::string> temp = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::string> temp2 = {"", ""};
    int count = 1;
    for(auto v : Solution().groupAnagrams(temp2)){
        std::cout << "Anagram Group: " << count++ << std::endl;
        for(int i = 0; i < v.size(); i++){
            std::cout << v[i] << (i + 1 < v.size() ? ", " : "");
        }
        std::cout << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


class Solution{

    public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string> words){
        int word_len = words[0].size();
        std::unordered_map<std::string, int> word_map;
        int total_len = 0;
        std::vector<int> out;
        
        for(std::string word : words){
            auto it = word_map.find(word);
            total_len += word.size();
            if(it == word_map.end()){
                word_map[word] = 1;
            }else{
                word_map[word]++;
            }
        }

        int i = 0;
        while(i < s.size()){
            if(word_map.find(s.substr(i, word_len)) != word_map.end() && i + total_len <= s.size()){
                std::unordered_map<std::string, int> copy_map;
                for(auto [key, value] : word_map){
                    copy_map[key] = 0;
                }
                std::string extracted_string = s.substr(i, total_len);
                std::string curr_word = "";
                for(int index = 0; index < total_len; index++){
                    curr_word += extracted_string[index];
                    if(curr_word.size() == word_len){
                        if(word_map.find(curr_word) != word_map.end()){
                            copy_map[curr_word]++;
                            curr_word = "";
                        }else break;
                    }
                }
                bool same = true;
                for(auto [key, v] : word_map){
                    if(word_map[key] != copy_map[key]){
                        same = false;
                        break;
                    }
                }
                if(same){
                    out.push_back(i);
                }
            }
            i++;
        }
        return out;
    }
};



int main(){

    std::vector<std::string> words = {"bar", "foo"};
    std::string s = "barfoothefoobarman";
    std::vector<int> indices = Solution().findSubstring(s, words);
    std::cout << "Permutation starting indices : ";
    for(int i : indices){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

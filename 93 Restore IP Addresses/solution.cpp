#include <iostream>
#include <math.h>
#include <string>
#include <vector>



class Solution {
    private:
    void recursiveAdd(std::vector<std::string>& out, std::string s, std::string current, int index, int count){
        if(index >= s.size()){
            if(count == 4) out.push_back(current);
            return;
        }
        current += ".";
        int i = index;
        
        std::string temp;
        if(s[index] != '0'){
            while(i < s.size() && i < index + 3){
                temp += s[i];
                if(strToInt(temp) > 255) break;
                recursiveAdd(out, s, current + temp, i + 1, count + 1);
                i++;
            }
        }else{
            recursiveAdd(out, s, current + s[index], index + 1, count + 1);
        }
    }

    int strToInt(std::string s){
        int n = s.size();
        int out = 0;
        for(int i = n - 1; i >= 0; i--){
            out += pow(10, n - 1 - i) * (s[i] - '0');
        }
        return out;
    }

    public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> out;
        if(s.size() > 12) return out;
        if(s.size() < 4) return out;
        std::string temp;
        if(s[0] == '0'){
            temp += s[0];
            recursiveAdd(out, s, temp, 1, 1);
        }else{
            for(int i = 0; i < 3; i++){
                temp += s[i];
                if(strToInt(temp) > 255) break;
                recursiveAdd(out, s, temp, i + 1, 1);
            }
        }
        return out;
    }
}; 


int main(){
    std::vector<std::string> temp = Solution().restoreIpAddresses("25525511135");
    std::cout << "[ ";
    for(int i = 0; i < temp.size(); i++){
        std::cout << temp[i] << ((i == temp.size() - 1) ? "" : ", ");
    }
    std::cout << " ]" << std::endl;
}
#include <iostream>
#include <string>
#include <math.h>
#include <limits>
#include <ctype.h>


class Solution{
    public:
    int myAtoi(std::string s){
        double long temp = 0;
        bool negative = false;
        bool seen_sign = false;
        int start_index = -1;
        for(int i = 0; i < s.length(); i++){
            std::cout << i << " ";
            if(s[i] == '-'){
                std::cout << "negative" << std::endl;
                if(seen_sign) return 0;
                negative = true;
                seen_sign = true;
            }
            else if(s[i] == '+'){
                if(seen_sign) return 0;
                seen_sign = true;
            }
            else if(s[i] == ' ' && seen_sign){
                std::cout << "run" << std::endl;
                 return 0;
                }
            else if('0' <= s[i] && s[i] <= '9') {
                start_index = i;  
                break;
            }
            else if('a' <= s[i] && s[i] <= 'z' ||('A' <= s[i] && s[i] <= 'Z')) break;
            else if(s[i] == '.') break;
        }
        if(start_index < 0) return 0;

        for(int i = start_index; i < s.length(); i++){
            if(!isdigit(s[i])) break;
            if(temp > (std::numeric_limits<int>::max() - (s[i] - '0')) / 10){
                return negative ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
            }
            temp = temp * 10 + (s[i] - '0');
        }
        if(negative){
            temp = -temp;
        }
        return temp;
    }
};



int main(){

    std::cout << Solution().myAtoi(" - 413") << std::endl;
    
    return 0;
}
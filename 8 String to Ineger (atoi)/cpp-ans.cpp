#include <iostream>
#include <string>
#include <math.h>
#include <limits>


class Solution{
    public:
    int myAtoi(std::string s){
        double long temp = 0;
        int out {0};
        int true_len = 0;
        bool negative = false;
        bool seen_numbers = false;
        bool seen_sign = false;
        int start_index = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '-'){
                if(seen_sign) return 0;
                if(seen_numbers) break;
                negative = true;
                seen_sign = true;
            }
            else if(s[i] == '+'){
                if(seen_sign) return 0;
                seen_sign = true;
            } 
            else if(s[i] == ' '){
                if(seen_numbers) break;
            }
            else if('0' <= s[i] && s[i] <= '9') {
                true_len++;
                if(!seen_numbers) start_index = i;
                seen_numbers = true;
            }
            else if('a' <= s[i] && s[i] <= 'z' ||('A' <= s[i] && s[i] <= 'Z')) break;
            else if(s[i] == '.') break;
        }
        for(int i = start_index; i < start_index + true_len; i++){
            temp += std::pow(10, true_len + (start_index - (i + 1))) * (s[i] - '0');
        }
        if(negative) temp = -temp;

        if(temp > std::numeric_limits<int>::max()) out = std::numeric_limits<int>::max();
        else if(temp < std::numeric_limits<int>::min()) out = std::numeric_limits<int>::min();
        else out = temp;

        return out;
    }
};



int main(){

    std::cout << Solution().myAtoi("-+12456256gsg") << std::endl;
    std::cout << sizeof(long double) << std::endl;
    return 0;
}
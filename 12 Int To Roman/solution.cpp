#include <iostream>
#include <vector>
#include <string>
#include <math.h>

class Solution{

    private:
    std::vector<int> values = {1, 5, 10, 50, 100, 500, 1000};
    std::vector<std::string> str_rpr = {"I", "V", "X", "L", "C", "D", "M"};
    std::vector<std::vector<int>> allowed_dec = {{-1}, {0}, {0}, {2}, {2}, {4}, {4}};
    std::vector<std::vector<int>> dec_rpr = {{0}, {4}, {9}, {40}, {90}, {400}, {900}};

    public:
    std::string intToRoman(int num){
        std::string out = "";
        int i = values.size() - 1;
        while(num != 0 && i >= 0){
            float temp = float(num) / values[i];
            if(temp < 1 && temp > 0){
                for(int j = 0; j < allowed_dec[i].size(); j++){
                    if(allowed_dec[i][j] == -1) break;
                    int dec_index = allowed_dec[i][j];
                    int dec_val = dec_rpr[i][j];
                    if(dec_val <= num){
                        out += str_rpr[dec_index];
                        out += str_rpr[i];
                        num -= dec_val;
                        break;
                    }
                }
            }else{
                for(int j = 0; j < std::floor(temp); j++) out += str_rpr[i];
                num -= values[i] * std::floor(temp);
            }
            if(std::floor(temp) == 0) i--;
        }
        return out;
    }
};


int main(){
    std::cout << Solution().intToRoman(1994) << std::endl;
    return 0;
}
#include <iostream>
#include <stdbool.h>
#include <limits>

class Solution{
    public:
    int divide(int divident, int divisor){
        bool is_negative = false;
        if(divident < 0 && divisor > 0) is_negative = true;
        if(divident > 0 && divisor < 0) is_negative = true;

        int count = 0;
        divident = divident < 0 ? -divident : divident;
        int original_divisor = divisor > 0 ? divisor : -divisor;
        divisor = original_divisor;

        if(divident < divisor) return 0;
        if(divident == divisor) return is_negative ? -1 : 1;

        while(divident - divisor > 1) {
            divisor <<= 1;
            count++;
        }
        int dec_count = 0;
        while(divident - divisor < 0) {
            divisor -= original_divisor;
            dec_count++;
        }
        double out  = is_negative ? - (count * 2 - dec_count) : count * 2 - dec_count;

        if(out > std::numeric_limits<int>::max()) out = std::numeric_limits<int>::max();
        if(out < std::numeric_limits<int>::min()) out = std::numeric_limits<int>::min();

        return int(out);
    }
};


int main(){

    std::cout << Solution().divide(-35656776, 1) << std::endl;

    return 0;
}
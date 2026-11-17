#include <iostream>
#include <string>


class Solution{

    private:
    bool isSmallerLexicographically(std::string s, int l1, int r1, int l2, int r2){
        int len = r2 - l2 < r1 - l1 ? r2 - l2 : r1 - l1;
        int i = 0;
        while(i < len && s[i + l1] == s[i + l2]) i++;
        return i < len ? s[i + l1] < s[i + l2] : false;
    }

    public:
    std::string shortestBeautifulSubstring(std::string s, int k){
        int l = 0, r = 0;
        int one_count = 0;
        int curr_l = -1, curr_r = -1;
        while(r < s.size() || l < s.size()){
            if(r < s.size() && s[r] == '1') one_count++;
            if(one_count > k){
                while(l <= r && one_count > k) if(s[l++] == '1') one_count--;
            }
            else if(one_count == k){
                if(curr_l >= 0){
                    bool is_above_limit = false;
                    if(r >= s.size()){
                        is_above_limit = true;
                        r--;
                    }
                    if((r - l == curr_r - curr_l && isSmallerLexicographically(s, l, r, curr_l, curr_r)) || r - l < curr_r - curr_l){
                        curr_l = l;
                        curr_r = r;
                    }
                    if(is_above_limit) r++;
                }else{
                    curr_l = l;
                    curr_r = r;
                }
            }
            if(r < s.size()) r++; 
            else{
                if(one_count < k) break;
                else {
                    if(s[l++] == '1') one_count--;
                }
            }
        }
        return curr_l >= 0 ? s.substr(curr_l, curr_r + 1) : "";
    }

};




int main(){

    std::string s = "100011001";
    int k = 3;    
    std::cout << "Shortest beautiful substring of (" << s << ") is : " << Solution().shortestBeautifulSubstring(s, k) << std::endl;

    return 0;
}
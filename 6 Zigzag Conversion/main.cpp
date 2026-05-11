#include <iostream>
#include <string>


class Solution{

    private:
    int get_position(int index, int numRows){
        return (index == 0) ? 0 : index - get_top_pos(index, numRows);
    }

    int get_top_pos(int index, int numRows){
        if(index == 0) return 0;
        int d = 2 * (numRows - 1);
        int an = 0;
        while(an <= index) an += d;
        return an - d;
    }

    int get_next_index(int pos, int numRows, int index){
        int d = 2 * (numRows - 1);
        if(pos == numRows - 1 || pos == 0){
            return index + d;
        }else{
            int top_index = get_top_pos(index, numRows);
            int next_top_index = top_index + d;
            if(pos < numRows - 1){
                return next_top_index - pos;
            }else{
                return next_top_index + (next_top_index - index);
            }
        }
    }

    public:
    std::string convert(std::string s, int numRows){        
        if(numRows >= s.length() || numRows == 1) return s;
        std::string out;
        for(int i = 0; i <= numRows - 1; i++){
            int index = i;
            while(index < s.length()){
                out += s[index];
                index = get_next_index(get_position(index, numRows), numRows, index);    
            }
        }
        return out;
    }
};



int main(){

    std::cout << Solution().convert("PAYPALISHIRING", 3) << std::endl;

}
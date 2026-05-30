#include <iostream>
#include <vector>
#include <string>


class Solution{

    public:
    std::string simplifyPath(std::string path){
        std::vector<std::string> directories;
        int len = path.size();
        int index = 1;
        std::string curr_dir = "";
        while(index < len){
            if(path[index] == '/'){
                while(path[index] == '/' && index < len) index++;
                if(curr_dir == ".." && directories.size() > 0) directories.pop_back();
                else if(curr_dir != "." && curr_dir != ".." && curr_dir.size() > 0) directories.push_back(curr_dir);
                curr_dir = "";
                if(index >= len) break;
            }
            curr_dir += path[index];
            index++;
        }
        if(curr_dir != ".." && curr_dir != "." && curr_dir.size() > 0) directories.push_back(curr_dir);
        else{
            if(curr_dir == ".." && directories.size() > 0) directories.pop_back();
        }
        std::string out = "/";
        for(int i = 0; i < directories.size(); i++){
            out += directories[i];
            out += i != directories.size() - 1 ? "/" : "";
        }
        return out;
    }
};



int main(){

    std::cout << Solution().simplifyPath("///TJbrd/owxdG//") << std::endl;

    return 0;
}
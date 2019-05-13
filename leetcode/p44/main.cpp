#include <iostream>
#include <regex>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        string pp="";
        for(int i=0;i<p.size();i++){
            if( p[i]== '*' ){
                pp+="[a-z]+";
            }else if(p[i]== '?'){
                pp+="[a-z]";
            }else{
                pp+=p[i];
            }
        }
        return regex_match(s, regex(pp));
        return false;
    }
};

int main()
{

    Solution Solution1;
    Solution1.isMatch("a","*");
    return 0;
}

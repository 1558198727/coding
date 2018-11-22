#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> digitMap = {"","","abc","def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        for(auto i : digits){
            for(auto j : digitMap[i-'0']){
                string tempStr;
                stringstream stream;
                stream << j;
                tempStr = stream.str();
                ret.push_back( tempStr );
            }
            //ret
        }
        return ret;
    }
};
int main()
{
    Solution Solution1;

    Solution1.letterCombinations("23");
    return 0;
}

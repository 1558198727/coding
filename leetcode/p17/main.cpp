#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> digitMap = {"","","abc","def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        ret.push_back("");
        for(auto i : digits){
            cout<<i<<endl;

            vector<string> temp;
            for(auto j : digitMap[i-'0']){
                for(int ii = 0 ;ii<ret.size();ii++){
                    temp.push_back(ret[ii] + j);
                    //cout<<"1111 "<<temp.size()<<endl;
                }
            }
            ret = temp;
            temp.clear();
            //for (auto d:ret){
            //    cout<<d<<endl;
            //}
            //ret
        }
        return ret;
    }
};
int main()
{

    Solution Solution1;

    for (auto i:Solution1.letterCombinations("23")){
        //cout<<i<<endl;
    }
    return 0;
}

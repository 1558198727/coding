#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> vestr;
    vector<int> ret;
    bool is_suan(char a){
        if(a == '+' || a == '-' || a == '*'){
            return true;
        }
        return false;
    }
    int str_int(string s){
        stringstream ss;
        ss<<s;
        int ret;
        ss>>ret;
        return ret;
    }
    string int_str(int a){
        stringstream ss;
        ss<<a;
        return ss.str();
    }
    vector<string> split(string s){
        vector<string> ret;
        int i=0;
        int j=0;
        while(j < s.size()){
            if( is_suan( s[j]) ){
                ret.push_back(s.substr(i,j-i));
                ret.push_back(s.substr(j,1));
                i = j+1;
                j = i;
            }else{
                j ++;
            }
        }
        ret.push_back(s.substr(i,j-i+1));
        return ret;
    }
    vector<int> diffWaysToCompute(string input) {
        vestr = split(input);
        findw(vestr);
        return ret;
    }
    int findw(vector<string> ve){
        if(ve.size()==0){
            return str_int(ve[0]);
        }
        string a1 = ve.front();
        ve.erase(ve.begin());
        string suan = ve.front();
        ve.erase(ve.begin());
        int a11 = str_int(a1);
        if(suan == "+"){
            return a11 + findw(ve);
        }else if(suan == "-"){
            return a11 - findw(ve);
        }if(suan == "*"){
            return a11 * findw(ve);
        }
    }
};

int main()
{
    Solution Solution1;
    Solution1.diffWaysToCompute("332*33-43*35");
    return 0;
}

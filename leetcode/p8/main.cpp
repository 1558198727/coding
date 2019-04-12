#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <limits.h>
using namespace std;

class Solution {
public:
    bool is_dig(char a){
        if(a=='-'|| a=='.'|| a=='+' || (a>='0' && a<='9')){
            return true;
        }
        return false;
    }
    int myAtoi(string str) {
        int pos =0;
        while(str[pos]==' '){
            pos++;
        }
        str = str.substr(pos);
        if(str.size()==0){
            return 0;
        }
        if(!is_dig(str[0])){
            return 0;
        }
        if(str[0]=='.'){
            return 0;
        }
        string newstr = "";
        for(auto i :str){
            if(is_dig(i)){
                newstr += i;
            }else{
                break;
            }
        }

        for(int i=0;i<newstr.size();i++){
            if(newstr[i]=='.'){
                newstr = newstr.substr(0,i);
            }
        }
        stringstream ss;
        ss<<newstr;
        int ret=1 ;
        ss>>ret;
        return ret;
    }
};
int main()
{
    Solution Solution1;
    cout<<Solution1.myAtoi("  -0012a42")<<endl;
    return 0;
}

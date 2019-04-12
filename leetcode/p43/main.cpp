#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ret = "";
        if(num1.size()==0 || num2.size()==0){
            return ret;
        }
        if(num1=="0" ||num2=="0"){
            return "0";
        }
        ret = string(num1.size() + num2.size(),'0');
        for(int i= num1.size()-1;i>=0;i--){
            for(int j = num2.size()-1;j>=0;j--){
                int temp = (num1[i]-'0')*(num2[j]-'0');
                temp += ret[i+j+1] - '0';
                ret[i+j+1] = temp%10 + '0';
                ret[i+j] += temp/10;
            }
        }
        int i=0;
        while(ret[i]=='0'){
            i++;
        }
        return ret.substr(i);
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.multiply("111","45")<<endl;
    return 0;
}

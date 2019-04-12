#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string arr[numRows];
        if(numRows==1){
            return s;
        }
        int index=0;
        int add = 1;
        for(int i=0;i< s.size();i++){
            arr[index] += s[i];
            index += add;
            if(add==1 && index == numRows-1){
                add = -1;
            }else if(add==-1 && index == 0){
                add = 1;
            }

        }
        string ret = "";
        for(int i=0;i<numRows;i++){
            ret += arr[i];
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.convert("AB", 1)<<endl;
    return 0;
}

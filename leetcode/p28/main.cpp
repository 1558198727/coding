#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

/*
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
*/
//KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> fail(haystack.size()+1,-1);
        if(haystack.size()<needle.size()){
            return -1;
        }
        int i=0,j =0;
        for(j =1;j<needle.size();j++){
            for(i = fail[j-1];i>=0 && needle[i+1]!=needle[j];i = fail[i]);
            fail[j] = (needle[i+1]==needle[j]?i+1:-1);
        }

        for(i=j=0;i<haystack.size() && j<needle.size();i++){
            //debug(1);
            if(haystack[i]==needle[j])j++;
            else if(j)j = fail[j-1]+1,i--;
        }
        return j==needle.size()?i - needle.size():-1;
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.strStr("hello","ll")<<endl;
    return 0;
}

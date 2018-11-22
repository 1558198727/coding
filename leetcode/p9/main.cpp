#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }else if(x==0){
            return true;
        }else{
            string str;
            while(x>0){
                char cur ='0'+ (x % 10);
                str += cur;
                x /=10;
            }
            int len = str.size();
            for(int i=0;i<len/2;i++){
                if(str[i]!=str[len-1-i]){
                    return false;
                }
            }
            return true;
        }

    }
};
int main()
{
    Solution Solution1;
    cout<<Solution1.isPalindrome(121);
    return 0;
}

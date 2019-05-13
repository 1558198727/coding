#include <iostream>
#include <string>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    bool isPalindrome(string S) {
        int pos = 0;
        for(int i=0;i<S.size();i++){
            if(S[i]>='A' && S[i]<='Z'){
                S[pos++] = S[i];
            }else if(S[i]>='a' && S[i]<='z'){
                S[pos++] = S[i] - 'a' + 'A';
            }else if(S[i]>='0' && S[i]<='9'){
                S[pos++] = S[i];
            }
        }
        S = S.substr(0,pos);
        //debug(S);
        for(int i = 0;i < pos/2;i ++){
            if(S[i] != S[pos-1-i]){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.isPalindrome("")<<endl;

    return 0;
}

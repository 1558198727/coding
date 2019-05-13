#include <iostream>
#include <string>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;
class Solution {
public:
    string removeOuterParentheses(string S) {
        int cnt = 0;
        int pos = 0;
        for(int i=0;i<S.size();i++){
            //debug(i);
            //debug(cnt);
            if(S[i]=='('){
                if(cnt==0){
                    ;
                }else{
                    S[pos++] = S[i];
                }
                cnt++;
            }else if(S[i]==')'){
                if(cnt==1){
                    ;
                }else{
                    S[pos++] = S[i];
                }
                cnt--;
            }
        }
        return S.substr(0,pos);
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.removeOuterParentheses("(()())(())(()(()))")<<endl;
    return 0;
}

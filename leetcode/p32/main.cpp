#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        s = "#"+s;
        vector<int>ans(s.size());
        int ret = 0;
        ans[0] = 0;
        for(int i=1;i<(int)s.size();i++){
            if(s[i]=='('){
                st.push(i);
                ans[i]=0;
            }else{
                if(st.empty()){
                    ans[i]=0;
                }else{
                    int top = st.top();
                    st.pop();
                    ans[i] = i-top+1+ans[top-1];
                    ret = max(ret,ans[i]);
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.longestValidParentheses("()()")<<endl;
    return 0;
}

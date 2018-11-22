#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack1;
        int len = s.size();
        for(int i=0;i<len;i++){
            if(s[i]=='(' || s[i]== '{' || s[i]== '['){
                stack1.push(s[i]);
            }else if(!stack1.empty() && s[i]==')' ){
                if(stack1.top() == '('){
                    stack1.pop();
                }else{
                    return false;
                }
            }else if(!stack1.empty() && s[i]== '}'){
                if(stack1.top() == '{'){
                    stack1.pop();
                }else{
                    return false;
                }
            }else if(!stack1.empty() && s[i]== ']'){
                if(stack1.top() == '['){
                    stack1.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        if(stack1.empty()){
            return true;
        }else{
            return false;
        }
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.isValid("]");
    return 0;
}

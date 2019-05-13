#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
class Solution {
public:
    int str_int(string s){
        stringstream ss;
        ss<<s;
        int ret;
        ss>>ret;
        return ret;
    }
    bool is_suan(string s){
        if(s=="+" || s=="-"|| s=="*"|| s=="/"){
            return true;
        }else{
            return false;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            //debug(tokens[i])
            if(is_suan( tokens[i] ) ){
                int you = st.top();
                st.pop();
                int zuo = st.top();
                st.pop();
                //debug(zuo);
                //debug(you);
                if(tokens[i]=="+"){
                    st.push(zuo+you);
                }else if(tokens[i]=="-"){
                    st.push(zuo-you);
                }else if(tokens[i]=="*"){
                    st.push(zuo*you);
                }else if(tokens[i]=="/"){
                    st.push(zuo/you);
                }
            }else{
                st.push( str_int(tokens[i]) );
                //debug( str_int(tokens[i]) );
            }
        }
        return st.top();
    }
};

int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution Solution1;
    cout << Solution1.evalRPN(tokens) << endl;
    return 0;
}

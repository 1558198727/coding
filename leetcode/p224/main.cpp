#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    int str_int(string s){
        stringstream ss;
        int a;
        ss<<s;
        ss>>a;
        return a;
    }

    bool is_dig(string a){
        if(a.size()==1 && a>="0" && a <= "9"){
            return true;
        }else{
            return false;
        }
    }
    bool is_c(string a){
        if(a.size()==1 && (a=="+" || a == "-"|| a == "*"|| a == "/"|| a == "("|| a == ")")){
            return true;
        }else{
            return false;
        }
    }

    vector<string> str_ve(string s){
        vector<string> ve;
        int i = 0;
        while(i<s.size()){
            if(!is_dig(s.substr(i,1))){
                ve.push_back(s.substr(i,1));
                i++;
            }else{
                int j = i;
                while(is_dig(s.substr(j,1))){
                    j++;
                }
                ve.push_back(s.substr(i,j-i));
                i=j;
            }
        }
        return ve;

    }
    int get_pri(string s){
        if(s.size()!=1){
            return -1;
        }
        if(s=="("){
            return 1;
        }else if(s=="+" || s=="-"){
            return 2;
        }else if(s=="*" || s=="/"){
            return 3;
        }else if(s==")"){
            return 4;
        }else{
            return -1;
        }

    }
    vector<string> zhong_to_hou(vector<string> ve){
        vector<string> hou;
        stack<string> st;
        for(int i=0;i<ve.size();i++){
            if(!is_c(ve[i])){
                hou.push_back(ve[i]);
            }else{
                if(st.empty() || ve[i]=="("){
                    st.push(ve[i]);
                }else if(ve[i]==")"){
                    while(st.top()!="("){
                        hou.push_back(st.top());
                        st.pop();
                    }
                    st.pop();
                }else{
                    int pri = get_pri(ve[i]);
                    if(get_pri(st.top()) < pri){
                        st.push(ve[i]);
                    }else{
                        while(!st.empty() && get_pri(st.top()) >= pri){
                            hou.push_back(st.top());
                            st.pop();
                        }
                        st.push(ve[i]);
                    }

                }

            }
        }
        while(!st.empty()){
            hou.push_back(st.top());
            st.pop();
        }

        return hou;
    }
    int cal_post(vector<string> ve){
        stack<int> ret;
        for(int i=0;i<ve.size();i++){
            if(!is_c(ve[i])){
                ret.push(str_int(ve[i]));
            }else{
                int b = ret.top();
                ret.pop();
                int a = ret.top();
                ret.pop();
                if(ve[i]=="+"){
                    ret.push(a+b);
                }else if(ve[i]=="-"){
                    ret.push(a-b);
                }if(ve[i]=="*"){
                    ret.push(a*b);
                }if(ve[i]=="/"){
                    ret.push(a/b);
                }
            }
        }
        return ret.top();
    }

    void trim(string &s)
    {
        /*
        if( !s.empty() )
        {
            s.erase(0,s.find_first_not_of(" "));
            s.erase(s.find_last_not_of(" ") + 1);
        }
        */
        int index = 0;
        if( !s.empty())
        {
            while( (index = s.find(' ',index)) != string::npos)
            {
                s.erase(index,1);
            }
        }

    }
    int calculate(string s) {
        trim(s);
        vector<string> ve = str_ve(s);
        vector<string> post = zhong_to_hou(ve);
        return cal_post(post);
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.calculate("2-1+ 2") << endl;
    return 0;
}

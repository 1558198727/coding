#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>cnt(256);
        vector<bool>in_right_place(256);
        for(bool i : in_right_place){
            cout<<i<<endl;
        }
        for(char c:s){
            cnt[c]++;
        }
        string res="";
        /*返回的字符串初始化为空*/
        for(char c:s){
            cnt[c]--;
            if(in_right_place[c]){
                /*如果已经在正确位置，则跳过*/
                continue;
            }else{
                while(cnt[res.back()]>0&&c<res.back()){
                    /*说明存在一个新序列使得字典序更小*/
                    in_right_place[res.back()]=false;
                    res.pop_back();
                    /*撤销正确位置的标记并将其从结果字符串弹出*/
                }
                res+=c;
                in_right_place[c]=true;
                /*此时c在“当前的”正确位置*/
            }
        }
        return res;

    }
};

int main()
{
    Solution Solution1;

    cout<<Solution1.removeDuplicateLetters("bcabc")<<endl;
    //string a = "abcdef";
    //a.pop_back();

    //cout<<a.front()<<endl;
    return 0;
}

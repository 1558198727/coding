#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        string t = "$#";
        for(auto i : s){
            t += i;
            t += "#";
            //cout<<i<<endl;
        }

        //可以初始化为1，进一步提高算法的效率
        vector<int>p(t.size(),1);

        int pos = 0;
        int maxlen = 0;
        int id = 0;
        int mx = 0;
        for(int i=1;i<t.size();i++){
            //利用对称性，降低了复杂度
            p[i] = i<mx?min(p[2*id-i],mx-i):1;
            //从已知的位置开始向两边延伸
            while(t[i+p[i]] == t[i-p[i]]){
                p[i]++;
            }
            //更新mx 和 id
            if(i+p[i]>mx){
                mx = i+p[i];
                id = i;
            }
            //记录最终的答案
            if(p[i]>maxlen){
                maxlen = p[i];
                pos = i;
            }
        }
        //(pos - maxlen)/2 长度
        return s.substr( (pos - maxlen)/2,maxlen-1 );
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.longestPalindrome("123321")<<endl;
    return 0;
}

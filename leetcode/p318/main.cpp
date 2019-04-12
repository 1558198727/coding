#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bit(words.size());
        for(int i=0;i<words.size();i++){
            for(int  j=0 ; j< words[i].size();j++){
                bit[i] |= 1<<( words[i][j] - 'a' );
            }
        }
        int len = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(!(bit[i]&bit[j]) ){
                    len = max(len, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return len;
    }
};

int main()
{
    Solution Solution1;
    string a[6] = {"abcw","baz","foo","bar","xtfn","abcdef"};
    vector<string> aa(a,a+6);
    cout<<Solution1.maxProduct(aa)<<endl;
    return 0;
}

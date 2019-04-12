#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for(int i=0;i<s.size();i++){
            ret*=26;
            ret += s[i]-'A'+1;
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.titleToNumber("AB")<<endl;
    return 0;
}

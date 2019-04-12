#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for(int i=0;i<len/2;i++){
            swap(s[i],s[len-1-i]);
        }
    }
};

int main()
{
    Solution Solution1;
    vector<char> s ={'h','e','l','l','o'};
    Solution1.reverseString(s);
    for(auto i:s){
        cout<<i<<" ";
    }
    return 0;
}

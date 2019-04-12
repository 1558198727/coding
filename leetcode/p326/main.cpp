#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467%n == 0;
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.isPowerOfThree(27)<<endl;
    return 0;
}

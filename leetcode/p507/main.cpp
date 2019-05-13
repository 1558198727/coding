#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int>nums = {6,28,496,8128,33550336};
        for(auto i:nums){
            if(i==num){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

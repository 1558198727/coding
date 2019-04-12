#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 对每一位单独统计出现1的次数, 如果出现的次数不能整除3说明唯一存在的数在这一位上为1, 时间复杂度O(32N)
        int ret = 0;
        for(int i = 0; i < 32; ++i) {
            int bitnums = 0;
            int bit = 1 << i;
            for(int num : nums) {
                if((num&bit) != 0)
                    bitnums++;
            }
            if(bitnums % 3 != 0)
                ret |= bit;
        }
        return ret;
    }
};
int main()
{
    Solution Solution1;
    int a[4]={2,2,3,2};
    vector<int> ve(a,a+4);
    cout<<Solution1.singleNumber(ve);
    return 0;
}

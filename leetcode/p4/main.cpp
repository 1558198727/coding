#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector< int > merged;
        merge( nums1.begin(), nums1.end(),
                nums2.begin(), nums2.end(),
                back_inserter( merged ) );

        auto middle = merged.size() / 2;
        if( merged.size() % 2 == 0 )
        {
            auto a = merged[middle - 1];
            auto b = merged[middle];

            return (a + b) / 2.;
        }
        else
        {
            return merged[middle];
        }
    }
};

int main()
{
    Solution Solution1;
    int nums1[2] = {1, 2};
    int nums2[2] = {3,4};
    vector<int> nums11(nums1,nums1+2);
    vector<int> nums22(nums2,nums2+2);
    cout<<Solution1.findMedianSortedArrays(nums11,nums22)<<endl;
    return 0;
}

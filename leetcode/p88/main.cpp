#include <iostream>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=0;
        int j=0;
        while(i<m+n && j<n){
            //在1中找2开头的位置
            while(i<j+m && nums2[j]>=nums1[i]){
                i++;
            }
            //挪动元素
            for(int k=nums1.size()-1;k>i;k--){
                nums1[k] = nums1[k-1];
            }
            nums1[i]=nums2[j];
            j++;
        }
    }
    void disp(vector<int> nums1){
        for(auto i:nums1){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    vector<int> nums1 = {0};
    int m = 0;
    vector<int> nums2 = {1};
    int n = 1;
    Solution Solution1;
    Solution1.merge(nums1,m,nums2,n);
    for(auto i:nums1){
        cout<<i<<" ";
    }
    return 0;
}

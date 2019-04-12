#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0 ;
        if(height.size()==0){
            return ret;
        }
        int l =0,r = height.size()-1;
        int lmax =0;
        int rmax = 0;
        while(l<r){
            lmax = max(lmax,height[l]);
            rmax = max(rmax,height[r]);
            if(lmax <= rmax){
                ret += lmax - height[l];
                l++;
            }else{
                ret += rmax - height[r];
                r--;

            }
        }
        return ret;
    }
};
int main()
{
    Solution Solution1;

    int a[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height(a,a+12);
    cout<<Solution1.trap(height)<<endl;
    return 0;
}

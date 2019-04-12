#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int pos = 0;
        int mav = -1;
        int mapos =-1;
        int counter = 0;
        if(nums.size()==0 || nums.size()==1){
            return pos;
        }
        while(pos + nums[pos] <nums.size()-1){
            for(int i=pos+1;i<=pos+nums[pos];i++){
                //cout<<"aaaaa"<<endl;
                if(i+nums[i]>mav){
                    mav = i+nums[i];
                    mapos = i;
                }
            }
            pos = mapos;
            counter ++;
        }
        return counter+1;
    }
};
int main()
{
    Solution Solution1;

    int a[5] = {1,2,3};
    vector<int> height(a,a+3);
    cout<<Solution1.jump(height)<<endl;
    return 0;
}

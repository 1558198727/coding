#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s1;
        for(auto i : nums){
            s1.insert(i);
        }
        if(s1.size() != nums.size()){
            printf("true\n");
            return true;
        }else{
            printf("false\n");
            return false;
        }
    }
};
int main()
{
    Solution Solution1;
    int a[4]={1,2,3,1};
    vector<int> v(a,a+4);

    Solution1.containsDuplicate(v);
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

bool cmp(int a,int b){
    return a>b;
}
int main()
{
    //int a[5] = {1,2,2,1,3};
    //vector<int> nums(a,a+5);
    map<int ,int>mp;
    vector<int> nums = {1,5000,600};
    for(int i=0;i<nums.size();i++){
        mp[ nums[i] ] = 1;
    }
    for(int i=0;i<nums.size();i++){
        if( mp[ 5001 - nums[i] ] ){
            cout<<"yes"<<endl;
            return 0;
        }
    }

    cout<<"no"<<endl;

    //debug(ret)
    return 0;        //最终的结果是：608.100000
}

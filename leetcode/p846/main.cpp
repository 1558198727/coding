#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define deubg(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> mp;
        if(hand.size()==0 || hand.size()%W!=0){
            return false;
        }
        for(auto i:hand){
            ++mp[i%W];
        }
        map<int,int>::iterator it = mp.begin();
        int cnt = it->second;
        for(int i=0;i<W;i++){
            if(mp[i]!=cnt){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution Solution1;
    vector<int>hand = {1,2,3,6,2,3,4,7,8};
    cout<<Solution1.isNStraightHand(hand,3)<<endl;
    return 0;
}

#include <iostream>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string pow2[31] = {"1", "2", "4", "8", "16", "23", "46", "128", "256", "125", "0124", "0248", "0469", "1289", "13468", "23678", "35566", "011237", "122446", "224588", "0145678", "0122579", "0134449", "0368888", "11266777", "23334455", "01466788", "112234778", "234455668", "012356789", "0112344778"};
        map<string,int>mp;
        for(int i=0;i<31;i++){
            mp[pow2[i] ]=1;
        }
        stringstream ss;
        ss<<N;
        string s = ss.str();
        sort(s.begin(),s.end());
        if(mp[s]==1){
            return true;
        }
        return false;

    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.reorderedPowerOf2(46)<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int i = 0;
        for(;i < citations.size();i ++){
            if( citations[i] < i+1){
                return i;
            }
        }
        return i;
    }
};

int main()
{
    Solution Solution1;
    vector<int> citations = {3,0,6,1,5};
    cout << Solution1.hIndex(citations) << endl;
    return 0;
}

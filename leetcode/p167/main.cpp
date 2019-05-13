#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size()==0){
            return {};
        }
        vector<int> ret;
        int i=0;
        int j = numbers.size()-1;
        while(i<j){
            if(numbers[i] + numbers[j]>target){
                j--;
            }else if(numbers[i]+numbers[j]<target){
                i++;
            }else{
                ret.push_back(i+1);
                ret.push_back(j+1);
                break;
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> a = {1,2,3,4,5,6};
    Solution1.twoSum(a,6);
    return 0;
}

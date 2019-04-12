#include <iostream>
#include <vector>
using namespace std;

/*±©Á¦·¨
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                maxA = max(maxA,(j-i)*min(height[i],height[j]));
            }
        }
        return maxA;
    }
};
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0){
            return 0;
        }
        int maxA = 0;
        int i=0,j=height.size() - 1;
        while(i!=j){
            maxA = max(maxA,(j-i)*min(height[i],height[j]));
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxA;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        if(matrix[0].size() == 0){
            return false;
        }
        int s=0,e = matrix.size()-1;
        int mid = e;
        while( s<=e ){

            if( matrix[mid][0] > target ){
                e = mid-1;
            }else if( matrix[mid][0] < target){
                if(matrix [mid][ matrix[0].size()-1] >= target){
                    //debug(2222)
                    break;
                }else{
                    s = mid+1;
                }

            }else{
                return true;
            }

            mid = (s+e)>>1;
        }
        if(mid<0){
            return false;
        }
        s=0;
        e = matrix[0].size()-1;
        int mmid = e;
        while( s<=e ){
            if( matrix[mid][mmid]>target ){
                e = mmid-1;
            }else if(matrix[mid][mmid]<target){
                s = mmid+1;
            }else{
                return true;
            }
            mmid = (s+e)>>1;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>>matrix = {
        {1}
    };
    Solution Solution1;
    cout << Solution1.searchMatrix(matrix,1) << endl;
    return 0;
}

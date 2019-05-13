#include <iostream>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

//O(n^2)
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto i:matrix){
            for(auto j:i){
                if(j==target){
                    return true;
                }
            }
        }
        return false;
    }
};
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }else if(matrix[0].size()==0){
            return false;
        }
        return findw(matrix,matrix.size()-1,0,target);
    }
    bool findw(vector<vector<int>>& matrix, int x,int y,int target){
        if(x>=matrix.size() || x<0 || y>=matrix[0].size() || y<0){
            return false;
        }
        if( matrix[x][y]<target ){
            return findw(matrix,x,y+1,target);
        }else if(matrix[x][y]>target){
            return findw(matrix,x-1,y,target);
        }else{
            return true;
        }

    }
};

int main()
{
    vector<vector<int>>matrix = {
            {1,   4},
            {2,   5},
    };
    Solution Solution1;
    cout << Solution1.searchMatrix(matrix,4) << endl;
    return 0;
}

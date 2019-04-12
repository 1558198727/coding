#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int sum = 0;
        vector<int> a(n,-1);
        fang(sum,a,0);
        return sum;
    }
    bool can(vector<int> &arr,int row,int col ){
        for(int i=0;i<row;i++){
            if(arr[i]==col){
                return false;
            }
        }
        for(int i=0;i<row;i++){
            //cout<<"ssss"<<endl;
            if(abs(row - i) == abs (col-arr[i])){
                //cout<<"aaaa"<<endl;
                return false;
            }
        }
        return true;
    }
    void fang(int &sum,vector<int>&arr,int cur){
        //cout<<"======"<<" "<<cur<<endl;
        if(cur == arr.size()){
            //cout<<"2222"<<cur<<" "<<arr.size()<<endl;
            sum ++;
        }
        for(int i=0;i<arr.size();i++){
            //cout<<"111 "<<i<<endl;
            if(can(arr,cur,i)){
                arr[cur] = i;
                //cout<<"333 "<<i<<endl;
                fang(sum,arr,cur+1);

            }
        }

    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.totalNQueens(4)<<endl;

    return 0;
}

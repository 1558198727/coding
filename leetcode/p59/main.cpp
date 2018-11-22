#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

//判断转弯的条件：
/*
向左、向右:包括左右端点
向上、向下：不包括左右端点，
而不能是所有的处理成一闭一开，
这样就在n是奇数的时候不能赋值最中间的n的平方了

*/

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret(n,vector<int>(n));
        int cnt = 1;
        int i=0;
        int j=0;

        while(cnt <= n*n){

            while(i<=j && j<=n-1-i && cnt <= n*n){
                ret[i][j++] = cnt++;
            }
            j--;
            i++;
            while(i>n-1-j && j > i && cnt <= n*n){
                //if(!ret[i][j++])
                ret[i++][j] = cnt++;
            }
            while(i>=j && j>=n-1-i && cnt <= n*n){
                ret[i][j--] = cnt++;
            }
            j++;
            i--;
            while(i<n-1-j && i>j && cnt <= n*n){
                ret[i--][j] = cnt++;
            }
            j++;
            i++;
        }
        return ret;
    }


};
void print(vector<vector<int> > ret){
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[0].size();j++){
            printf("%d\t",ret[i][j]);

        }
        cout<<endl;
    }
}
int main()
{
    Solution aa;
    vector<vector<int> > array = aa.generateMatrix(10);
    print(array);
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ret = "";
        while(A>0 && B>0){
            if(A>B){
                ret += "aa";
                ret += "b";
                A -= 2;
                B -= 1;
            }else if(A<B){
                ret += "a";
                ret += "bb";
                A -= 1;
                B -= 2;
            }else{
                ret += "a";
                ret += "b";
                A -= 1;
                B -= 1;
            }

        }
        while(A--){
            ret += "a";
        }
        while(B--){
            ret += "b";
        }
        return ret;
    }
};
int main()
{
    Solution Solution1;
    cout<<Solution1.strWithout3a3b(4,1)<<endl;
    return 0;
}

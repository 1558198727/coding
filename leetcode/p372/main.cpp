#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long LL;
class Solution {
public:
    vector<int> chu2(vector<int>& b){

        int jie = 0;
        for(int i=0;i<b.size();i++){
            int curr = jie*10 + b[i];
            jie = curr % 2;
            b[i] = curr/2;
        }
        return b;
    }
    bool iszero(vector<int>& b){
        for(auto i:b){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
    string to_bin(vector<int> b){
        string bin = "";
        while(!iszero(b)){
            bin += b[b.size()-1]%2+'0';
            b = chu2(b);
            /*
            for(auto i:b){
                cout<<i;
            }

            cout<<endl;
            */
        }
        for(int i=0;i < bin.size()/2;i++){
            swap(bin[i],bin[bin.size()-1-i]);
        }
        //cout<<"bin "<<bin<<endl;
        return bin;
    }
    int superPow(int a, vector<int>& b) {
        LL x = a;
        //x %= 1337;
        LL ans = 1;
        string bin = to_bin(b);
        int index = bin.size()-1;
        while(index>=0){
            if(bin[index]=='1'){
                ans = ans*x %1337;
            }
            x = (x*x)%1337;
            index--;
        }
        return ans;
    }
};

int main()
{
    Solution Solution1;
    int a = 2, b[5] = {1,0,1,1,1};
    vector<int>bb(b,b+2);
    cout<<Solution1.superPow(a,bb)<<endl;
    return 0;
}

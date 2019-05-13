#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
typedef long long LL;
#define debug(x) cout<<#x<<": "<<x<<endl;
/*
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
*/

/*
class Solution {
public:
    int myPow(int a,int n){
        int ans = 1;
        a%=1337;
        while(n){
            if(n&1){
                ans*=a;
                ans%=1337;
            }
            a*=a;
            a%=1337;
            n>>=1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        if(a==0 || a==1){
            return a;
        }else if(b.size() == 1 ){
            return int ( myPow(a,b[0]) )%1337 ;
        }
        else{
            int ba = b.back();
            b.pop_back();
            return  ( int(myPow( superPow(a,b),10)) %1337 * int(myPow(a,ba))%1337 )%1337;
        }
    }
};
*/

class Solution {
public:
    int myPow(int a,int n){
        int ans = 1;
        a%=1337;
        while(n){
            if(n&1){
                ans*=a;
                ans%=1337;
            }
            a*=a;
            a%=1337;
            n>>=1;
        }
        return ans;
    }

    int superPow(int a, vector<int>& b) {
        int n = 0;
        if(b.size()==0){
            return 0;
        }
        for(int i=0;i<b.size();i++){
            n*=10;
            n+=b[i];
            n%=1140;
        }
        return myPow(a,n);
    }
};

int main()
{
    Solution Solution1;
    int a = 2, b[5] = {1,0};
    vector<int>bb(b,b+2);
    cout<<Solution1.superPow(a,bb)<<endl;
    return 0;
}

#include <iostream>
#include <map>
#include <math.h>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>ret={ 1,10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771, 8877691};
        return ret[n];
    }
};


long long Anm(long long n,long long m){
    long long ret =1;
    long long mm = m;
    while(mm>0){
        ret*=n;
        mm--;
        n--;
    }

    return ret;
}

int main()
{
    long long ret[11]={0};
    ret[0] = 10;
    for(int i=1;i<11;i++){
        ret[i]=Anm(10,i+1)-Anm(9,i) + ret[i-1];
    }
    for(auto i:ret){
        cout<<i<<", ";
    }
    return 0;
}

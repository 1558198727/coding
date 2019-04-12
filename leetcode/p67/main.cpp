#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        if(a.size()<b.size()){
            swap(a,b);
        }
        int i = a.size()-1;
        int j = b.size()-1;
        int jin = 0;
        while(i>=0 && j>=0){

            if(a[i]-'0'+b[j]-'0'+jin>=2){
                a[i] = (a[i]-'0'+b[j]-'0'+jin)%2+'0';
                jin = 1;
            }else{
                a[i] = a[i]-'0'+b[j]-'0'+ jin + '0';
                jin = 0;
            }
            i--;
            j--;
        }
        while(i>=0){
            if(a[i]-'0' + jin>=2){
                a[i] = (a[i]-'0'+jin)%2+'0';
                jin = 1;
            }else{
                a[i] = a[i]-'0'+jin + '0';
                jin = 0;
            }
            i--;
        }
        if(jin){
            a.insert(0,"1");
        }
        return a;
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.addBinary("1110", "11")<<endl;
    return 0;
}

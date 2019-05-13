#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
class Solution {
public:

    string int_bit(int n){
        string ret = "";
        while(n){
            ret.insert(ret.begin(),n%2+'0');
            n/=2;
        }
        int res = 8 - ret.size();
        for(int i=0;i < res;i++){
            ret.insert(ret.begin(),'0');
        }
        return ret;
    }
    bool validUtf8(vector<int>& data) {
        vector<string>strs(data.size());
        for(int i=0;i<data.size();i++){
            strs[i] = int_bit(data[i]&0xff);
            debug(strs[i])
        }
        for(int i=0;i<strs.size();){
            debug(i);
            if(strs[i][0]=='0'){
                i++;
            }else if(strs[i][0]=='1'){
                if(strs[i][1]=='0'){
                    return false;
                }
                int cnt = 0;
                int j=0;
                while(j<8 && strs[i][j] == '1'){
                    cnt++;
                    j++;
                }
                //debug(cnt)
                if(cnt > 4){
                    return false;
                }

                for(int j=i+1; j<i+cnt;j++){
                    if(j>= strs.size()){
                        return false;
                    }
                    if(strs[j].substr(0,2)== "10"){
                        continue;
                    }else{
                        return false;
                    }
                }
                i += cnt;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> data = {240,162,138,147,145};
    Solution Solution1;
    cout <<  Solution1.validUtf8(data) << endl;
    return 0;
}

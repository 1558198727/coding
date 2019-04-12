#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string getstr(int n,int pos ){
        string ret="";
        if(pos==1){
            while(n--){
                ret += "M";
            }
        }
        else if(pos ==2){
            if(n<=3){
                while(n--){
                    ret += "C";
                }
            }else if(n==4){
                ret = "CD";
            }else if(n==5){
                ret = "D";
            }else if(n<9){
                ret = "D";
                for(int i=0;i<n-5;i++){
                   ret += "C";
                }
            }else if(n==9){
                ret = "CM";
            }
        }else if(pos ==3){
            if(n<=3){
                while(n--){
                    ret += "X";
                }
            }else if(n==4){
                ret = "XL";
            }else if(n==5){
                ret = "L";
            }else if(n<9){
                ret = "L";
                for(int i=0;i<n-5;i++){
                   ret += "X";
                }
            }else if(n==9){
                ret = "XC";
            }

        }else if(pos==4){
            if(n<=3){
                while(n--){
                    ret += "I";
                }
            }else if(n==4){
                ret = "IV";
            }else if(n==5){
                ret = "V";
            }else if(n<9){
                ret = "V";
                for(int i=0;i<n-5;i++){
                   ret += "I";
                }
            }else if(n==9){
                ret = "IX";
            }
        }
        return ret;
    }
    string intToRoman(int num) {
        int nums[5];
        string ret;
        for(int i=4;i>0;i--){
            nums[i] = num%10;
            num/=10;
        }
        for(int i =1;i<5;i++){
            ret += getstr(nums[i],i);
        }
        cout<<"ret "<<ret<<endl;
        return ret;
    }
};

int main()
{
    Solution Solution1;
    Solution1.intToRoman(1994);
    return 0;
}

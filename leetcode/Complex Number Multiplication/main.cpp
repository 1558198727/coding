
//复数乘法给定两个代表两个复数的字符串。
//你需要返回一个代表它们乘法的字符串。根据定义，注意i的平方 = -1。

#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <vector>
#include "stdlib.h"
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
         int aa;
         int bb;
         int cc;
         int dd;
         int ret;
         string retString;
         split(a,aa,bb);
         split(b,cc,dd);
         ret = aa*cc -bb*dd;

         retString +=std::to_string (ret);//.c++11标准增加了全局函数std::to_string:
         retString +="+";
         ret = aa*dd + bb*cc;
         retString +=std::to_string (ret);
         retString +="i";
         return retString;

    }
    void split(string str,int & a,int & b){
        char * d= "+";
        char * Str = new char [str.length()+1];
        for(int i=0;i<str.size();i++){
            Str[i] = str[i];
        }
        char *p;
        vector<char*>results;
        p = strtok (Str,d);
        while(p != NULL)
        {
            //printf("%s\n", p);
            results.push_back(p);
            p=strtok(NULL, d);
        }
            cout<<results[0]<<endl;
            cout<<results[1]<<endl;
            a=atoi(results[0]);
            b=atoi(results[1]);
    }
};
int main()
{
    Solution ss;
    string str1= "3+2i";
    string str2= "5+6i";
    string ret;
    ret = ss.complexNumberMultiply(str1,str2);
    cout<<ret<<endl;

    return 0;
}

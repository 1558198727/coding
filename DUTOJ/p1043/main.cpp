#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int findstr(string str,string aim,int n){
     return str.find(aim, n);
}
int main()
{
    string str= "hahahahahahah";
    string aim[3] ={"0-0","haha","frog"};
    int i;
    int counter;
    while(scanf("%s",&str[0]) != EOF){
        //i = 0;
        //counter = 0;
        cout<<str<<endl;
        /*for(int j=0;j<3;j++){
            while( findstr(str,aim[j],i) != -1){
                counter ++;
                i = findstr(str,aim[j],i);
                i += 2;
            }
        }*/
        //printf("+%ds\n",counter);
    }
    return 0;
}

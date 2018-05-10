#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int N;
    int len;
    int temp;
    int min;
    int maxLen;
    while(scanf("%d",&N)){
        len = 0;
        scanf("%d",&temp);
        min = temp;
        for(int i=0;i<N-1;i ++){
            scanf("%d",&temp);
            if(temp>min){
                min = temp;
                len ++;
            }else{
                maxLen = min;
            }
        }
    }

    return 0;
}

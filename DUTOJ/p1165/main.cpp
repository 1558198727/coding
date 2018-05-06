#include <iostream>
#include <stdio.h>
using namespace std;
int a[50000];
bool isIna(int n){
    bool flag = false;
    int i = 0;
    while(a[i]<n){
        i++;
    }
    if(a[i]==n){
        flag = true;
    }
    return flag;
}
int main()
{
    int T;
    int temp;

    scanf("%d",&T);
    a[0]=3;
    for(int i=1;i<50000;i++){
        a[i]=a[i-1]+i+1;
    }
    for(int i=0;i<T;i++){
        scanf("%d",&temp);
        if(temp<3){
            printf("Xiaoming\n");
        }else{
            if(isIna(temp)){
                printf("Xiaoming\n");
            }else{
                printf("Xiaohong\n");
            }
        }

    }

    return 0;
}

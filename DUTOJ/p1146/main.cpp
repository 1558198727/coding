#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int a[100000][2];
bool cmp(int *aa,int *bb){
    return fabs(aa[0]-aa[1])>fabs(bb[0]-bb[1]);
}
int main()
{
    int n;
    int sum=0;
    int countera=0;
    int counterb=0;
    scanf("%d",&n);
    int **b;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i][0]);
        scanf("%d",&a[i][1]);
    }
    b = (int**)a;
    sort( b,b + n,cmp);
    for(int i=0;i<n;i++){
        //if(a[0]>a[1]){
          cout<<a[i][0]<<" "<<a[i][1]<<endl;
        //}
    }
    return 0;
}

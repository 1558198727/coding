#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int peakIndexInMountainArray(int* A, int ASize) {
    for(int i=0;i<ASize;i++){
        if(A[i+1]>A[i]){
            continue;
        }else{
            return i;
        }
    }
    return 0;
}
int main()
{
    int a[3]={0,1,0};

    cout<<peakIndexInMountainArray(a,3);
    return 0;
}

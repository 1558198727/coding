#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int arr[200001];

#define debug(x) cout<<#x<<": "<<x<<endl;

int main()
{
    int n;
    scanf("%d",&n);

    memset(arr,0, sizeof(arr) );
    int maxn = 0;
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        arr[temp] = 1;
        maxn = temp;
    }
    if(n==1){
        printf("1\n");
        return 0;
    }
    int ret = 0;
    for(int i=2;i <= maxn;i++){
        if( arr[i] == 1 ){
            //debug(i)
            ret++;
            for(int k=1;k< maxn;k++){
                if( k*(i-1) <= maxn ){
                    arr[ k*(i-1)+1 ] = 0;
                }else{
                    break;
                }
            }
        }
    }
    printf("%d\n",ret);
    return 0;
}

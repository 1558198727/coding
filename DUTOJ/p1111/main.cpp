#include <iostream>
#include <stdio.h>
#include<set>
using namespace std;
int a[100000];
int main()
{
    int n;
    int q;
    int L;
    int R;
    int ret;
    set<int>set1;
    set<int>::iterator iter;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&L);
        scanf("%d",&R);
        set1.clear();
        L--;
        R--;
        ret = a[L];
        set1.insert(a[L]);
        for(int j=L+1;j<=R;j++){
            set1.insert(a[j]);
            ret ^= a[j];
        }
        iter=set1.begin();
        while(iter!=set1.end()){
            ret ^= *iter;
            ++iter;
        }
        printf("%d\n",ret);
    }

    return 0;
}
//³¬Ê±ÁË

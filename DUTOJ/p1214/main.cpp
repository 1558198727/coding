#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
using namespace std;
int n,m;
int grap[1001][1001];
int cost[1001][1001];
bool Dijstra(int c,int d)
{
    int [n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

        }
    }

}
int main()
{

    int x,y,q;
    while(scanf("%d",&n)!= EOF){
        scanf("%d",&m);
        memset(grap,0x3F,sizeof(grap));
        memset(grap,0x3F,sizeof(cost));

        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            scanf("%d",&y);
            grap[x-1][y-1] = 1;
        }
        scanf("%d",&x);
        scanf("%d",&y);
        if(DFS(x-1,y-1))
            printf("first\n");
        else if(DFS(y-1,x-1))
            printf("second\n");
        else
            printf("unknown\n");

    }
    return 0;

}

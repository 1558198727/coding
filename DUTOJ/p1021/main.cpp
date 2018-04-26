#include <iostream>
#include<string.h>
using namespace std;
int n,m;
int grap[1001][1001];
bool DFS(int c,int d)
{
    bool flag;
    if(c==d)return true;
    else for(int i=0;i<n;i++)
    {
        if(grap[c][i]==1&&i!=c)
        {
            flag=DFS(i,d);
            if(flag)return flag;
        }
    }
    return false;
}
int main()
{

    int x,y;
    cin>>n;
    cin>>m;
    memset(grap,0,sizeof(grap));
    for(int i=0;i<m;i++)
    {
        cin>>x;
        cin>>y;
        grap[x-1][y-1]=1;
    }
    cin>>x;
    cin>>y;
    if(DFS(x-1,y-1))
        cout<<"first"<<endl;
    else if(DFS(y-1,x-1))
        cout<<"second"<<endl;
    else
        cout<<"unknown"<<endl;
    return 0;
}

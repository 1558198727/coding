#include <iostream>

using namespace std;

int main()
{
    int n;
    void hannuo(int n,char x,char y,char z);
    cout<<"������Nֵ"<<endl;
    cin>>n;
    hannuo(n,'A','B','C');

    return 0;
}
void hannuo(int n,char x,char y,char z)
{
    if(n==1)
    {
        cout<<x<<"------>"<<z<<endl;
    }
    else
    {
        hannuo(n-1,x,z,y);
        cout<<x<<"------>"<<z<<endl;
        hannuo(n-1,y,x,z);
    }
}

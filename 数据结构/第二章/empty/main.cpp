#include<iostream>
#include<string.h>
using namespace std;
int myAtoi(char* str)
{
    int i=0;
    int j=0;
    int flag=1;
    bool zhengfu=true;
    bool youfuhao=false;
    int jie;
    if(str[0]=='\0')
    {
        cout<<"sdfas"<<endl;
    }

    if((str[0]>=48 && str[0]<=57))
    {
        ;
    }
    else if(str[0]=='+')
    {

       zhengfu=true;
       youfuhao=true;
    }
    else if(str[0]=='-')
    {
        zhengfu=false;
        youfuhao=true;
    }
    else
    {
     flag=0;
    }

    i=1;
    while(str[i]!='\0')
    {

        if(str[0]>=48 && str[0]<=57)
        {
            ;
        }
        else
        {
            flag=0;
        }
         i++;
    }
    i=0;
    while(str[i]!='\0')
    {
      i++;
    }
    if(youfuhao)
    {
        int jie=str[1]-48;
        for(j=1;j<i-1;j++)
       {
        jie*=10;
        jie+=str[j+1]-48;
       }
       if(zhengfu)
       return jie;
       else
        return -jie;
    }
    else
    {
        int jie=str[0]-48;
        for(j=0;j<i-1;j++)
        {
        jie*=10;
        jie+=str[j+1]-48;
       }
    }
    for(j=0;j<i-1;j++)
    {
        jie*=10;
        jie+=str[j+1]-48;
    }
    if(i==0 ||!flag)
    {
        return 0;
    }
    else
    return jie;
}


int main()
{
    cout<<myAtoi("")<<endl;
}

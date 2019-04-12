#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    cout<<"0xFFFFFFFF\t"<<0xFFFFFFFF<<endl;
    cout<<"(int)0xFFFFFFFF\t"<<(int)0xFFFFFFFF<<endl;
    cout<<"0x7FFFFFFF\t"<<0x7FFFFFFF<<endl;
    cout<<"(int)0xFFFFFFFF\t"<<(int)0xFFFFFFFF<<endl;
    cout<<"(int)0x7FFFFFFF\t"<<(int)0x7FFFFFFF<<endl;
    cout<<"INT_MAX\t\t"<<INT_MAX<<endl;
    cout<<"INT_MIN\t\t"<<INT_MIN<<endl;
    cout<<"0xFFFFFFFF+1\t\t"<<0xFFFFFFFF+1<<endl;
    cout<<"0x10000000\t"<<0x10000000<<endl;
    cout<<"(int)0x80000000\t"<<(int)0x80000000<<endl;

    cout<<"(int)0x80000000\t"<<(int)0x80000000<<endl;
    cout<<"(int)0x80000000\t"<<(int)0x80000000<<endl;

    cout<<"string::npos\t"<<string::npos<<endl;
    cout<<"0xFFFFFFFF==-1 "<<(0xFFFFFFFF==-1)<<endl;
    cout<<"0xFFFFFFFF<0 "<<(0xFFFFFFFF<0)<<endl;
    cout<<"(int)0xFFFFFFFF<0 "<<((int)0xFFFFFFFF<0)<<endl;
    cout<<"INT_MAX==-1 "<<(INT_MAX==-1)<<endl;

    return 0;
}

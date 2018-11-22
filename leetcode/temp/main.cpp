
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<sstream>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int maxn = 100;
#define isBigC(x) ((x>='A' && x<='Z') ? true:false)
#define isSmallC(x) ((x>='a' && x<='z') ? true:false)
#define isN(x) ((x>='0' && x<='9') ? true:false)
int main()
{
    string string_temp="302";
    int i=0;
    int int_temp=0;
    //int_temp=atoi(string_temp.c_str());

    while(isN(string_temp[i])){
        int_temp*=10;
        int_temp+=string_temp[i]-'0';
        i++;
    }
    cout<<int_temp<<endl;
    return 0;
}

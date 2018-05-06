#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

    int x;
    int days;
    int hours;
    int minutes;
    int second;
    while(scanf("%d",&x)!=EOF){
        days = x/86400;
        x %= 86400;
        hours = x /3600;
        x %= 3600;
        minutes = x/60;
        x %= 60;
        second = x;
        printf("%dday(s),%02d:%02d:%02d\n",days,hours,minutes,second);
        //%02d中2是指输出字符的最少个数，0是指不足位时前补0，d表示输出一个整
    }

    return 0;
}

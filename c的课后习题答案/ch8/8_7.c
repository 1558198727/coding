/*8_7
将一个正整数分解质因数。
输入90,打印出90 = 2 * 3 * 3 * 5。*/
#include<stdio.h>
void main()
{
	int n,i;
	printf("please input a number:\n");
	scanf("%d",&n);
	if(n<1)printf("wrong number\n");
	else
	{
		printf("%d=",n);
		for(i=2;i<n;i++)
		{
			while(i!=n)
			{
				if(n%i==0)					//找到因子并输出
				{
					printf("%d*",i);
					n=n/i;
				}
				else break;
			}
		}
		printf("%d\n",n);
	}
}

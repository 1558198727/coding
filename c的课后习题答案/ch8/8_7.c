/*8_7
��һ���������ֽ���������
����90,��ӡ��90 = 2 * 3 * 3 * 5��*/
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
				if(n%i==0)					//�ҵ����Ӳ����
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

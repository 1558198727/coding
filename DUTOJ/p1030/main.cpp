#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int M;
    double x,y;
    double x0,y0;
    while(scanf("%d",&M)!=EOF){
        scanf("%lf",&x);
        scanf("%lf",&y);
        x0 = 1;
        y0 = 1;
        while(x/x0 + y/y0 >1){
            y0 ++;
            x0 ++;
            printf("2222\n");
        }
        for(int i=0;i<M-1;i++){
            scanf("%lf",&x);
            scanf("%lf",&y);
            if(x<y){
                while(x/x0 +y/y0 >1){
                    y0 ++;
                    printf("dd\n");
                }
            }else if(x>y) {
                while(x/x0 + y/y0 >1){
                    x0 ++;
                    printf("111\n");
                }
            }else{
                while(x/x0 + y/y0 >1){
                    y0 ++;
                    x0 ++;
                    printf("2222\n");
                }
            }
        }
    printf("%lf\n",x0*y0/2);
    }
    return 0;
}

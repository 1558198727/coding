#include <iostream>

using namespace std;

int main()
{
    int r,y,g;
    int n;
    cin>>r>>y>>g;
    cin>>n;
    int sum = 0;
    for(int i=0;i<n;i++){
        int k,t;
        cin>>k>>t;
        if(k==0){
            sum += t;
        }else if(k==1){
            sum += t;
        }else if(k==2){
            sum +=t;
            sum+=r;
        }else if(k==3){
            ;
        }
    }
    cout<<sum<<endl;
    return 0;
}

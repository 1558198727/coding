#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int len = speed.size();
        vector<int> flag(len);
        for(int i=0;i<len;i++){
            if(position[i]+speed[i]<=target){
                position[i] += speed[i];
            }else{
                position[i] = target+1;
            }
        }
        for(int i=0;i<len;i++){
            flag[i]=1;
            for(int j=i+1;j<len;j++){
                if(position[i]==position[j]){
                    flag[j]=1;
                }
            }

        }
    }
};

int main()
{
    Solution Solution1;
    vector<int> position;
    vector<int> speed;
    int position1[5] = {10,8,0,5,3};
    int speed1[5] = {2,4,1,1,3};
    for(int i=0;i<5;i++){
        position.push_back(position1[i]);
        speed.push_back(speed1[i]);
    }
    Solution1.carFleet(12,position,speed);
    return 0;


}

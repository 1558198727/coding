#include <iostream>
#include <map>
#include <time.h>
#include <stdlib.h>
using namespace std;
typedef map<int,int> counter;
class Solution {
public:
    int rand10() {
        while(1){
           int rand49 = (rand7()-1)*7+rand7()-1;
            if(rand49<=39){
                return rand49/4+1;
            }
        }
        return 0;
    }
};

int main()
{
    Solution Solution1;
    Solution1.rand10();
    return 0;
}

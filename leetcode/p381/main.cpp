#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>
using namespace std;

class RandomizedCollection {
public:
    map<int ,int >mp;
    int cnt;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(0));
        cnt = 0;
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        mp[val]++;
        cnt++;
        return true;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        --mp[val];
        if(mp[val]>=0){
            cnt--;
            return true;
        }else{
            mp[val] = 0;
            return false;
        }
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int ran = rand()% cnt+1;
        map<int ,int >::iterator it = mp.begin();
        for(; it!= mp.end();it++){
            ran -= it->second;
            if(ran<=0){
                return it->first;
            }
        }
        return it->first;
    }
};


int main()
{
    RandomizedCollection RandomizedCollection1;
    for(int i=0;i<10;i++)
    cout<<RandomizedCollection1.insert(1)<<endl;
    for(int i=0;i<11;i++){
        cout<<RandomizedCollection1.remove(1)<<endl;
    }
    return 0;
}

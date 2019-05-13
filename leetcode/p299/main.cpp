#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> ccnt;
        map<char,int> scnt;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                scnt[ secret[i] ]++;
            }
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.getHint("1123","0111"); << endl;
    return 0;
}

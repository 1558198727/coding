#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==0){
            return 0;
        }
        int i = 0;
        while(s[i]==' '){
            i++;
        }
        if(i == s.size()){
            return 0;
        }else{
            s = s.substr(i);
        }

        i = s.size() - 1;
        while(i>0 && s[i]==' '){
            i--;
        }
        s = s.substr(0,i+1);
        cout<<s.size()<<endl;

        i = s.size() - 1;
        while(i>0 && s[i]!=' '){
            i--;
        }
        if(i>0)
        s = s.substr(i+1);
        return s.size();
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.lengthOfLastWord(" d")<<endl;
    return 0;
}

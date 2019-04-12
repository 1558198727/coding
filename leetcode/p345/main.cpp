#include <iostream>
#include <string>

using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
class Solution {
public:
    bool is_yuan(char c){

        string yuan = "aoeiuAOEIU";
        return yuan.find(c)!=string::npos?true:false;
    }
    string reverseVowels(string s) {
        if(s.size()==0){
            return s;
        }
        int i=0,j = s.size()-1;
        //cout<<is_yuan('v')<<endl;
        while(i<j){
            while(!is_yuan(s[i]) && i<j){
                i++;
            }
            while(!is_yuan(s[j]) && i<j){
                j--;
            }
            if(i>=j){
                return s;
            }else{
                swap(s[i],s[j]);
                i++;
                j--;
            }

        }
        return s;
    }
};

int main()
{

    Solution Solution1;
    cout<<Solution1.reverseVowels(".,")<<endl;
    return 0;
}

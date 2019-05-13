#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string zhuan[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string>se;
        for(int i=0;i<words;i++){
            word = "";
            for(int j=0;j<words[i].size();j++){
                words += zhuan[words[i][j] ];
            }
            se.insert(word);
        }
        return se.size();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

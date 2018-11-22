#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;

        do {
            if (s.size() <= 1) {
                ret = s.size();
                break;
            }

            set<char> setChars;
            for (int i = 0; i < s.size(); ++i) {
                for (int j = i; j < s.size(); ++j) {
                    if (setChars.count(s[j])) {
                        break;
                    } else {
                        setChars.insert(s[j]);
                    }
                }

                if (setChars.size() > ret) {
                    ret = setChars.size();
                }
                setChars.clear();
            }
        } while (false);

        return ret;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

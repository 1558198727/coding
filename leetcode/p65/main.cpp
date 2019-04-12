#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		string re = "[[:graph:]]+@163[.]com";
		regex rule(re);
		string str = "acvds.cpp@163.com";
		cout << regex_match(str, rule) << endl; //true
		return false;
	}
};

int main()
{
	Solution Solution1;
	Solution1.isNumber("a.e.q");
	return 0;
}


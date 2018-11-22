#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<sstream>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int maxn = 100;
class Solution {
private:
    // 输入字符串：化学公式
    string formula;
    // 指针：指向formula当前位置
    int start = 0;
public:
    string countOfAtoms(string formula) {
        this->formula = formula;
        // 递归得到化学公式里每个原子及其对应的个数，以哈希表map形式存储
        map<string, int> relation = getAtomsRelation();
        // 将得到的结果转成字符串输出：由于map按key的字典序保存，所以从头开始遍历
        string result = "";
        for (map<string, int>::iterator it = relation.begin(); it != relation.end(); it++) {
            result += it->first;
            // 将int转成string
            if (it->second > 1) {
                stringstream ss;
                ss << it->second;
                result += ss.str();
            }
        }
        return result;
    }
    map<string, int> getAtomsRelation() {
        // 创建当前递归的哈希表
        map<string, int> cur;
        while (start < formula.length()) {
            // 遇到'('进入下一层递归，然后将递归的结果存入当前哈希表中
            if (formula[start] == '(') {
                start++;
                map<string, int> inCur = getAtomsRelation();
                for (map<string, int>::iterator it = inCur.begin(); it != inCur.end(); it++)
                    cur[it->first] += it->second;

            // 遇到')'返回上一层递归，返回之前还要看看后面有没有数字，如果有，要将当前哈希表所有值乘以这个数再返回
            } else if (formula[start] == ')') {
                int j = start + 1, tempInt = 0;
                while (j < formula.length() && formula[j] <= '9' && formula[j] >= '0') {
                    tempInt *= 10;
                    tempInt += formula[j] - '0';
                    j++;
                }
                tempInt = tempInt == 0 ? 1 : tempInt;

                for (map<string, int>::iterator it = cur.begin(); it != cur.end(); it++)
                    it->second *= tempInt;

                start = j;
                return cur;

            // 遇到大写字母表示遇到新的原子，得到当前原子全名和对应数字，存入当前哈希表中
            } else if (formula[start] >= 'A' && formula[start] <= 'Z') {
                // 得到原子全名
                int j = start + 1;
                while (j < formula.length() && formula[j] >= 'a' && formula[j] <= 'z')
                    j++;
                string tempString = formula.substr(start, j - start);

                // 得到对应数字
                int tempInt = 0;
                while (j < formula.length() && formula[j] <= '9' && formula[j] >= '0') {
                    tempInt *= 10;
                    tempInt += formula[j] - '0';
                    j++;
                }
                tempInt = tempInt == 0 ? 1 : tempInt;

                // 存入哈希表中
                cur[tempString] += tempInt;

                start = j;
            }
        }
        return cur;
    }
};

int main()
{
    string formula = "K4(ON(SO3)2)2";
    Solution Solution1;
    cout<<Solution1.countOfAtoms(formula)<<endl;
    return 0;
}

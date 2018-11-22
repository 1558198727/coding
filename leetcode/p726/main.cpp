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
#define isBigC(x) ((x>='A' && x<='Z') ? true:false)
#define isSmallC(x) ((x>='a' && x<='z') ? true:false)
#define isN(x) ((x>='0' && x<='9') ? true:false)

//·ÇµÝ¹é
class Solution {
public:
    int start;
    string countOfAtoms(string formula) {
        start = 0;
        map<string ,int>strInt;
        stack<pair<string,int> > sks;
        while(start < formula.length()){
            if(formula[start]=='('){

                string tempString = formula.substr(start,1);
                sks.push(pair<string ,int>(tempString,0));
                start ++;
            }else if(isBigC(formula[start])){
                int j = start + 1;
                while(isSmallC(formula[j])){
                    j++;
                }
                string subs = formula.substr(start ,j - start);
                int tempInt = 0;
                while(isN(formula[j])){
                    tempInt *= 10;
                    tempInt += formula[j] - '0';
                    j++;
                }
                tempInt = tempInt==0 ? 1 : tempInt;
                sks.push(pair<string ,int>(subs,tempInt));
                start = j;

            }else if(formula[start]==')'){
                int k = start + 1;

                int intTemp=0;
                while(isN(formula[k])){
                    intTemp *= 10;
                    intTemp += formula[k]-'0';
                    k++;
                }
                start = k;
                intTemp = intTemp==0 ? 1 : intTemp;
                stack<pair<string,int> > sktemp;
                pair<string,int> stemp;
                do{
                    stemp = sks.top();
                    stemp.second *= intTemp;
                    if(stemp.first!= "(")
                    sktemp.push(pair<string,int>(stemp.first,stemp.second));
                    sks.pop();
                }while(stemp.first != "(");

                while(!sktemp.empty()){
                    sks.push(sktemp.top());
                    sktemp.pop();
                }
            }
        }
        pair<string,int> temp1;
        while(!sks.empty()){

            temp1 = sks.top();
            strInt[temp1.first] += temp1.second;
            sks.pop();
        }
        map<string ,int>::iterator it;
        string ret="";
        for(it=strInt.begin();it!=strInt.end();it++){
            ret += it->first;
            stringstream stream;
            if(it->second>1){
                stream<<it->second;
                ret +=  stream.str();
            }

        }
        return ret;
    }
};

//µÝ¹é
/*
class Solution {
public:
    int start;
    string countOfAtoms(string formula) {
        start = 0;
        map<string,int> ret = cal(formula);
        map<string,int>::iterator it;
        string retS="";
        for(it = ret.begin();it!=ret.end();it++){
            retS += it->first;
            if(it->second>1){
                stringstream stream;
                stream<<it->second;
                retS += stream.str();
            }

        }
        return retS;
    }
    map<string,int> cal(string formula){
        map<string,int> strInt;

        while(start < formula.length()){
            if(formula[start]=='('){
                start++;
                map<string,int> tempMap = cal(formula);
                map<string,int>::iterator it;
                for(it = tempMap.begin();it!=tempMap.end();it++){
                    strInt[it->first] += it->second;
                }
            }else if(isBigC(formula[start])){
                int j = start + 1;
                while(isSmallC(formula[j])){
                    j++;
                }
                string subs = formula.substr(start ,j - start);
                int tempInt = 0;
                while(isN(formula[j])){
                    tempInt *= 10;
                    tempInt += formula[j] - '0';
                    j++;
                }
                tempInt = tempInt==0 ? 1 : tempInt;
                strInt[subs] += tempInt;
                start = j;

            }else if(formula[start]==')'){

                int k = start+1;
                int intTemp=0;
                while(isN(formula[k])){
                    intTemp *= 10;
                    intTemp += formula[k]-'0';
                    k++;
                }
                start = k;
                map<string,int>::iterator it;
                intTemp = intTemp==0 ? 1 : intTemp;
                for(it = strInt.begin();it!=strInt.end();it++){
                    strInt[it->first] *= intTemp;
                }
                return strInt;
            }
        }
        return strInt;

    }

};

*/
int main()
{
    string formula = "K4(ON(SO3)2)2";
    Solution Solution1;
    string s = Solution1.countOfAtoms(formula);
    cout<<s<<endl;

    return 0;
}

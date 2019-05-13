#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;
class Solution {
public:
    vector<string> split(string s,char sp){
        vector<string> ret;
        if(s.size()==0){
            return ret;
        }
        if(s[0]==sp){
            s = s.substr(1);
        }
        int i=0,j=0;
        while(i<s.size()){
            if((j = s.find(sp,i)) != string::npos ){
                ret.push_back( s.substr(i,j-i) ) ;
                i = j+1;
            }else{
                break;
            }
        }
        ret.push_back(s.substr(i,s.size()-i ));
        return ret;
    }
    string simplifyPath(string path) {
        if(path.size()==0){
            return "";
        }
        int pos = 0;
        int i=0;
        for(i=0;i < path.size()-1;){
            if(path[i]=='/' && path[i] == path[i+1]){
                i++;
            }else{
                path[pos++] = path[i++];
            }
        }
        if(path[i]!='/'){
            path[pos++] = path[i++];
        }
        path = path.substr(0,pos);
        //debug(path)
        vector<string> sppath = split(path,'/');
        int le = 0;
        vector<string> retv;
        for(int i=0;i<sppath.size();i++){
            //debug(sppath[i])
            if(sppath[i]=="."){
                ;
            }else if(sppath[i]==".."){
                le--;
                if(le<0){
                    le = 0;
                }
            }else{
                if(retv.size() == 0 || le == retv.size()){
                    retv.push_back( sppath[i] );
                    le++;
                }else{
                    retv[le]=sppath[i];
                    le++;
                }

            }
        }
        string ret = "";
        for(int i=0;i<le;i++){
            ret += "/" + retv[i];
        }
        if(ret.size()==0){
            ret = "/";
        }
        return ret;

    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.simplifyPath("/a/./b/../../c/") << endl;
    return 0;
}

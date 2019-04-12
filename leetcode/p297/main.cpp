#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Codec {
public:


    string int_str(int a){
        stringstream ss;
        ss<<a;
        return ss.str();
    }
    int str_int(string s){
        stringstream ss;
        ss<<s;
        int a;
        ss>>a;
        return a;
    }

    vector<string> split(string s){
        vector<string> ret;
        if(s.size()==0){
            return ret;
        }
        for(int i=0;i<s.size();){
            int j=i;
            j = s.find(",",j);
            if(j>0){
                ret.push_back(s.substr(i,j-i));
                i = j+1;
            }else{
                //debug(s.substr(i,s.size()-i) );
                ret.push_back(s.substr(i,s.size()-i));
                break;
            }

        }
        //for(auto i:ret){
        //    cout<<i<<endl;
        //}
        return ret;
    }
        // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> qu;
        string ret="";
        if(root==NULL){
            return ret;
        }
        qu.push(root);
        //debug(root->val);
        while(!qu.empty()){
            TreeNode* fr = qu.front();
            qu.pop();
            //debug(fr->val);
            if(fr)
                ret += (int_str(fr->val)+",");
            else
                ret+="n,";
            if(fr){
                qu.push(fr->left);
                qu.push(fr->right);
            }
        }
        cout<<ret<<endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> ves = split(data);
        TreeNode* root = nullptr;
        if(ves.size()==0){
            return nullptr;
        }
        root = new TreeNode(str_int(ves[0]));
        queue<TreeNode*>qu;
        qu.push(root);
        int pos = 0;
        while(!qu.empty() && pos < ves.size()-1){
            TreeNode* fr = qu.front();
            qu.pop();
            //debug(fr->val);
            if( ves[++pos]!= "n"){
                //debug(str_int(ves[pos]));
                fr->left = new TreeNode(str_int(ves[pos]) );
                qu.push(fr->left);
            }

            if(pos >= ves.size()-1){
                return root;
            }

            if( ves[++pos]!= "n"){
                //debug(str_int(ves[pos]));
                fr->right = new TreeNode(str_int(ves[pos]) );
                qu.push(fr->right);
            }

        }

        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    Codec Codec1;
    TreeNode* no = Codec1.deserialize("1,2,3,4,5,n,n,n,n,n,n");
    Codec1.serialize(no);
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        inorder(root,ret);
        return ret;
    }
    void inorder(TreeNode* root,vector<int>&ret){
        if(root){
            inorder(root->left,ret);
            ret.push_back(root->val);
            inorder(root->right,ret);
        }
    }
};
*/


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        if(root==nullptr){
            return ret;
        }
        stack<TreeNode*> st;
        st.push(root);

        TreeNode* temp = root;
        while(temp->left){
            //debug(temp->left->val);
            st.push(temp->left);
            temp = temp->left;
        }
        while(!st.empty()){
            TreeNode* tp = st.top();
            st.pop();
            //debug(tp->val);
            ret.push_back(tp->val);
            //debug(tp->val);
            if(tp->right){
                st.push(tp->right);
                //debug(tp->right->val);
                temp = tp->right;
                while(temp->left){
                    //debug(temp->left->val);
                    st.push(temp->left);
                    temp = temp->left;
                }
            }

        }
        return ret;
    }

};
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

int main()
{
    TreeNode * head  = deserialize("1,2,3,4,5,6,7,n,n,n,n,n,n,n,n");
    Solution Solution1;
    vector<int>ret = Solution1.inorderTraversal(head);
    for(auto i:ret){
        debug(i);
    }
    return 0;
}

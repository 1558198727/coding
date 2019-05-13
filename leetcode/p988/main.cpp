#include <iostream>

using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string ret = "";
    string smallestFromLeaf(TreeNode* root) {
        finw(root,"");
        return ret;
    }
    void finw(TreeNode* root,string temp){
        if(!root){
            return ;
        }else if(!root->left && !root->right){
            temp = string(1,root->val + 'a') + temp ;
            if(ret == ""){
                ret = temp;
            }else{
                ret = min(ret,temp);
            }
            return;
        }
        if(root->left){
            finw(root->left,string(1,root->val + 'a') + temp);
        }
        if(root->right){
            finw(root->right,string(1,root->val + 'a') + temp);
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.smallestFromLeaf(nullptr) << endl;
    return 0;
}

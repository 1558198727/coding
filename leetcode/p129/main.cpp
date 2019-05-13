#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ret = 0;
        add(ret,root,0);
        return ret;
    }
    void add(int &ret,TreeNode* root,int preVal){
        if(!root){
            return ;
        }
        if(!root->left && !root->right){
            ret += preVal*10+root->val;
            return;
        }
        if(root->left){
            add(ret,root->left,preVal*10+root->val);
        }
        if(root->right){
            add(ret,root->right,preVal*10+root->val);
        }

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

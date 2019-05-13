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
    bool ret = true;
    bool isBalanced(TreeNode* root) {
        height(root);
        return ret;
    }
    int height(TreeNode* root){
        if(!root){
            return 0;
        }else if(!root->left && !root->right){
            return 1;
        }
        int lson = height(root->left);
        int rson = height(root->right);
        if(abs(lson-rson)>1){
            ret = false;
        }
        return 1 + max(lson,rson);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

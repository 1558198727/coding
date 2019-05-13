#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            swap(root->left,root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

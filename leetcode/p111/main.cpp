#include <iostream>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root){
            if(root->left && root->right){
                return 1 + min( minDepth(root->left) , minDepth(root->right) );
            }else if(root->left){
                return 1 + minDepth(root->left);
            }
            else if(root->right){
                return 1 + minDepth(root->right);
            }else{
                return 1;
            }
        }else{
            return 0;
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

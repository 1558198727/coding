#include <iostream>
#include <limits.h>
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
    long long visit = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        return order(root);
    }
    bool order(TreeNode* root){
        if(root){
            bool is = order(root->left);
            if(root->val <= visit ){
                return false;
            }else{
                visit = root->val;
            }
            return is && order(root->right);
        }
        return true;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

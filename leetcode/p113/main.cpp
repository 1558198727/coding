#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        findw(root,sum,{},ret);
        return ret;
    }
    void findw(TreeNode* root, int sum,vector<int> tans,vector<vector<int>>&ret){
        if(!root){
            return;
        }
        if(root->val == sum && !root->left && !root->right){
            tans.push_back(root->val);
            ret.push_back(tans);
        }else{
            tans.push_back(root->val);
            if(root->left){
                findw(root->left,sum - root->val,tans,ret);
            }
            if(root->right){
                findw(root->right,sum - root->val,tans,ret);
            }
        }
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

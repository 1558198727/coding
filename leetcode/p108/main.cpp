#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return make(nums);
    }
    TreeNode* make(vector<int> nums){
        if(nums.size()==0)return nullptr;
        int n = nums.size();
        TreeNode*root = new TreeNode(nums[n/2]);
        root->left = make( vector<int>( begin(nums),next(begin(nums),n/2) ) );
        root->right = make( vector<int>( next(begin(nums),n/2+1),end(nums) ));
        return root;
    }
};

void dfs(TreeNode * t){
    if(t!=NULL){
        cout<<t->val<< " ";
        dfs(t->left);
        dfs(t->right);
    }
}
int main()
{


    Solution Solution1;

    int a[7] = {-10,-3,0,5,9};
    vector<int> ve(a,a+5);
    dfs(Solution1.sortedArrayToBST(ve));

    return 0;
}

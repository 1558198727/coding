#include <iostream>
#include <queue>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): left(NULL), right(NULL){}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxLen = 0;
    int longestUnivaluePath(TreeNode* root) {

        if(root==NULL){
            return 0;
        }
        getLongestPath(root);
        return maxLen;
    }
    //递归函数做两件事情
    //1统计左右两边的相同的数字的长度
    //2返回左右中较长的串的长度
    int getLongestPath(TreeNode*root){
        int l=0,r=0;
        if(root->left==NULL && root->right == NULL){
            return 0;
        }
        if(root->left && root->left->val==root->val){

            l = 1 + getLongestPath(root->left);
        }else if(root->left){
            getLongestPath(root->left);
        }
        if(root->right && root->right->val==root->val){

            r = 1 + getLongestPath(root->right);
        }else if(root->right){
            getLongestPath(root->right);
        }

        maxLen = max(maxLen,l+r);
        return (l > r) ? l : r;
    }
};
int main()
{
    Solution Solution1;
    queue<TreeNode*> q;
    int a[7] = {1,2,2,3,4,4,3};
    TreeNode* root = new TreeNode();
    root->val = a[0];
    TreeNode* temp = root;
    q.push(temp);
    int i=1;
    while(!q.empty() && i<7){
        temp = q.front();
        q.pop();
        temp->left = new TreeNode();
        temp->left->val = a[i];
        i++;
        q.push(temp->left);

        temp->right = new TreeNode();
        temp->right->val = a[i];
        i++;
        q.push(temp->right);
    }
    int ret;
    ret=Solution1.longestUnivaluePath(root);
    cout<<ret<<endl;
    return 0;
}

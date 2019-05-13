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
void dfs(TreeNode * t){
    if(t!=NULL){
        cout<<t->val<< " ";
        dfs(t->left);
        dfs(t->right);
    }
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q == nullptr){
            return true;
        }else if( (p && !q) || (!p && q)){
            return false;
        }else{
            if(p->val==q->val){
                return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
            }else{
                return false;
            }
        }
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

    cout<<Solution1.isSameTree(root,root)<<endl;


    return 0;
}

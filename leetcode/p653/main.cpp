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
    vector<int> ve;
    void dfs(TreeNode * t){
        if(t!=NULL){
            dfs(t->left);
            ve.push_back(t->val);
            dfs(t->right);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        if(ve.size()==0){
            return false;
        }
        int i=0;
        int j = ve.size()-1;
        while(i<j){
            if(ve[i] + ve[j]>k){
                j--;
            }else if(ve[i]+ve[j]<k){
                i++;
            }else{
                return true;
            }
        }
        return false;
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

    cout<<Solution1.findTarget(root,7)<<endl;


    return 0;
}

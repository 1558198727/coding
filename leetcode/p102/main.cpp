#include <iostream>
#include <vector>
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        vector<int> tem;
        TreeNode * nothing = new TreeNode(0);//压如一个空的指针表示一行结束
        if(root!=NULL){
            q.push(root);
            q.push(nothing);
        }
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==nothing ){
                if(q.size()>0){
                    q.push(nothing);
                }
                ret.push_back(tem);
                tem.clear();
            }else{
                if(temp!=nothing){
                    tem.push_back(temp->val);
                }
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);

            }

        }
        return ret;
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
    vector<vector<int> > ret;
    ret=Solution1.levelOrder(root);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

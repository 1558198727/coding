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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        queue<TreeNode *>que;
        vector<vector<int> >ret;
        vector<int> retTemp;
        if(root){
            que.push(root);
        }else{
            return ret;
        }
        que.push(NULL);


        while(que.size() > 0){
            TreeNode * temp = que.front();
            que.pop();
            if(temp){
                retTemp.push_back(temp->val);
                //cout<<"temp->val "<<temp->val<<endl;
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }

            }else{
                //cout<<"temp "<<temp <<endl;
                if(que.size() > 0){
                    que.push(NULL);
                }

                ret.insert(ret.begin(),retTemp);
                retTemp.clear();

            }

        }
        return ret ;
    }
};
int main()
{
    queue<TreeNode*> q;

    Solution Solution1;

    int a[7] = {3,9,20,NULL,NULL,15,7};
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
    ret=Solution1.levelOrderBottom(root);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

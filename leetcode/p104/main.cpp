

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }else{
            return maxH(root);
        }

    }
    int maxH(TreeNode* rt){
        if(rt->left==NULL && rt->right == NULL){
            return 1;
        }else if(rt->left==NULL){
            return 1 + maxH(rt->right);
        }else if(rt->right==NULL){
            return 1 + maxH(rt->left);
        }else{
            return 1+ max(maxH(rt->left),maxH(rt->right));
        }
    }
};


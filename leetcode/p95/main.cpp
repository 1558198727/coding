#include <iostream>
#include <vector>
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
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0){
            return {};
        }
        return make(1,n);
    }

    vector<TreeNode*> make(int start,int ends){
        if(start > ends){
            return vector<TreeNode*>{nullptr};
        }
        vector<TreeNode*> ans;
        for(int i = start;i <= ends;i ++){
            vector<TreeNode*> leftNodes = make(start,i-1);
            vector<TreeNode*> rightNodes = make(i+1,ends);
            for(auto ii:leftNodes){
                for(auto jj:rightNodes){
                    TreeNode* head = new TreeNode(i);
                    head->left = ii;
                    head->right = jj;
                    ans.push_back(head);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution Solution1;
    Solution1.generateTrees(5);
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* buildTree(vector<int> in, vector<int> pt) {
        //中序 后序
        if (in.empty()) return nullptr;
        auto root = new TreeNode(pt[pt.size()-1]);
        //cout<<root->val<<endl;
        auto in_mid = find(begin(in), end(in), root->val), pt_mid = next(begin(pt),  in_mid - begin(in));
        root->left = buildTree(vector<int>(begin(in), in_mid), vector<int>(begin(pt), pt_mid));
        root->right = buildTree(vector<int>(next(in_mid), end(in)), vector<int>(pt_mid, end(pt)-1));
        return root;

    }
};

int main(){

    int in[5] = {9,3,15,20,7};
    int po[5] = {9,15,7,20,3};
//通过数组a的地址初始化，注意地址是从0到5（左闭右开区间）

    vector<int> preorder(in,in+5);
    vector<int> inorder(po,po+5);

    Solution Solution1;
    Solution1.buildTree(preorder,inorder);

return 0;
}

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

    TreeNode* buildTree(vector<int> pr, vector<int> in) {
        if (pr.empty()) return nullptr;
        auto root = new TreeNode(pr[0]);
        auto in_mid = find(begin(in), end(in), root->val), pr_mid = next(begin(pr),  1 + in_mid - begin(in));
        root->left = buildTree(vector<int>(next(begin(pr)), pr_mid), vector<int>(begin(in), in_mid));
        root->right = buildTree(vector<int>(pr_mid, end(pr)), vector<int>(next(in_mid), end(in)));
        return root;
    }
};

int main(){

    int pr[5] = {3,9,20,15,7};
    int in[5] = {9,3,15,20,7};
//通过数组a的地址初始化，注意地址是从0到5（左闭右开区间）

    vector<int> preorder(pr,pr+5);
    vector<int> inorder(in,in+5);
    for(auto i : preorder){
        cout<<i<<" ";
    }
    cout<<endl;;
    cout<< * next(begin(preorder),3)<<endl;
    //Solution Solution1;
    //Solution1.buildTree(preorder,inorder);

return 0;
}

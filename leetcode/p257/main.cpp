#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> ret;
    vector<string> binaryTreePaths(TreeNode* root) {
        findw(root,"");
        return ret;
    }
    string int_str(int a){
        stringstream ss;
        ss<<a;
        return ss.str();
    }
    void findw(TreeNode* root,string temp){
        if(!root){
            return;
        }else if(!root->left && !root->right){
            temp += int_str(root->val);
            ret.push_back(temp);
            return;
        }else{
            temp += int_str(root->val) + "->" ;
            if(root->left){
                findw(root->left,temp);
            }
            if(root->right){
                findw(root->right,temp);
            }
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

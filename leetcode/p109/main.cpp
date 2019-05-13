#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dispL(ListNode* head){
        ListNode* temp = head;
        cout<<endl;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int cnt = 0;
        ListNode *temp = head;
        if(head==nullptr){
            return nullptr;
        }
        while(temp){
            cnt ++;
            temp = temp->next;
        }
        temp = head;
        for(int i=0;i< cnt/2 ;i++){
            temp = temp->next;
        }
        //debug(temp->val);

        TreeNode* father = new TreeNode(temp->val);
        if(cnt>=2){
            ListNode *temp1 = head;
            for(int i=0;i<cnt/2-1;i++){
                temp1 = temp1->next;
            }
            //debug(temp1->val)
            temp1->next = nullptr;
            father->left = sortedListToBST(head);
        }else{
            father->left = nullptr;
        }
        if(temp->next){
            //debug(temp->next->val);
            father->right = sortedListToBST(temp->next);
        }else{
            father->right = nullptr;
        }

        return father;
    }
};

int main()
{
    ListNode* p = nullptr;
    p = new ListNode(0);
    ListNode* head = p;

    for(int i=1;i<10;i++){
        p->next = new ListNode(i);
        p = p->next;
    }

    Solution Solution1;
    Solution1.dispL(head);
    Solution1.sortedListToBST(head);
    cout << "Hello world!" << endl;
    return 0;
}

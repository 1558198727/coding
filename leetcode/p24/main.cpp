#include <iostream>

using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void disp(ListNode* head){
        ListNode* temp = head;
        cout<<endl;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        //debug(head->val);
        if(head==nullptr){
            return nullptr;
        }
        if(head->next){
            ListNode* hnext = head->next;
            //debug(head->val);
            //debug(head->next->val);
            head->next = swapPairs(hnext->next);
            hnext->next = head;
            return hnext;
        }else{
            return head;
        }
    }
};

int main()
{
    ListNode* p = nullptr;
    p = new ListNode(0);
    ListNode* head = p;

    for(int i=1;i<9;i++){
        p->next = new ListNode(i);
        p = p->next;
    }
    Solution Solution1;
    head = Solution1.swapPairs(head);
    Solution1.disp(head);
    return 0;
}

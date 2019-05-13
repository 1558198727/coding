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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        if(head->val == head->next->val){
            ListNode* temp = head;
            while(temp->next && temp->val == temp->next->val){
                temp = temp->next;
            }
            head = deleteDuplicates(temp->next);
        }else{
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
};

int main()
{
    ListNode* p = nullptr;
    p = new ListNode(1);
    ListNode* head = p;

    for(int i=2;i<6;i++){
        p->next = new ListNode(i);
        p = p->next;
        p->next = new ListNode(i);
        p = p->next;
        p->next = new ListNode(i);
        p = p->next;
    }
    Solution Solution1;
    Solution1.disp(head);
    head = Solution1.deleteDuplicates(head);
    Solution1.disp(head);
    return 0;
}


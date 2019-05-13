#include <iostream>
#include <stack>
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
        ListNode*temp=head;
        while(temp){
            if(temp->next){
                ListNode*tnext = temp->next;
                if(tnext->val == temp->val){
                    temp->next = tnext->next;
                }else{
                    temp = temp->next;
                }

            }else{
                break;
            }
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

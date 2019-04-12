#include <iostream>
#include <string>
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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        ListNode* temp = head;
        stack<ListNode*>st;
        int kk = k;
        while(temp && kk){
            st.push(temp);
            //debug(temp->val);
            temp = temp->next;
            kk--;
        }

        if(kk==0){
            ListNode* tail = temp;
            head = new ListNode(0);
            temp = head;
            while(!st.empty()){
                temp->next = st.top();
                st.pop();
                temp = temp->next;
            }
            temp->next = reverseKGroup(tail,k);
            return head->next;
        }
        //if()
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
    }
    Solution Solution1;
    head = Solution1.reverseKGroup(head,3);
    Solution1.disp(head);
    return 0;
}

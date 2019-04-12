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

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==nullptr){
            return nullptr;
        }
        stack<ListNode*>st;
        ListNode* s,*e;
        int cnt = 0;
        ListNode*temp = new ListNode(0);
        temp->next = head;
        head = temp;
        e = head;
        while(e && cnt<=n){
            if(cnt==m-1){
                s = e;
            }
            if(cnt>=m && cnt <=n){
                st.push(e);
                //debug(e->val);
            }
            cnt++;
            e = e->next;
        }
        //debug(e->val)
        while(!st.empty()){
            s->next = st.top();
            //debug(st.top()->val);
            st.pop();
            s = s->next;
        }
        s->next = e;
        //disp(head);
        return head->next;
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
    Solution1.disp(head);
    head = Solution1.reverseBetween(head,2,4);
    Solution1.disp(head);
    return 0;
}

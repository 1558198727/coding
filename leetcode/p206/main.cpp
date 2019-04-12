#include <iostream>
#include <stack>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
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

    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }else if(head->next==nullptr){
            return head;
        }else{

            ListNode* re = reverseList(head->next);
            ListNode*temp = re;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = head;
            head->next = nullptr;
            return re;

        }
    }
};
*/

/*
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

    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        stack<ListNode*>st;
        while(head){
            //debug(head->val);
            st.push(head);
            head = head->next;
        }
        head = new ListNode(0);
        ListNode*temp = head;
        while(!st.empty()){
            //debug(temp->val);
            temp->next = st.top();
            st.pop();
            temp = temp->next;
        }
        temp->next = nullptr;
        //disp(head);
        return head->next;
    }
};
*/

//µü´ú
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

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode*p = head->next,*q;
        head->next = nullptr;
        while(p){
            q = p->next;
            p->next = head;
            head = p;
            p = q;
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
    }
    Solution Solution1;
    Solution1.disp(head);
    head = Solution1.reverseList(head);
    Solution1.disp(head);
    return 0;
}

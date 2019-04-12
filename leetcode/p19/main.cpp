#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sum = 0;
        ListNode* t = head;
        while(t){
            sum += 1;
            t = t->next;
        }
        t = head;
        if(sum == n){
            return head->next;
        }
        for(int i=0;i<sum-n-1;i++){
           t = t->next;
        }
        t->next = t->next->next;
        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

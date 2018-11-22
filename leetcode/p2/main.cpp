#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int jin=0;
        ListNode *ret;
        ListNode *temp;
        ListNode *cur;
        ret = temp = cur = new ListNode(-1);
        while(l1 && l2){
            int he = l1->val + l2->val + jin;
            if(he > 9){
                jin = 1;

            }else{
                jin = 0;
            }

            temp = new ListNode(he%10);
            cur ->next = temp;
            cur = cur ->next;
        }
        ret = ret->next;
        return ret;
    }
};


int main()
{
    Solution Solution1;
    return 0;
}

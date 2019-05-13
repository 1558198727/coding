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
        return add(l1,l2,0);
    }
    ListNode* add(ListNode* l1, ListNode* l2,int jin){
        if(l1 && l2){
            if(l1->val + l2->val + jin >= 10 ){
                l1->val = (l1->val + l2->val +jin ) %10;
                jin = 1;
            }else{
                l1->val = (l1->val + l2->val +jin ) %10;
                jin = 0;
            }
            l1->next = add(l1->next,l2->next,jin);
            return l1;

        }else if(l1){
            if( l1->val + jin < 10){
                l1->val = l1->val + jin;
                return l1;
            }else{
                l1->val = (l1->val + jin)%10;
                l1->next = add(l1->next,l2,1);
                return l1;
            }

        }else if(l2){
            if( l2->val + jin < 10){
                l2->val = l2->val + jin;
                return l2;
            }else{
                l2->val = (l2->val + jin)%10;
                l2->next = add(l1,l2->next,1);
                return l2;
            }
        }else{
            if(jin){
                return new ListNode(1);
            }else{
                return nullptr;
            }
        }
        return nullptr;
    }
};


int main()
{
    Solution Solution1;
    return 0;
}

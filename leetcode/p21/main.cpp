#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *cur,*ret;
        if(l1->val<l2->val){
            ret = l1;
            l1 = l1->next;
        }else{
            ret = l2;
            l2 = l2->next;
        }
        cur = ret;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else if(l1->val < l2->val){
                cur->next = l2;
                l2 = l2->next;
            }
        }
        if(l1) cur->next=l1;
        else if(l2) cur->next=l2;
        return ret;
    }
};

int main()
{
    Solution Solution1;
    Solution1.mergeTwoLists("MCMXCIV");
    return 0;
}


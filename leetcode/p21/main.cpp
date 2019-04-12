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
         if(l1==nullptr && l2==nullptr){
            return nullptr;
        }else if(l1==nullptr){
            return l2;
        }else if(l2==nullptr){
            return l1;
        }
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l2->next,l1);
            return l2;
        }
    }

};

int main()
{
    Solution Solution1;
    Solution1.mergeTwoLists("MCMXCIV");
    return 0;
}


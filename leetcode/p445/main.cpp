#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int len1 = 0;
    int len2 = 0;
    int jin = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        for(;l1;){
            l1 = l1->next;
            len1 ++;
        }
        for(;l2;){
            l2 = l2->next;
            len2 ++;
        }

    }
    ListNode* add(int s1,int s2,ListNode* l1, ListNode* l2){
        if(jin){

        }
        if(len1-s1 > len2 - s2){
            l1 = add( s1+1,s2,l1->next,l2);
            if( l1->val + jin){

            }
            return l1;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

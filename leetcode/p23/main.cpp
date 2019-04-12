#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
class Solution {
public:
    static bool cmp(ListNode*a,ListNode*b){
        return a->val > b->val;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists){
        ListNode*head = new ListNode(0);
        ListNode*rethead = head;
        //去掉空指针
        vector<ListNode*>::iterator it;
        for(it=lists.begin(); it!=lists.end();){
            if(*it==nullptr){
                it = lists.erase(it);
            }else{
                it++;
            }
        }
        if( lists.size()==0){
            return nullptr;
        }else if(lists.size()==1){
            return lists[0];
        }
        while(lists.size()>0){
            //构建最小堆
            make_heap(lists.begin(),lists.begin()+lists.size(),cmp);
            head->next = lists[0];
            head = head->next;
            lists[0] = lists[0]->next;
            for(it=lists.begin(); it!=lists.end();){
                if(*it==nullptr){
                    it = lists.erase(it);
                }else{
                    it++;
                }
            }
        }
        return rethead->next;
    }
};
*/

//两个两个合并
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * ret = nullptr;
        for(int i=0;i<lists.size();i++){
            ret = mergetwo(ret,lists[i]);
        }
        return ret;
    }

    ListNode*mergetwo(ListNode* a,ListNode* b){
        if(a==nullptr && b==nullptr){
            return nullptr;
        }else if(a==nullptr){
            return b;
        }else if(b==nullptr){
            return a;
        }
        if(a->val <= b->val){
            a->next = mergetwo(a->next,b);
            return a;
        }else{
            b->next = mergetwo(b->next,a);
            return b;
        }
    }
};

int main()
{
    Solution Solution1;
    vector<ListNode*> lists = {nullptr,nullptr,nullptr,nullptr};
    Solution1.mergeKLists(lists);
    return 0;
}

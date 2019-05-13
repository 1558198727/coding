#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int>qu;

    MyStack() {
        ;
    }

    /** Push element x onto stack. */
    void push(int x) {
        queue<int>temp;
        while(!qu.empty()){
            temp.push(qu.front());
            qu.pop();
        }
        qu.push(x);
        while(!temp.empty()){
            qu.push(temp.front());
            temp.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(!qu.empty()){
            int ret = qu.front();
            qu.pop();
            return ret;

        }else{
            return -1;
        }
    }

    /** Get the top element. */
    int top() {
        if(!qu.empty()){
            return qu.front();
        }else{
            return -1;
        }
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return qu.empty();
    }
};


int main()
{
    queue<int>qu;
    qu.push(12);
    cout<<qu.front()<<endl;
    cout<<qu.front()<<endl;
    return 0;
}

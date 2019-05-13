#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>st;
    MyQueue() {
        ;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int>temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!st.empty()){
            int ret = st.top();
            st.pop();
            return ret;
        }else{
            return -1;
        }
    }

    /** Get the front element. */
    int peek() {
        if(!st.empty()){
            int ret = st.top();
            return ret;
        }else{
            return -1;
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

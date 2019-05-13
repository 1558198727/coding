#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>st;
    stack<int>mst;
    MinStack() {
        ;
    }

    void push(int x) {
        st.push(x);
        if(mst.empty()){
           mst.push(x);
        }else{
            if(x<mst.top()){
                mst.push(x);
            }else{
                mst.push(mst.top());
            }
        }
    }

    void pop() {
        if(!st.empty()){
            st.pop();
            mst.pop();
        }

    }

    int top() {
        if(!st.empty()){
            return st.top();
        }else{
            return -1;
        }
    }

    int getMin() {
        if(!mst.empty()){
            return mst.top();
        }else{
            return -1;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

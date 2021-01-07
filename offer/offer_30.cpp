//
// Created by Administrator on 2021/1/5.
//
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> A, B;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        A.push(x);
        if (B.empty() || x <= B.top()) {
            B.push(x);
        }
    }

    void pop() {
        if (!A.empty()) {
            if (A.top() == min()) {
                B.pop();
            }
            A.pop();
        }
    }

    int top() {
        return A.top();
    }

    int min() {
        if (!B.empty()) {
            return B.top();
        }
        return -1;
    }
};

int main() {
    MinStack minStack;
    minStack.push(0);
    minStack.push(1);
    minStack.push(0);
    minStack.pop();
    int min = minStack.min();
    cout << min << endl;
    return 0;
}

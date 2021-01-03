//
// Created by Administrator on 2021/1/3.
//
#include <iostream>
#include <stack>

using namespace std;

class CQueue {
    stack<int> A, B;
public:
    CQueue() {

    }

    void appendTail(int value) {
        A.push(value);
    }

    /**
     *
     * @return
     */
    int deleteHead() {
        if (!B.empty()) {
            int a = B.top();
            B.pop();
            return a;
        }
        while (!A.empty()) {
            int aa = A.top();
            A.pop();
            B.push(aa);
        }
        if (!B.empty()) {
            int a = B.top();
            B.pop();
            return a;
        }
        return -1;
    }

    void print() {
        while (!B.empty()) {
            int b = B.top();
            B.pop();
            cout << b << endl;
        }
    }
};

int main() {
    auto *cQueue = new CQueue();
    cQueue->appendTail(2);
    cQueue->appendTail(6);
    cQueue->appendTail(7);
    cQueue->deleteHead();
    cQueue->print();
    return 0;
}

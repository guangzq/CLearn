//
// Created by qiguang.zhu on 2021/1/11.
//
#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
    priority_queue<int> A;//大顶堆存较小的数
    priority_queue<int,vector<int>,greater<int>> B;//小顶堆存较大的数
public:
    /** initialize your data structure here. */
    MedianFinder() {
        A = priority_queue<int ,vector<int>,less<int>>();
        B = priority_queue<int, vector<int>, greater<int>>();
    }

    void addNum(int num) {
        if (A.size() != B.size()) {
            A.push(num);
            int aTop = A.top();
            A.pop();
            B.push(aTop);
        }else {
            B.push(num);
            int bTop =  B.top();
            B.pop();
            A.push(bTop);
        }
    }

    double findMedian() {
        if (A.size() != B.size()) {
            return A.top();
        }else {
            return (double)(A.top() + B.top()) / 2;
        }
    }
};

int main() {
    MedianFinder finder;
    finder.addNum(2);
    cout<<finder.findMedian()<<endl;
    finder.addNum(6);
    finder.addNum(4);
    cout<<finder.findMedian()<<endl;
    finder.addNum(5);
    finder.addNum(1);//1 2 4 5 6
    cout<<finder.findMedian()<<endl;
    return 0;
}


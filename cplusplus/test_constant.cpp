//
// Created by qiguang.zhu on 2020/9/29.
//
#include <iostream>

using namespace std;

class Clock {
private:
    const int h;
    const int m;
    int const s;
    static const int x;
public:
    Clock(int a, int b, int c) : h(a), m(b), s(c) {
        cout << "constructor" << endl;
    }

    int getX() const {
        //x=66;
        cout << x << endl;
        return x;
    }
};

const int Clock::x = 99;

int main() {
    Clock A(1, 2, 3);
    A.getX();
    return 0;
}


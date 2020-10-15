//
// Created by qiguang.zhu on 2020/10/15.
//
#include <iostream>

using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    virtual double area() {
        return 0;
    }
};
class Circle: public Point {
private:
    int x1;
    int x2;
    int x3;
public:
    Circle(int d,int e, int f) {
        this ->x1 = d;
        x2 = e;
        x3 = f;
    }
    double area() {
        return 3.14 * x1 * x2;
    }
};

int main() {
    Point A(10, 11);
    cout<<A.area()<<endl;
    Circle B(2, 6, 7);
    cout<<B.area()<<endl;
    Point *D;
    D = &B;
    cout<<D->area()<<endl;
    Point &p = B;
    cout<<p.area()<<endl;
    return 0;
}


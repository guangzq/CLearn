//
// Created by qiguang.zhu on 2020/9/28.
//
#include <iostream>
#include <math.h>

using namespace std;

class Point {
private:
    double x;
    double y;
public:
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    friend class Tool;
};

class Tool {
public:
    double getD(Point &point) {
        double l = sqrt(point.x * point.x + point.y * point.y);
        cout<<l<<endl;
        return l;
    }
};

int main() {
    Point C(1.0, 2.0);
    Tool tool;
    tool.getD(C);
    return 0;
}

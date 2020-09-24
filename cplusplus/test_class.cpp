//
// Created by qiguang.zhu on 2020/9/24.
//
#include <iostream>

using namespace std;

class Person {
public:
    int num;
    char name[100];
    double score;
    int print();
//    int print() {
//        cout << num << " " << name << " " << score << endl;
//        return 0;
//    }
};
int Person::print() {
    cout << num << " " << name << " " << score << endl;
    return 0;
}

//
// Created by qiguang.zhu on 2020/9/28.
//
#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    char name[100];
    int num;
    double score;
public:
    Student(char *n, int num1, double score1);

    ~Student();

    void print();

};

Student::Student(char *n, int num1, double score1) {
    strcpy(name, n);
    num = num1;
    score = score1;
    cout << name << " " << num << " " << score << " constructor" << endl;
}

Student::~Student() {
    cout << name << " " << num << " " << score << " destructor" << endl;
}

void Student::print() {
    cout << name << " " << num << " " << score << endl;
}

int main() {
    Student A("this is A", 01, 98.7);
    Student B("this is B", 02, 98.6);
    return 0;
}


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
    void print();

};
Student::Student(char *n, int num1, double score1) {
    strcpy(name, n);
    num = num1;
    score = score1;
}
void Student::print() {
    cout<<name<<" "<<num<<" "<<score<<endl;
}
int main() {
    Student A("xiaoming", 01, 98.7);
    A.print();
    return 0;
}


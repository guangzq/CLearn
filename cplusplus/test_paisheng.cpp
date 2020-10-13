//
// Created by qiguang.zhu on 2020/10/13.
//
#include <iostream>
#include <cstring>
using namespace std;
class Person{
public:
    char name[100];
    int sex;
public:
    Person(char *name,int sex) {
        strcpy(this->name, name);
        this->sex = sex;
        cout<<"Person contructor"<<endl;
    }
};
class Student: public Person {
public:
    Student(char *n, int o) : Person(n, o) {
        cout<<"Student contructor"<<endl;
    }
};
int main() {
    Student A("xiaoming", 1);
    return 0;
}


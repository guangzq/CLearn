//
// Created by qiguang.zhu on 2020/9/29.
//
#include <iostream>
#include <cstring>
using namespace std;
class Person {
protected:
    char name[100];
    int sex;
public:
    void setName(char *n) {
        strcpy(name, n);
    }
};
class Student: public Person {
public:
    void setSex(int s) {
        this->sex = s;
    }
    void getInfo() {
        cout<<name<<" "<<sex<<endl;
    }
};
int main() {
    Student A;
    A.setName("zhangsan");
    A.setSex(0);
    A.getInfo();
    return 0;
}


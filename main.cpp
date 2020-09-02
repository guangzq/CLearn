#include <iostream>

using namespace std;

class Student {
public:
    string name;
    int age;
};

class Person {
public:
    int height;
};

class Maliu : Student, Person {
public:
    int getValue() {
        height = 3;
        age = 2;
        return age * height;
    }
};

int main() {
    Student student;
    Maliu maliu;
    student.age = 20;
    student.name = "zhangsan";
    cout << maliu.getValue() << endl;
    return 0;
}

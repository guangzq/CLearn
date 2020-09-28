//
// Created by qiguang.zhu on 2020/9/28.
//
#include <iostream>
#include <cstring>

using namespace std;

class Circle {
private:
    double R;
    char *n;
public:
    Circle(double R, char *num);

    ~Circle();
};

Circle::Circle(double R, char *num) {
    cout << "constructor" << endl;
    this->R = R;
    this->n = new char[strlen(num) + 1];
    strcpy(n, num);
    cout<<R<<" "<<n<<endl;
}

Circle::~Circle() {
    delete n;
    cout<<"destructor "<<n<<endl;
}

//Circle::Circle(Circle &circle) {
//    cout<<"copy constructor"<<endl;
//    this->R = circle.R;
//}
int main() {
    Circle A(2, "this is A");
    Circle B(2, "this is A");
//    Circle B(A);
    return 0;
}


//
// Created by qiguang.zhu on 2020/9/23.
//
#include <iostream>

using namespace std;

int main() {
    int id;
    char sex;
    double score1 = 0, score2 = 0, score3 = 0;
    bool isNO1;
    cout << "please input ID, 'M' or 'W', score1, score2, score3" << endl;
    cin >> id >> sex >> score1 >> score2 >> score3;
    isNO1 = score1 > 12;
    cout << "ID=" << id << ",sex=" << sex << ",total=" << score1 + score2 + score3 <<",isNo1="<<isNO1<<endl;
    return 0;
}


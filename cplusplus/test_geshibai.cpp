//
// Created by qiguang.zhu on 2020/9/23.
//
#include <iostream>

using namespace std;
/**
 * 判断一个数是否为"水仙花数"，所谓"水仙花数"是指这样的一个数：首先是一个三位数，
 * 其次，其各位数字的立方和等于该数本身。例如：371是一个"水仙花数"，371=3^3+7^3+1^3.
 * @return
 */
int main() {
    int a, ge, shi, bai;
    cout << "input num >100" << endl;
    cin >> a;
    ge = a % 10;
    shi = a % 100 / 10;
    bai = a / 100;
    cout << "ge=" << ge << ",shi=" << shi << ",bai=" << bai << endl;
    if ((ge * ge * ge + shi * shi * shi + bai * bai * bai) == a) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}


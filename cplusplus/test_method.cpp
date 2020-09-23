//
// Created by qiguang.zhu on 2020/9/23.
//
#include <iostream>
#include <cstring>
using namespace std;
/**
 * 反转字符串
 * @param a 原字符串
 * @param b 反转后的字符串
 * @return
 */
int reverse(char a[], char b[]) {
    int n = strlen(a);
    int i = 0;
    while (a[i] != '\0') {
        b[n - i - 1] = a[i];
        i++;
    }
    b[n] = '\0';
    return 0;
}

int main() {
    char a[100];
    char b[100];
    cin >> a;
    reverse(a, b);
    cout << b << endl;
    return 0;
}


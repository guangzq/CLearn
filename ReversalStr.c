//
// Created by qiguang.zhu on 2020/7/8.
//
#include <stdio.h>
#include <string.h>

/**
 * 字符串反转（利用指针）
 * @param str
 */
void reverse(char *str);

void reverse(char *str) {
    char *first = str;//指向字符串的首地址
    char *end = strlen(str) + str - 1;//指向字符串的尾地址
    //交换首地址和尾地址对应的值
    while (first < end) {
        char tmp = *first;
        *first = *end;
        *end = tmp;
        first++;
        end--;
    }
}

int main() {
    char str[] = "abcdefg";
    printf("ori->%s\n", str);
    reverse(str);
    printf("reverse->%s", str);
    return 0;
}


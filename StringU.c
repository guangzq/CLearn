//
// Created by qiguang.zhu on 2020/7/16.
//
#include <stdio.h>
#include <string.h>

#define ARR_LENGTH 50
/**
 * C语言实现strcpy（字符串复制）、strcat（字符串链接）、
 * strstr（字符串包含）、strchr（字符出现位置）、memcpy（拷贝）。主要熟悉指针高级用法。
 */

/**
 * 复制
 * @param destStr 目标strng
 * @param srcStr 原string
 * @return
 */
char *my_strcpy(char *destStr, const char *srcStr) {
    if (destStr == NULL || srcStr == NULL) return NULL;
    if (destStr == srcStr) return destStr;
    char *tmp = destStr;
    while (*srcStr != '\0') {
        *destStr++ = *srcStr++;//地址自增，知道遇到字符串结束符NUL,即'\0'
    }
    return tmp;
}

/**
 * 链接字符串（思路：先取目标字符串最后一个字符，然后再后面不断追加）
 * @param destStr
 * @param srcStr
 * @return
 */
char *my_strcat(char *destStr, const char *srcStr) {
    if (destStr == NULL || srcStr == NULL) return NULL;
    while (*destStr != '\0') {
        destStr++;//因为字符串指向的是首地址
    }
    while ((*destStr++ = *srcStr++) != '\0') {
    }
    return destStr;
}

/**
 * 字符串包含
 * @param str
 * @param subStr
 * @return
 */
const char *my_strstr(const char *str, const char *subStr) {
    const char *str1;
    const char *subStr1;
    while (*str) {
        str1 = str;
        subStr1 = subStr;
        while (*str1++ == *subStr1++) {
            if (!*subStr1) {//到了子串的最后位置
                return str;
            }
        }
        str++;
    }
    return NULL;
}

int main(void) {
    char *srcStr = "this is a string";
    char destStr[ARR_LENGTH];
    memset(destStr, 0, ARR_LENGTH);//将内存设定为指定的值
    printf("destStr %s\n", destStr);
    printf("strcpy destStr-> %s\n", my_strcpy(destStr, srcStr));
    memset(destStr, 0, ARR_LENGTH);//将内存设定为指定的值
    my_strcat(destStr, "this is a ");
    my_strcat(destStr, "string ");
    printf("strcat destStr-> %s\n", destStr);
    printf("strcat strStr-> %s\n", my_strstr(destStr, "a"));
    return 0;
}


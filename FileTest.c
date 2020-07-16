//
// Created by qiguang.zhu on 2020/7/14.
//
#include <stdio.h>

/**
 * {@link https://www.cnblogs.com/likebeta/archive/2012/06/16/2551780.html}
 * 假如数据库中有如下记录：
       43 peter
       21 Linda
       90 Jesson
       77 Donald
       ......
编写代码完成：1）从文件中读取Person对象2）将Person写入一个新文件3）对Person根据姓名排序4）释放内存5）关闭文件流
 * @return
 */

typedef struct UserInfo {
    int order;
    char *name;
};


//int main() {
//    FILE *file = fopen("../filetext", "r");
//    if (file == NULL) {
//        printf("open file error");
//        return 0;
//    }
//    int getc = fgetc(file);
//    while (getc != EOF) {
//        putchar(getc);
//        getc = fgetc(file);
//    }
//
//
//    fclose(file);
//    return 0;
//}

int main(void) {
    char *p = "abc";
    printf("%s", p);
    return 0;
}


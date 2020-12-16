//
// Created by qiguang.zhu on 2020/7/21.
//
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @author zhuqiguang
 * 38.mmap函数的熟练掌握，
 * 首先我们先建立一个测试用文件，建立了一个大小为 1KB 的文本文件 test.txt，
 * 然后使用mmap完成文件的首字节的改写，更新成JavaIloveyou。掌握3个函数的使用。
 * @return
 */
int main() {

    char data[] = "JavaIloveyou"; // this str will be inserted to the file
    int len = strlen(data);
    // 打开文件
    int fd = open("../test.txt", O_RDWR | O_CREAT, 00777);
    // lseek将文件指针往后移动 len - 1 位
    lseek(fd, len - 1, SEEK_END);
    // 预先写入一个空字符；mmap不能扩展文件长度，这里相当于预先给文件长度，准备一个空架子
    write(fd, " ", 1);
    // 建立映射
    char *buffer = (char *) mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    // 关闭文件
    close(fd);
    // 将 data 复制到 buffer 里
    memcpy(buffer, data, len);
    // 关闭映射
    munmap(buffer, len);

    return 0;
}


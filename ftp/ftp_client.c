//
// Created by qiguang.zhu on 2020/9/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define N 256

void commd_help();

void commd_exit();

void commd_ls(struct sockaddr_in, char *);

void commd_get(struct sockaddr_in, char *);

void commd_put(struct sockaddr_in, char *);

int getPortNum(char *buf);

int sockfd;

int main(int argc, char *argv[]) {
    char commd[N];
    char buffer[N];
    struct sockaddr_in addr;
    int len;
    bzero(&addr, sizeof(addr));     //将＆addr中的前sizeof（addr）字节置为0，包括'\0'
    addr.sin_family = AF_INET;      //AF_INET代表TCP／IP协议
    addr.sin_addr.s_addr = inet_addr("39.107.238.182"); //将点间隔地址转换为网络字节顺序
    addr.sin_port = htons(21);    //转换为网络字节顺序
    len = sizeof(addr);
    //创建套接字
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket Error!\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        printf("Connect Error!\n");
        exit(1);
    }

    //login
    sprintf(buffer, "USER %s\r\n", "ftptest");
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "PASS %s\r\n", "123");
    int login_size = send(sockfd, buffer, strlen(buffer), 0);
    if (login_size > 0) {
        printf("login success\n");
    }
    while (1) {
        printf("ftp>");
        bzero(commd, N);
        //fgets函数从stdin流中读取N-1个字符放入commd中
        if (fgets(commd, N, stdin) == NULL) {
            printf("Fgets Error!\n");
            return -1;
        }

        commd[strlen(commd) - 1] = '\0';    //fgets函数读取的最后一个字符为换行符，此处将其替换为'\0'

        printf("Input Command Is [ %s ]\n", commd);

        if (strncmp(commd, "help", 4) == 0) //比较两个字符串前4个字节，若相等则返回0
        {
            commd_help();
        } else if (strncmp(commd, "exit", 4) == 0) {
            commd_exit();
            exit(0);   //结束进程
        } else if (strncmp(commd, "ls", 2) == 0) {
            commd_ls(addr, commd);
        } else if (strncmp(commd, "get", 3) == 0) {
            commd_get(addr, commd);
        } else if (strncmp(commd, "put", 3) == 0) {
            commd_put(addr, commd);
        } else {
            printf("Command Is Error!Please Try Again!\n");
        }

    }
    return 0;
}

/*
**帮助信息
*/
void commd_help() {

    printf("\n=---------------------欢迎使用FTP--------------------------|\n");
    printf("|                                                           |\n");
    printf("|                 help:显示所有FTP服务器命令                 |\n");
    printf("|                                                           |\n");
    printf("|                 exit:离开FTP服务器                         |\n");
    printf("|                                                           |\n");
    printf("|                 ls : 显示FTP服务器的文件列表               |\n");
    printf("|                                                           |\n");
    printf("|                 get <file>：从FTP服务器下载文件            |\n");
    printf("|                                                           |\n");
    printf("|                 put <file>:上传文件到FTP服务器             |\n");
    printf("|                                                           |\n");
    printf("|-----------------------------------------------------------|\n");

    return;
}

/*
**退出FTP服务器
*/
void commd_exit() {
    printf("Bye!\n");
}

/*
**显示文件列表
*/
void commd_ls(struct sockaddr_in addr, char *commd) {



    //将commd指向的内容写入到sockfd所指的文件中，此处即指套接字
    if (write(sockfd, commd, N) < 0) {
        printf("Write Error!\n");
        exit(1);
    }

    while (read(sockfd, commd, N) > 0)  //从sockfd中读取N字节内容放入commd中，
    {                                   //返回值为读取的字节数
        printf(" %s ", commd);
    }
    printf("\n");

    close(sockfd);
    return;
}

/*
**实现文件的下载
*/
void commd_get(struct sockaddr_in addr, char *commd) {
    int fd;
    int sockfd;
    char buffer[N];
    int nbytes;
    //创建套接字，并进行错误检测
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket Error!\n");
        exit(1);
    }
    //connect函数用于实现客户端与服务端的连接,此处还进行了错误检测
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        printf("Connect Error!\n");
        exit(1);
    }
    //通过write函数向服务端发送数据
    if (write(sockfd, commd, N) < 0) {
        printf("Write Error!At commd_get 1\n");
        exit(1);
    }
    //利用read函数来接受服务器发来的数据
    if (read(sockfd, buffer, N) < 0) {
        printf("Read Error!At commd_get 1\n");
        exit(1);
    }
    //用于检测服务器端文件是否打开成功
    if (buffer[0] == 'N') {
        close(sockfd);
        printf("Can't Open The File!\n");
        return;
    }
    //open函数创建一个文件，文件地址为(commd+4)，该地址从命令行输入获取
    if ((fd = open(commd + 4, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
        printf("Open Error!\n");
        exit(1);
    }
    //read函数从套接字中获取N字节数据放入buffer中，返回值为读取的字节数
    while ((nbytes = read(sockfd, buffer, N)) > 0) {
        //write函数将buffer中的内容读取出来写入fd所指向的文件，返回值为实际写入的字节数
        if (write(fd, buffer, nbytes) < 0) {
            printf("Write Error!At commd_get 2");
        }
    }

    close(fd);
    close(sockfd);

    return;

}

/*
**实现文件的上传
*/
void commd_put(struct sockaddr_in addr, char *commd) {
    char buffer[N];
    //解析数据端口
//    int a,b,c,d,pa,pb,*port;
//    char ipaddr[32];
//    char *find = strrchr(buffer, '(');
//    sscanf(find, "(%d,%d,%d,%d,%d,%d)", &a, &b, &c, &d, &pa, &pb);
//    sprintf(ipaddr, "%d.%d.%d.%d", a, b, c, d);
    int port = getPortNum(buffer);
    addr.sin_port = htons(port);
//    sprintf(buffer, "PORT\r\n");
//    send(sockfd, buffer, strlen(buffer), 0);
    //创建套接字
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket Error!\n");
        exit(1);
    }
    //客户端与服务端连接
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        printf("Connect Error!\n");
        exit(1);
    }
    //login
    sprintf(buffer, "USER %s\r\n", "ftptest");
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "PASS %s\r\n", "123");
    int login_size = send(sockfd, buffer, strlen(buffer), 0);
    if (login_size > 0) {
        printf("login success\n");
    }

    //PASV
    sprintf(buffer, "PASV\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    //STOR 上传命令
    sprintf(buffer, "STOR %s\r\n", "/zqg/zqg_1055.txt");
    send(sockfd, buffer, strlen(buffer), 0);
    close(sockfd);

    return;
}


int getPortNum(char *buf) {
    int num1 = 0, num2 = 0;

    char *p = buf;
    int cnt = 0;
    while (1) {
        if (cnt == 4 && (*p) != ',') {
            num1 = 10 * num1 + (*p) - '0';
        }
        if (cnt == 5) {
            num2 = 10 * num2 + (*p) - '0';
        }
        if ((*p) == ',') {
            cnt++;
        }
        p++;
        if ((*p) == ')') {
            break;
        }
    }
    return num1 * 256 + num2;
}

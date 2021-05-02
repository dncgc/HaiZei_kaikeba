/*************************************************************************
	> File Name: 2.boy.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 02 May 2021 11:46:24 PM CST
 ************************************************************************/

#include "head.h"
//定义一个信号处理函数，处理ctrl + c信号
    //发送BYe
    //close()
    //exit()

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s ip port!\n", argv[0]);
        exit(1);
    }
    // 定义地址结构体，sockfd
    // socket()
    // connect
    // while loop
        // scanf
        // send
    return 0;
}

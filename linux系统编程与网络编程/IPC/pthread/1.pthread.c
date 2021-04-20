/*************************************************************************
	> File Name: 1.pthread.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 12 Apr 2021 07:12:03 PM CST
 ************************************************************************/

#include "head.h"

struct Arg{
    int age;
    char name[20];
};

void *print(void *arg) {
    struct Arg *argin = (struct Arg *)arg;
    printf("%s is %d years old!\n", argin->name, argin->age);
}

int main() {
    pthread_t thread;
    struct Arg arg;
    memset(&arg, 0, sizeof(arg));
    arg.age = 18;
    strcpy(arg.name, "cuiguochong");
    pthread_create(&thread, NULL, print, (void *)&arg);
    usleep(10);
    return 0;
}

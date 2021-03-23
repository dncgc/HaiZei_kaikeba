/*************************************************************************
	> File Name: 5.nonblock.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 23 Mar 2021 04:00:25 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    int age1 = 0, age2 = 0;
    make_nonblock(0);
    int ret = scanf("%d", &age1);
    if (ret < 0) {
        if (errno == EAGAIN) {
            printf("EAGAIN\n");
        }
        perror("scanf");
    }
    make_block(0);
    scanf("%d", &age2);
    printf("suyelu is %d  <%d> years old!\n", age1, age2);
    return 0;
}

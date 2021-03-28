/*************************************************************************
	> File Name: my_shm.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 28 Mar 2021 03:39:58 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    int fd, pro_id = 1, shm_id;
    key_t key;
    if ((fd = open(".my_shm", O_CREAT | O_TRUNC | O_RDWR)) < 0) {
        perror("open");
        exit(1);
    }
    key = ftok(".my_shm", pro_id);
    if ((shm_id = shmget(key, 4096, PIC_CREAT | PIC_EXCL)) < 0) {
        perror("shmget");j
        exit(1);
    }
    return 0;
}

/*************************************************************************
	> File Name: 1.shm.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 28 Mar 2021 03:51:08 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    int shmid;
    char *share_memory = NULL;
    key_t key = ftok("./1.shm.c", 328);
    if ((shmid = shmget(key, 4096, IPC_CREAT | IPC_EXCL | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((share_memory = shmat(shmid, NULL, 0)) == NULL) {
        perror("shmat");
    }
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }

    if (pid) {
        while (1) {
            scanf("%[^\n]s", share_memory);
            getchar();
        }
    } else {
        while (1) {
            if (strlen(share_memory)) printf("<Child> : %s\n", share_memory);
            memset(share_memory, 0, 4096);
        }
    }
    return 0;
}

/*************************************************************************
	> File Name: 5.sem.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 07 Apr 2021 08:08:58 PM CST
 ************************************************************************/

#include "head.h"
#define INS 3

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                (Linux-specific) */
};

int create_sem(const char *path, int project_id) {
    int sem_id;
    key_t key = ftok(path, project_id);
    if((sem_id = semget(key, 1, IPC_CREAT | 0666)) < 0) {
        return -1;
    }
    return sem_id;
}

int init_sem(int sem_id, int sem_num, int value) {
    union semun arg;
    arg.val = value;
    return semctl(sem_id, sem_num, SETVAL, arg);
}

int P(int sem_id, int sem_num) {
    struct sembuf sbuff;
    sbuff.sem_num = sem_num;
    sbuff.sem_op = -1;
    sbuff.sem_flg = SEM_UNDO;
    if(semop(sem_id, &sbuff, 1) < 0) {
        return -1;
    }
    return 0;
}

int V(int sem_id, int sem_num) {
    struct sembuf sbuff;
    sbuff.sem_num = sem_num;
    sbuff.sem_op = 1;
    sbuff.sem_flg = SEM_UNDO;
    if(semop(sem_id, &sbuff, 1) < 0) {
        return -1;
    }
    return 0;
}

int main(int argc, char **argv) {
    int sem_id;
    if ((sem_id = create_sem(".", 2021)) < 0) {
        perror("create_sem");
        exit(1);
    }
    if (argc > 1) {
        if (init_sem(sem_id, 0, INS) < 0) {
            perror("init");
            exit(1);
        }
    }
    int cnt = 0;
    while(1) {
        if (P(sem_id, 0) < 0) {
            perror("P");
            exit(1);
        }
        sleep(3);
        cnt++;
        if (V(sem_id, 0) < 0) {
            perror("V");
            exit(1);
        }
        printf("This is %dth of mine!\n", cnt);
    }

    return 0;
}

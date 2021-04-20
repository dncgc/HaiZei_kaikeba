/*************************************************************************
	> File Name: 3.shm_cond_mutex.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 28 Mar 2021 04:36:47 PM CST
 ************************************************************************/
 //Usage : ./a.out -t 1|2 -m msg
#include "head.h"

struct SHM {
    int flag;
    int type;
    char msg[512];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

int main(int argc, char **argv) {
    int opt;
    struct SHM shm_data;
    memset(&shm_data, 0, sizeof(shm_data));
    if (argc != 5) {
        fprintf(stderr, "Usage : %s -t 1|2 -m msg.\n", argv[0]);
        exit(1);
    }
    while ((opt = getopt(argc, argv, "t:m:")) != -1) {
        switch (opt) {
            case 't':
                shm_data.type = atoi(optarg);
                break;
            case 'm':
                strcpy(shm_data.msg, optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -t 1|2 -m msg.\n", argv[0]);
                exit(1);
        }
    }
    key_t key;
    int shmid;
    struct SHM *share_memory = NULL;
    key = ftok("./2.shm_1.c", 328);
    if ((shmid = shmget(key, sizeof(struct SHM), IPC_CREAT | IPC_EXCL | 0600)) < 0) {
        if (errno == EEXIST) {
            printf("shm exist!\n");
            if ((shmid = shmget(key, sizeof(struct SHM), 0600)) < 0) {
                perror("shmget2");
                exit(1);
            }
        } else {
            perror("shmget1");
            exit(1);
        }
    } else {
        printf("Success!\n");
    }
    if ((share_memory = (struct SHM *)shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
        exit(1);
    }
    if (shm_data.type == 1) {
        pthread_mutexattr_t mattr;
        pthread_mutexattr_init(&mattr);
        pthread_mutexattr_setpshared(&mattr, 1);

        pthread_condattr_t cattr;
        pthread_condattr_init(&cattr);
        pthread_condattr_setpshared(&cattr, 1);

        pthread_mutex_init(&share_memory->mutex, &mattr);
        pthread_cond_init(&share_memory->cond, &cattr);
    }
    if (shm_data.type == 1) {
        while (1) {
            char buffer[512] = {0};
            printf("Input : \n");
            scanf("%[^\n]s", buffer);
            getchar();
            if (strlen(buffer)) {
                pthread_mutex_lock(&share_memory->mutex);
                strcpy(share_memory->msg, buffer);
                pthread_mutex_unlock(&share_memory->mutex);
                pthread_cond_signal(&share_memory->cond);
            }
        }
    } else {
        while (1) {
            pthread_mutex_lock(&share_memory->mutex);
            pthread_cond_wait(&share_memory->cond, &share_memory->mutex);
            printf("\033[32m❤ \033[0m : %s\n", share_memory->msg);
            memset(share_memory->msg, 0, sizeof(share_memory->msg));
            pthread_mutex_unlock(&share_memory->mutex);
        }
    }

    return 0;
}

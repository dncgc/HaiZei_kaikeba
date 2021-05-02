/*************************************************************************
	> File Name: 2.multi_thread_add.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 27 Apr 2021 04:09:07 PM CST
 ************************************************************************/

#include "head.h"
#define INS 50
#define MAX 1000

int now, sum;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *work(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (now > MAX) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        sum += now;
        usleep(15);
        now++;
        pthread_mutex_unlock(&mutex);
   }
}

int main() {
    pthread_t *tid = calloc(INS, sizeof(pthread_t));
    for (int i = 0; i < INS; i++) {
        pthread_create(&tid[i], NULL, work, NULL);
    }
    for (int i = 0; i < INS; i++) {
        pthread_join(tid[i], NULL);
    }
    printf("%d\n", sum);
    return 0;
}

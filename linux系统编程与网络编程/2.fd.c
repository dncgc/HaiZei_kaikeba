/*************************************************************************
	> File Name: 2.fd.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 19 Mar 2021 06:14:52 PM CST
 ************************************************************************/

#include "head.h"

int main(int argc, char **argv) {
    int fd, fd2;
    
    if (argc != 3) {
        fprintf(stderr, "Usage : %s file1 file2\n", argv[0]);
        exit(1);
    }
    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        perror("open");
        exit(1);  //等价于 return 1;
    }

    if ((fd2 = open(argv[2], O_CREAT | O_RDWR, 0666)) < 0) {
        perror("open");
        exit(1);
    }

    while (1) {
        char buff[512] = {0};
        ssize_t size = read(fd, buff, sizeof(buff));
        printf("%s", buff);
        write(fd2, buff, size);
        if (size <= 0) {
            break;
        }
    }
    close(fd);
    close(fd2);

    return 0;
}

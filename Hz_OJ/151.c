/*************************************************************************
	> File Name: 151.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 18 Sep 2020 03:19:15 PM CST
 ************************************************************************/

#include <stdio.h>

int guess(char ch1, char ch2) {
    if (ch1 == ch2) return 0;
    else if ((ch1 == 'Y' && ch2 == 'H') || (ch1 == 'O' && ch2 == 'Y') || (ch1 == 'H' && ch2 == 'O'))
        return 1;
    else return -1;
}

int main() {
    char ming[3] = {0}, hua[3] = {0};
    scanf("%c %c\n%c %c", &ming[0], &ming[1], &hua[0], &hua[1]);
    if (guess(ming[0], hua[0]) == 1) {
        if (guess(ming[0], hua[1]) != -1 )  printf("MING\n");
        else {
            if (guess(ming[1], hua[1]) == 1) printf("MING\n");
            else printf("LIHUA\n");
        }
    } else if (guess(ming[0], hua[0]) == 0) {
        if (guess(ming[1], hua[1]) == 1) printf("MING\n");
        else if (guess(ming[1], hua[1]) == -1) printf("LIHUA\n");
        else printf("TIE\n");
    } else {
        if (guess(ming[1], hua[0]) != 1) printf("LIHUA\n");
        else {
            if (guess(ming[1], hua[1]) != -1) printf("MING\n");
            else printf("LIHUA\n");
        }
    }
    return 0;
}

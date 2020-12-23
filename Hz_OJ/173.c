/*************************************************************************
	> File Name: 173.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Sep 2020 04:46:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    int i = 0, letter = 0, num = 0, space = 0, other = 0;
    while (~scanf("%c", str + i)) {
        if ((*(str + i) >= 65 && *(str + i) <= 90) || (*(str + i) >= 97 && *(str + i) <= 122))
            letter++;
        else if (*(str + i) >= 48 && *(str + i) <= 57)
            num++;
        else if (*(str + i) == ' ')
            space++;
        else other++;
        i++;
    }
    printf("%d %d %d %d\n", letter, num, space, other);
    return 0;
}

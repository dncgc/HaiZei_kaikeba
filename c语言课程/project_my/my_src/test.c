/*************************************************************************
	> File Name: test.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月16日 星期五 14时46分20秒
 ************************************************************************/

#include <stdio.h>
#include <test.h>

int RUN_ALL_TESTS() {
    return 0;
}

int EXPECT_EQ(int sum, int c) {
    return sum == c ? 0 : 1;
}

int ASSERT_EQ(int sum, int c) {
    return sum == c ? 0 : 1;
}

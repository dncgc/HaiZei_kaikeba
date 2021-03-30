/*************************************************************************
	> File Name: main.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月14日 星期三 20时24分18秒
 ************************************************************************/

#include <stdio.h>
#include <haizei/test.h>

int add(int a, int b) {
    return a + b;
}

TEST(func, add) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_NE(add(3, 2), 6);
    EXPECT_BN(add(1, 2), 2);
}

TEST(func2, add) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_NE(add(3, 2), 6);
    EXPECT_BN(add(1, 2), 3);
    EXPECT_SN(add(1, 2), 4);
    EXPECT_BE(add(1, 2), 4);
}

TEST(func3, add) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_NE(add(3, 2), 5);
    EXPECT_BN(add(1, 2), 2);
    EXPECT_SN(add(1, 2), 4);
    EXPECT_BE(add(1, 2), 3);
    EXPECT_SE(add(3, 4), 8);
}
int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}

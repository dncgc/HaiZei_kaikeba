/*************************************************************************
	> File Name: main.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月14日 星期三 20时24分18秒
 ************************************************************************/

#include <stdio.h>
//#include <gtest/gtest.h> 
#include <haizei/test.h>

int add(int a, int b) {
    return a + b;
}

TEST(testfunc, add) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_EQ(add(3, 2), 5);
//    ASSERT_EQ(add(1, 2), 4);
    EXPECT_EQ(add(1, 2), 3);
}

TEST(testfunc, add2) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_EQ(add(3, 2), 5);
//    ASSERT_EQ(add(1, 2), 4);
    EXPECT_EQ(add(1, 2), 3);
}

TEST(test, funcadd) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_EQ(add(1, 2), 5);
//    ASSERT_EQ(add(1, 2), 4);
    EXPECT_EQ(add(1, 2), 3);
}
int main(int argc, char *argv[]) {
    //testing::InitGoogleTest(&argc, argv); //
    return RUN_ALL_TESTS();
    //return 0;
}

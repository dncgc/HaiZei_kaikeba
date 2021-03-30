/*************************************************************************
	> File Name: test.h
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月16日 星期五 18时19分40秒
 ************************************************************************/
//__attribute__宏为后面的函数加一个属性，constructor使其优于主函数执行
#ifndef _TEST_H
#define _TEST_H

#define TEST(a, b)\
void a##_haizei_##b();\
__attribute__((constructor))\
void add##_haizei_##a##_haizei_##b() {\
    add_function(a##_haizei_##b, #a "." #b);\
}\
void a##_haizei_##b()
//void a##b() //可能出现重定义的错误

#define EXPECT_EQ(a, b) printf("\033[32m[-----------]\033[0m %s == %s %s\n", #a, #b, (a) == (b) ? "\033[32mTrue\033[0m" : "\033[31mFalse\033[0m");\
success_cnt(a, b, (char *)"==");
#define EXPECT_NOTEQ(a, b) printf("\033[32m[-----------]\033[0m %s != %s %s\n", #a, #b, (a) != (b) ? "\033[32mTrue\033[0m" : "\033[31mFalse\033[0m");\
success_cnt(a, b, (char *)"!=");
#define EXPECT_BIG(a, b) printf("\033[32m[-----------]\033[0m %s > %s %s\n", #a, #b, (a) > (b) ? "\033[32mTrue\033[0m" : "\033[31mFalse\033[0m");\
success_cnt(a, b, (char *)">");
#define EXPECT_SMALL(a, b) printf("\033[32m[-----------]\033[0m %s < %s %s\n", #a, #b, (a) < (b) ? "\033[32mTrue\033[0m" : "\033[31mFalse\033[0m");\
success_cnt(a, b, (char *)"<");
#define EXPECT_BIGEQ(a, b) printf("\033[32m[-----------]\033[0m %s >= %s %s\n", #a, #b, (a) >= (b) ? "\033[32mTrue\033[0m" : "\033[31mFalse\033[0m");\
success_cnt(a ,b, (char *)">=");
#define EXPECT_SMALLEQ(a, b) printf("\033[32m[-----------]\033[0m %s <= %s %s\n", #a, #b, (a) <= (b) ? "\033[32mTrue\033[0m" : "\033[31mFalse\033[0m");\
success_cnt(a, b, (char *)"<=");

typedef void (*TestFunc)();

typedef struct Function {
    TestFunc func;
    const char *str;
} Function;

int RUN_ALL_TESTS();
void add_function(TestFunc, const char*);
void success_cnt(int a, int b, char *str);

#endif

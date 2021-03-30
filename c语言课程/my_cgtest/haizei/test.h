/*************************************************************************
	> File Name: test.h
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月23日 星期五 10时09分32秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#include <haizei/linklist.h>

#define TEST(a, b)\
void a##_haizei_##b();\
__attribute__((constructor))\
void a##_haizei_##b##_haizei() {\
    add_function(a##_haizei_##b, #a "." #b);\
}\
void a##_haizei_##b()\

#define TYPE(a) _Generic((a),\
    int : "%d",\
    float : "%f",\
    double : "%lf",\
    char : "%c"\
)

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define YELLOW(a) COLOR(a, 33)
#define PURPLE(a) COLOR(a, 35)

#define PRINT(a, color) {\
    char frm[1000];\
    sprintf(frm, color("%s"), TYPE(a));\
    printf(frm, a);\
}

#define EXPECT(a, b, comp) {\
    ++testinfo.total;\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    if (_a comp _b) ++testinfo.success;\
    else {\
        printf(YELLOW("\n\t%s:%d: Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW("\t\texpect : %s %s %s") "\n", #a, #comp, #b);\
        printf(YELLOW("\t\tactual : "));\
        PRINT(_a, YELLOW);\
        printf(YELLOW(" vs "));\
        PRINT(_b, YELLOW);\
        printf("\n\n");\
    }\
    printf(GREEN("[-----------]"));\
    printf(" %s " #comp " %s %s\n", #a, #b, _a comp _b ? GREEN("True") : RED("False"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_BN(a, b) EXPECT(a, b, >)
#define EXPECT_SN(a, b) EXPECT(a, b, <)
#define EXPECT_BE(a, b) EXPECT(a, b, >=)
#define EXPECT_SE(a, b) EXPECT(a, b, <=)


typedef void (*TestFunction)();

typedef struct FunctionInfo {
    LinklistNode pnext;
    TestFunction func;
    const char *funcname;
} FunctionInfo;

typedef struct TestInfo {
    int total, success;
} TestInfo;

extern TestInfo testinfo;

void add_function(TestFunction, const char *);
int RUN_ALL_TESTS();

#endif

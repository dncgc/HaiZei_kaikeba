/*************************************************************************
	> File Name: test.h
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月16日 星期五 18时19分40秒
 ************************************************************************/
//__attribute__宏为后面的函数加一个属性，constructor使其优于主函数执行
//泛型宏：
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

#define CORLOR(a, b) "\033[" #b "m" a "\033[0m"
#define CORLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) CORLOR(a, 32)
#define RED(a) CORLOR(a, 31)
#define BULE(a) CORLOR(a, 34)
#define YELLOW(a) CORLOR(a, 33)

#define GREEN_HL(a) CORLOR_HL(a, 32)
#define RED_HL(a) CORLOR_HL(a, 31)
#define BULE_HL(a) CORLOR_HL(a, 34)
#define YELLOW_HL(a) CORLOR_HL(a, 33)

#define TYPE(a) _Generic((a),\
    int : "%d",\
    double : "%lf",\
    float : "%f",\
    long long : "%lld",\
    char * : "%s"\
)
//const char * : "%s"

#define P(a, color) {\
    char frm[1000];\
    sprintf(frm, color("%s"), TYPE(a));\
    printf(frm, a);\
}

#define EXPECT(a, b, comp) {\
    haizei_test_info.total += 1;\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    if (_a comp _b) haizei_test_info.success += 1;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s:%d: Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect : " #a " " #comp " " #b "\n\t\tactual : "));\
        P(_a, YELLOW_HL);\
        P(" vs ", YELLOW_HL);\
        P(_b, YELLOW_HL);\
        printf("\n\n");\
    }\
    printf(GREEN("[-----------] ") #a " " #comp  " " #b);\
    printf(" %s\n", _a comp _b ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)

typedef void (*TestFunc)();

typedef struct Function {
    TestFunc func;
    const char *str; //const char *str
} Function;

struct FunctionInfo{
    int total, success;
};
extern struct FunctionInfo haizei_test_info;//声明一个变量是存在的

int RUN_ALL_TESTS();
void add_function(TestFunc, const char*);//const char *

#endif

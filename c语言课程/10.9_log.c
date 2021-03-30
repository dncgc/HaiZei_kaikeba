/*************************************************************************
	> File Name: 10.9_log.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月09日 星期五 18时15分56秒
 ************************************************************************/
//变参宏, argc相当于...的别名, #将参数字符串化，##连接,确保参数为空的时候不出问题
//g++ -DEBUG .c 可调用log宏
#include <stdio.h>
//#ifdef DEBUG
#define log(frm, argc...) {\
    printf("[%s : %d] ", __func__, __LINE__);\
    printf(frm, ##argc);\
    printf("\n");\
}
//#else
//#define log(frm, argc...)
//#endif

#define contact(a, b) a##b

void func(int a) {
    a += 1;
    log("%d", a);
    return;
}

int main() {
    int a = 123, abcdef = 0;
    //printf("[%s : %d]%d\n", __func__, __LINE__, a);
    func(a);
    log("%d %d", a, abcdef);
    printf("hello world\n");
    log("hello workd");
    contact(abc, def) = 24;
    log("%d", abcdef);
    return 0;
}

/*************************************************************************
	> File Name: math_compute.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月18日 星期五 19时50分36秒
 ************************************************************************/
//运算符优先级
//结合方向（从左到右 或 从右到左）
//int 在一些64位操作系统中类型占32位，在一些32位系统中占16位
//32/64位在操作系统中代表寻址范围
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

int main() {
    int32_t a = 70000;
    printf("%s\n", PRId32);//d
    printf("%s\n", PRId64);//输出lld，但不要替换，增强可移植性
    printf("Hello" "world\n");
    printf("%" PRId32 "\n", a);
    printf("INT8_MIN = %" PRId8 " INT8_MAX = %" PRId8 "\n", INT8_MIN, INT8_MAX);

    int a = 7, b = 3, c;
    int *p = &a;
    *p--;//注意优先级与结合方向
//    printf("%d\n", a / b);//%lf 输出会出错0.00000 a*1.0转为浮点数就行了
/*    while (scanf("%d", &a) != EOF) { //可写成～scanf("%d", &a) -1的二进制为1111111
                                    //-2 = -1 -1 ==> 11111110
        printf("a = %d\n", a);
    }*/
    a ^= b;
    b ^= a;
    a ^= b; 
    //交换两个变量的值，不需要第三个变量，建议在整数中用，字符也可
    //
    bool n = true;
    printf("%d\n", n);
    return 0;
}

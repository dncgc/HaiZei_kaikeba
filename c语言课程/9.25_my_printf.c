/*************************************************************************
	> File Name: 9.25_my_printf.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月25日 星期五 18时13分41秒
 ************************************************************************/
//putchar();向屏幕打印一个字符
#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int reverse_num(int num, int *temp) {
    int digit = 0;
    do {
        *temp = *temp * 10 + num % 10;
        num /= 10;
        ++digit;
    } while (num);
    return digit;
}

int output_num(int num, int digit) {
    int cnt = 0;
    while (digit--) {
        putchar(num % 10 + '0');
        num /= 10;
        cnt++;
    }
    return cnt;
}

int my_printf(const char *frm, ...) {
    //字符串字面量不可被修改，所以用const, char *const frm:指针常量
    va_list arg;
    va_start(arg, frm);
    int cnt = 0;
    #define PUTC(a) putchar(a), ++cnt//局部宏，工程中很少全局宏
    for (int i = 0; frm[i]; ++i) {
        switch (frm[i]) {
            case '%': {
                switch (frm[++i]) {
                    case '%': {
                        PUTC(frm[i]);
                    } break;
                    case 'd': {
                        int xx = va_arg(arg, int);//取int类型的值 
                        uint32_t x;
                        if (xx < 0) x = -xx, PUTC('-');//输出负数 
                        else x = xx;
                        int num1 = x / 100000, num2 = x % 100000;
                        int temp1 = 0, temp2 = 0;
                        int digit1 = reverse_num(num1, &temp1);
                        int digit2 = reverse_num(num2, &temp2);
                        if (num1) digit2 = 5;
                        else digit1 = 0;
                        cnt += output_num(temp1, digit1);
                        cnt += output_num(temp2, digit2);
                    } break;
                    case 's': {
                        const char *str = va_arg(arg, const char*);
                        for (int i = 0; str[i]; i++) {
                            PUTC(str[i]);
                        }
                    } break;
                }
            } break;
            default: PUTC(frm[i]); break;
        }
    }
    #undef PUTC
    va_end(arg);
    return cnt;
}

int main() {
    int a = 123;
    printf("hello world\n");
    my_printf("hello world\n");
    printf("int a = %d\n",a);
    my_printf("int a = %d\n",a);
    printf("int a = %d\n",1000);
    my_printf("int a = %d\n",1000);
    printf("int a = %d\n",0);
    my_printf("int a = %d\n",0);
    printf("int a = %d\n",-123);
    my_printf("int a = %d\n",-123);
    printf("int a = %d\n",INT32_MAX);
    my_printf("int a = %d\n",INT32_MAX);
    printf("int a = %d\n",INT32_MIN);
    my_printf("int a = %d\n",INT32_MIN);
    char *str = "I love china\n";
    printf("%s", str);
    my_printf("%s", str);
    int n;
    while (~scanf("%d", &n)) {
        printf(" has %d digits!\n", printf("%d", n));
        my_printf(" has %d digits!\n", my_printf("%d", n));
    }
    return 0;
}

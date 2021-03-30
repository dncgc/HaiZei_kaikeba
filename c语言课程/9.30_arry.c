/*************************************************************************
	> File Name: 9.30_arry.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月30日 星期三 19时01分02秒
 ************************************************************************/
//静态数组传参

#include <stdio.h>

//int **a :指向指针的指针，指向int*类型的变量
//int (*a)[200] 与二维数组指针行为方式相同，高维数组同理，传参最多省略一维
//(*a)加括号是因为[]的优先级比*高，不加会变成指针数组
void func(int (*a)[200]) { //*a int n, int m, int a[n], int b[m]
    //*a = 123;
    a[0][1] = 234;
    printf("a = %p, a + 1 = %p\n", a, a + 1);
    return;
}

int main() {
    int arr[100][200];
    printf("arr = %p &arr[0] = %p\n", arr, &arr[0]);
    printf("arr + 1 = %p arr + 2 = %p\n", arr + 1, arr + 2);
    char *p = (char *)arr;
    printf("p = %p p + 1 = %p\n", p, p + 1);
    int n = 0;
    func(arr);
    printf("sizeof(arr) = %lu\n", sizeof(arr));
    printf("%d\n", n);
    for (int i = 0; i < 10; ++i) {
        scanf("%d", arr + i);
    }
    return 0;
}

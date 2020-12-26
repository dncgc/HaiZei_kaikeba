/*************************************************************************
	> File Name: rand.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Dec 2020 10:52:35 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    /*
    srand(time(0));
    int op, val;
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {
        switch (rand() % 5) {
            case 0: printf("0 %d\n", rand() % 15); break;
            case 1:
            case 2:
            case 3: printf("1 %d\n", rand() % 15); break;
            case 4: printf("2 %d\n", rand() % 15); break;
        }
    }
    */
    srand(time(0));
    int arr[26], sum = 0;
    for (int i = 0; i < 26; i++) {
        arr[i] = rand() % 1000;
        sum += arr[i];
    }
    printf("26\n");
    for (int i = 0; i < 26; i++) {
        printf("%c %lf\n", i + 'A', 1.0 * arr[i] / sum);
    }
    return 0;
}

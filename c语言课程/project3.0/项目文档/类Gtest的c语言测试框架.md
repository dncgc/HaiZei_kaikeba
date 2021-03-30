### 类Gtest的c语言测试框架

#### gtest演示：

下载后用cmake生成makefile文件。cmake：可以生成当前环境下支持的makefile文件

执行make会生成两个静态连接库：libgtest.a libgtest_main.a

在main.c中include<gtest/gtest.h>使用TEST()、EXPECT_EQ()、RUN_ALL_TESTS()来进行测试，注意编译时要-I./(gtest文件夹所在路径)将该文件夹添加到搜索路径；末尾要-L./(静态连接库所在路径)，-lgtest来链接静态连接库；-lpthread将多线程库连接进来。

###### main.c:

`#include <stdio.h>`
`#include <gtest/gtest.h>` 

`int add(int a, int b) {`
    `return a + b;`
`}`

`TEST(testfunc, add) {`
    `EXPECT_EQ(add(3, 4), 7);`
    `EXPECT_EQ(add(3, 2), 5);`
    `EXPECT_EQ(add(1, 2), 3);`
`}`
`int main(int argc, char *argv[]) {`
    `testing::InitGoogleTest(&argc, argv); //`
    `return RUN_ALL_TESTS();`
`}`

###### 运行结果图：

<img src="/home/cgc/c语言课程/project3.0/项目文档/gtest.png" alt="gtest" style="zoom: 25%;" />

为了实现类似效果，对例子代码进行分析：

TEST(func, add)没有返回值，而其形式类似于函数，可知TEST()是用宏实现的；

EXPECT_EQ(add(3, 4), 7)则不确定，可以用函数也可以用宏实现；

RUN_ALL_TESTS()在主函数中做返回值，可知其是返回值为0的函数。

#### project1.0

目标：将gtest的头文件替换为#include<haizei/test.h>可以编译通过，实现类似gtest功能的简单基本框架，最终效果：

<img src="/home/cgc/c语言课程/project3.0/项目文档/project1.0.png" alt="project1.0" style="zoom: 33%;" />

新建文件夹haizei，将test.h、test.c文件放在该文件夹下，.h放宏、函数声明、变量声明，.c放函数的定义。

###### step1:

首先是TEST宏的实现：`#define TEST(a, b) void a##b()`

EXPECT_EQ()的实现： `#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "True" : "False");`

RUN_ALL_TEST则直接return 0;

运行后会发现**无输出**，这是由于TEST代码替换后得到的函数并没有运行，直接在RUN_ALL_TEST中返回0值。

则将TEST宏改为以下代码后即可输出，\__attribute__作用是为后面的一个函数添加属性，costructor属性是让后面的函数先于主函数执行：

`#define TEST(a, b)\`

`__attribute__((constructor))`\

`void a##b()`

**step2:**

在step1完成的代码中有一个bug：当a##b（a与b不同）后的字段向同时会出现重复定义的错误。

可以在连接a,b时在中间连接一个不常用的字段，比如a##\_haizei_##b即可。

**step3:**

目前为止RUN_ALL_TESTS()其实并没起到什么作用，和直接return 0没有区别，而gtest中没有RUN_ALL_TESTS()则不会输出。

只有RUN_ALL_TESTS()中包含要运行的函数信息才能达到这样的效果。

可以让一个记录函数信息的函数先于主函数执行。则在\__attribute__后面加：

`void add##_haizei_##a##_haizei_##b() {\`
    `add_function(a##_haizei_##b, #a "_haizei_" #b);\`
`}\`

而且还要定义函数指针变量、存储函数指针和名称的结构体、一个全局结构体数组来辅助完成add_function()、RUN_ALL_TESTS()的功能。

在将字面量字符串进行传值的时候建议使用strdup()，可以避免对原字符串的操作。

#### project2.0

目标：将输出加上颜色，并且输出错误信息，记录每组测试的测试数量与成功数量，最终结果：

<img src="/home/cgc/c语言课程/project3.0/项目文档/project2.0.png" alt="project2.0" style="zoom:33%;" />

**1.输出颜色与格式信息：**

方法：\033[(颜色编号)m(字符串)\033[0m，由于加颜色的地方很多，则可以将添加颜色封装成宏

如：#define GREEN(a) CORLOR(a, 32)  #define CORLOR(a, b) "\033[" #b "m" a "\033[0m"

#define GREEN_HL(a)  CORLOR_HL(a, 32)  #define CORLOR(a, b) "\033[1;" #b "m" a "\033[0m"

对于不同比较关系也可封装成一个宏：

`#define EXPECT(a, b, comp) {\`

​    `printf(GREEN("[-------------]") #a #comp #b);\`

​    `pritnf(" %s\n", (a) comp (b) ? GREEN_HL("True") : RED_HL("False"));\`

`}`

`#define EXPECT_EQ(a, b) EXPECT(a, b, ==)`

**2.设计输出统计信息：**

定义一个全局结构体变量，包括total和success两个值，注意在.c文件中定义变量，结构体定义在.h，extern声明也在.h。

在RUN_ALL_TESTS()中初始化两个值为0，可用“%6.2lf”作为百分比占位符，共占6位。

**3.输出错误提示信息：**

由于每个测试返回值数据类型不确定，考虑使用泛型宏来实现（函数也可实现，转为字符串输出便可）。

使用\__FILE__ \__LINE__来获取文件与行号信息；

`#define TYPE(a) _Generic((a),\`

​    `int : "%d",\`

​    `double : "%lf",\`

​    `float : "%f",\`

`)`

**注意：**将TYPE(a)嵌套进颜色宏时会出现问题，不能正常展开，则可使用sprintf进行拼接：

`#define P(a, color) {\`

`char frm[1000];\`

`sprintf(frm, color("%s"), TYPE(a));\`

`printf(frm, a);\`

`}`

对于a++这样的传参，EXPECT()中if会出现问题，则添加\__typeof(a) _a = (a), __typeof(b) _b = (b), 然后将之后的a, b 更换为\_a、\_b。

#### project3.0

project2.0中_Generic宏在mac系统上可以正常运行，但在ubuntu上却不可以，实际上是因为\_Generic宏是c11标准中的，要用gcc来编译运行，g++不可，更改makefile及文件后缀即可。

目标：project2.0中定义了一个固定大小的结构体数组用来存储函数信息，实际工程中肯定不会这么实现，如果仅定义一个Function结构体类型的链表，那当其他类型的数据需要使用链表结构实现时需要再定一个该类型的链表，不灵活，考虑使用链表数据结构构造一个“外骨骼”来实现。

在工程中某个可重复使用的功能可单独封装成一个文件，在这封装到linklist.c和.h文件中。

`#define offset(T, name) (long long)(&(((T *)(0))->name)) //获取结构体T中name字段的偏移量`

`#define Head(p, T, name) (T *)((char *)(p) - offset(T, name))`

`struct LinkNode {`

`struct LinkNode *next;`

`};`

然后直接在想要实现链表结构的结构体末尾加上一个LinkNode类型的变量，再更改test.c便可。
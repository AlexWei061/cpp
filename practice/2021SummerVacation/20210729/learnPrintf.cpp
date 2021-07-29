#include<bits/stdc++.h>
using namespace std;

//https://www.runoob.com/cprogramming/c-function-printf.html
//http://c.biancheng.net/view/159.html

int main(){
    /* 1.printf("string\n") */
    printf("Hello world\n");

    /* 2.printf("输出控制符", 输出参数) */
    int i = 10;
    printf("%d\n", i);                     //%d是控制符, d表示二进制
    /*
    输出控制符介绍 :
    %d            按十进制整型数据的实际长度输出

    %lld          输出长整型数据

    %md           m 为指定的输出字段的宽度. 如果数据的位数小于 m, 则左端补以空格, 若大于 m, 则按实际位数输出

    %u            输出无符号整型(unsigned). 输出无符号整型时也可以用 %d, 这时是将无符号转换成有符号数, 然后输出.
                  但编程的时候最好不要这么写, 因为这样要进行一次转换, 使 CPU 多做一次无用功

    %c            用来输出一个字符

    %f            用来输出实数, 包括单精度和双精度, 以小数形式输出. 不指定字段宽度, 由系统自动指定, 整数部分全部输出,
                  小数部分输出 6 位, 超过 6 位的四舍五入

    %.mf          输出实数时小数点后保留 m 位, 注意 m 前面有个点

    %o            以八进制整数形式输出, 这个就用得很少了, 了解一下就行了

    %s            用来输出字符串. 用 %s 输出字符串同前面直接输出字符串是一样的. 但是此时要先定义字符数组或字符指针存储或指向字符串

    %x            以十六进制形式输出整数, 这个很重要(或%X 或%#x 或%#X)

    %e,E          以指数形式输出单、双精度实数

    %g,G          以%f或%e中较短的输出宽度输出单、双精度实数

    %p            输出指针地址
    */
    
    //%x %X %#x %#X的区别
    i = 47;
    printf("%x\n", i);     //--->  2f
    printf("%X\n", i);     //--->  2F
    printf("%#x\n", i);    //--->  0x2f
    printf("%#X\n", i);    //--->  0X2F 

    double n = 24.54;
    printf("%e\n", n);     //--->  2.454000e+01
    printf("%E\n", n);     //--->  2.454000E+01

    return 0;
}
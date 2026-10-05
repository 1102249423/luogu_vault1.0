//豆包完整快读
#include <cstdio>
#include <cctype>
//getchar只逐个读取单个字符，开销极小，是竞赛最快的字符读取方式。
template <class I>//泛型模板：I是类型占位符，可以自动适配int / long long / unsigned long long / __int128所有整型；原理：编译阶段，编译器会根据你传入变量的类型，自动生成对应 int、long long 的专属 read 函数，一份代码多用；
//内联函数，编译器直接把代码嵌入调用处，省去函数调用开销，提速；
inline void read(I &num){    //& 代表引用传递：函数内修改 num，会直接修改外部传入的变量，不用 return 返回数值，读入值直接存入变量。
    num = 0;
    char c = getchar(), up = c;//从标准输入缓冲区读取单个字符，一次只读 1 字节，速度极快；
    while(!isdigit(c)) up = c, c = getchar();//isdigit(c)：判断字符是不是 0~9 数字；
    while(isdigit(c)) num = (num << 1) + (num << 3) + (c ^ '0'), c = getchar();//🦖这个在以后可以常用喵~c ^ '0'：等价于 c - '0'，把字符'5'转为数字5，位运算略快于减法；
    //化简：num = num*2 + num*8 + 数字 = num*10 + 当前位数值和 num = num * 10 + (c-'0') 完全等价，位运算 CPU 执行效率略高于乘法。
    up == '-' ? num = -num : 0; return;//三元运算符：条件 ? 成立执行 : 不成立执行（0或者其他常数表示不变）
    //if(up == '-') num = -num;
}
//多参数重载 read
template <class I>
inline void read(I &a, I &b) {read(a); read(b);}
template <class I>
inline void read(I &a, I &b, I &c) {read(a); read(b); read(c);}


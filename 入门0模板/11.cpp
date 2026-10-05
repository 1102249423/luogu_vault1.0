#include <bits/stdc++.h>
using namespace std;
double r;
double h;
double v;
int main(){
    cin>>h>>r;
    v= (int)ceil(20000/3.14/r/r/h);
    //v= 20000/3.14/r/r/h;
    //cout<<v<<endl;
    printf("%d\n",(int)v);
    //cout<<fixed<<setprecision(1)<<p<<endl;
    return 0;
}

//printf("%%5d 输出：%5d\n", num);   // 宽度5，补空格："  123"（前面2个空格）
//printf("%%05d输出：%05d\n", num);  // 宽度5，补0："00123"（前面2个0）
//printf("%%3d 输出：%3d\n", num);   // 宽度3，和数字位数一致："123"
//printf("%%03d输出：%03d\n", num);  // 宽度3，和数字位数一致："123"
//%nd：n 是输出总宽度，如果数字的位数小于 n，左侧补空格（右对齐）；如果位数大于等于 n，按实际位数输出。
//%0nd：0 是补位符，含义是 “宽度不足时左侧补 0 而非空格”，其余规则和 %nd 一致。
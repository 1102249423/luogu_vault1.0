#include <bits/stdc++.h>
using namespace std;
int n;
//🦖使用结构体存储每个成员的信息，包括姓名、原职位、新职位、帮贡、等级和输入顺序。
struct node {
    string na, zw, xzw;  // 姓名、原职位、新职位
    long long bg;        // 帮贡
    int le, h;           // 等级、输入顺序编号
} ab[115];
//🦖将职位字符串映射为数字，数字越小表示职位越高，便于后续比较。
int change(string a) {
    if (a == "BangZhu") return 0;
    if (a == "FuBangZhu") return 1;
    if (a == "HuFa") return 2;
    if (a == "ZhangLao") return 3;
    if (a == "TangZhu") return 4;
    if (a == "JingYing") return 5;
    if (a == "BangZhong") return 6;
}
//（1）先按帮贡排序；
//（2）如帮贡一样，则按输入顺序排列。
int cmp1(node x, node y) {
    //如果 x 比 y 早输入 → 返回 真（1） → x 排 y 前面
    //如果 x 比 y 晚输入 → 返回 假（0） → y 排 x 前面
    if (x.bg == y.bg) return x.h < y.h;
    //如果 x 帮贡 > y 帮贡 → 返回 真（1） → x 在前
    //如果 x 帮贡 < y 帮贡 → 返回 假（0） → y 在前
    else return x.bg > y.bg;
}
//2.再重新编好职位后排输出顺序，也就是职位内的排名，排序方式如下：
//（1）先按现在的职位排序；
//（2）如职位相同，再按等级排序；
//（3）如果恰好等级还破天荒地一样，则按输入顺序排列。
int cmp2(node x, node y) {
    if (change(x.xzw) == change(y.xzw)) {      // 职位相同
        if (x.le == y.le) return x.h < y.h;    // 等级相同，按输入顺序
        return x.le > y.le;                    // 否则等级降序
    }
    return change(x.xzw) < change(y.xzw);       // 职位数字小的在前（职位高）
}


int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>ab[i].na>>ab[i].zw>>ab[i].bg>>ab[i].le;
        ab[i].h=i;
    }
    /*
    sort(start, end, compare_function)、
    start：指向要排序序列起始位置的指针/迭代器
    end：指向要排序序列结束位置的下一个的指针/迭代器
    compare_function：比较函数，定义了如何比较两个元素。🦖cmp1作为sort函数的参数
    */
    sort(ab+4,ab+1+n,cmp1);//前三人位置不动
    for (int i=1;i<=n;i++){
        if (i==1) ab[i].xzw="BangZhu";
        else if (i==2||i==3) ab[i].xzw="FuBangZhu";
        else if (i==4||i==5) ab[i].xzw="HuFa";
        else if (i>=6&&i<=9) ab[i].xzw="ZhangLao";
        else if (i>=10&&i<=16) ab[i].xzw="TangZhu";
        else if (i>=17&&i<=41) ab[i].xzw="JingYing";
        else ab[i].xzw="BangZhong";
    }
    sort(ab+1,ab+1+n,cmp2);//所有人位置都改变
    for (int i=1;i<=n;i++){
        cout<<ab[i].na<<" "<<ab[i].xzw<<" "<<ab[i].le<<endl;
    }
    return 0;
}

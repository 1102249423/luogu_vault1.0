#include <bits/stdc++.h>//老伙计
using namespace std;
int a[100000];
int n,m;
bool cmp(int q,int h) {
    return q<h;//如果 q 小于 h，返回 true，否则返回 false。比较函数
}
int main() {
    //🦖提速三件套
    ios::sync_with_stdio(false);//C++ 标准库默认：cin/cout 和 C 语言的 scanf/printf 共用同一个缓冲区，同步数据保证混用不出错。关闭同步后：cin、cout 不再和 C 输入输出同步，省去同步开销，速度大幅提升。注意：关闭后不能同时混用 cin 和 scanf、cout 和 printf，否则输出乱序。
    cin.tie(0);//读取输入时不再刷新 cout，减少 IO 操作，提速
    cout.tie(0);//解除 cout 和其他输入流的绑定，输出时不会自动刷新输入缓存，进一步减少开销。
    cin>>n>>m;
    for (int i = 1; i <= m; ++i) {
        for (int j= 1; j < i; ++j) {
            if (a[j]>a[i]) {
                swap(a[j],a[i]);
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}
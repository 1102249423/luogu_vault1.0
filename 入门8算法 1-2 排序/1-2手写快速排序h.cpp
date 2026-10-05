#include <bits/stdc++.h>//🦖找一个基准数，小的扔左边，大的扔右边，然后递归
using namespace std;
int n,m;
int a[2000000];


void quit_sort(int l,int r) {
    if (l>=r) return;//🦖如果里面不是没有元素，就返回空值，直接结束当前这一次 quit_sort 函数调用，不再往下执行后面的分区、递归代码。
    int mid=rand()%(r-l+1)+l;//rand() 会返回一个很大的非负随机整数。加上偏移量
    int t=a[mid];//把选中的基准数存到 t，后面数组会被覆盖，防止基准丢失。
    int q=l,h=r;
    a[mid]=a[l];
    while (q<h) {
        while (q<h&&a[h]>=t) {
            h--;
        }
        // 把找到的小数，填入左边的坑 q
        a[q]=a[h];
        while (q<h&&a[q]<=t) {
            q++;
        }

        a[h]=a[q];
    }
    a[q]=t;
    // 递归排 基准左侧区间 [l, q-1]
    quit_sort(l,q-1);
    // 递归排 基准右侧区间 [q+1, r]
    quit_sort(q+1,r);
    return;//void 函数不需要返回具体数值，return; 表示：当前函数所有逻辑执行完毕，退出函数，回到上一层递归调用的位置继续执行。
}
int main() {
    srand(time(0)); // 🦖随机播种，只执行一次
    cin>>n>>m;
    for (int i = 1; i <=m; ++i) {
        cin>>a[i];
    }
    quit_sort(1,m);
    for (int i = 1; i <=m; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}
#include <bits/stdc++.h>//🦖桶排序绝对的朴实无华，现在觉得缺少力量，那就从真正的强工作倒推你要的东西！
using namespace std;
int n,m;
int tong[2000000];
int main(){

    cin>>n>>m;
    for (int i = 1; i <= m; ++i) {
        int x;
        cin>>x;
        tong[x]++;
    }
    for (int i = 1; i <= n; ++i) {//从最小的桶 1，一直遍历到最大的桶 n，保证输出一定从小到大（升序）。
        for(int j=1;j<=tong[i];j++) {
            cout<<i<<" ";
        }
    }
    return 0;
}
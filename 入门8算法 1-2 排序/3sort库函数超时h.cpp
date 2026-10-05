#include <bits/stdc++.h>
using namespace std;
int n,k;
const int MAXN = 5e6 + 10;
int a[MAXN]; // 开到500万+，满足题目上限
int main(){
    //不加这仨哥们会超时
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[k]<<" ";
    return 0;

}
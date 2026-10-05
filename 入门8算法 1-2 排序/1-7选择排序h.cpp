#include<bits/stdc++.h>//🦖找1到m，交换。2到m，交换。3到m，交换。等等下去的值；
using namespace std;
int a[1000005];
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i = 1; i <=m; ++i) {
        cin>>a[i];
    }
    for (int i = 1; i <=m; ++i) {
        int minn=2e9;//2x10^9;
        int ans=0;
        for (int j = i; j <= m; ++j) {//找1到m。2到m。3到m等等下去的值；
            if (a[j]<minn) {
                minn=a[j];
                ans=j;
            }
        }
        swap(a[i],a[ans]);
    }
    for(int i=1;i<=m;i++) cout<<a[i]<<" ";
    return 0;

}

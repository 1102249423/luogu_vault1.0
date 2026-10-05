#include <bits/stdc++.h>
using namespace std;
int n;
int a[114511];
int b[114511];
int c[114511];
int sum[114511];
int main(){
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i]>>b[i]>>c[i];
        sum[i]=a[i]+b[i]+c[i];
    }
    //掌握精髓
    sort(sum,sum+n);
    for (int i = 0; i < n; ++i) {
        cout<<sum[i];
        
    }
    return 0;
}
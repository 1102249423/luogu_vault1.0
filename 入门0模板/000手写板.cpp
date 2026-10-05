#include <bits/stdc++.h>//🦖
using namespace std;
int n,m;
int a[2000000];


int main(){

    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        cin>>a[i];
    }
    //sort([数组名],[数组名]+n);
    sort(a,a+m);
    for(int i = 0;i < m;++i)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
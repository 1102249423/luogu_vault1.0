#include <bits/stdc++.h>
using namespace std;
int N;
int a[114511];
int main(){
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }
    //sort([数组名],[数组名]+n);
    sort(a,a+N);
    for(int i = 0;i < N;++i)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
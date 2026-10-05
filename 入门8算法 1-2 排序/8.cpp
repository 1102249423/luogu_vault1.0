#include <bits/stdc++.h>
using namespace std;
int N;
int a[114511];

//int vessel1=0;
int cnt;
int main(){
    cin>>N;
    for (int i=1;i<=N;i++) {
        cin>>a[i];
    }
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=i;j++) {
            if (a[i]<a[j]) {
                //swap(a[i],a[j]);//请问了这个不加有变化么？灵活，什么时候死板只是减少工作量。
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
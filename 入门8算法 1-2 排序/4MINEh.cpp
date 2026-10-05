#include <bits/stdc++.h>
using namespace std;
int N;
int M;
int a[10000000];
int main(){
    int N1;
    cin>>N;
    N1=N;
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }
    sort(a,a+N);

    for (int i = 0; i < N; ++i) {

        if (a[i]==a[i-1]) {
            a[i-1]=0;
            N1=N1-1;
        }
    }
    sort(a,a+N);
    M=N1;
    cout<<M<<endl;
    for (int i = 0; i < N; ++i) {
        if (a[i]!=0)
        cout<<a[i]<<" ";
    }
    return 0;

}
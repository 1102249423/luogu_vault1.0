#include <bits/stdc++.h>
using namespace std;
int N;
int a[114511];
int b[114511];

int cnt=0;
int main(){
    cin>>N;
    for (int i=1;i<=N;i++) {
        cin>>a[i];
    }
    for (int i=1;i<=N;i++) {
        //cin>>a[i];
        if (i!=N) {
            b[i]=abs(a[i+1]-a[i]);
        }
    }
    sort(b+1,b+N);
    for (int i=1;i<=N-1;i++) {
        //cout<<b[i];
        if (b[i]!=i) {
            cnt=1;
        }
    }

    if (cnt==1) {
        cout<<"Not jolly"<<endl;
    }else {
        cout<<"Jolly"<<endl;
    }

    return 0;

}
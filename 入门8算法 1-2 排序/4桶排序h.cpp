#include<bits/stdc++.h>
using namespace std;
int n;
int a[1001];
int ans;
int main() {
    cin>>n;
    for (int i=1;i<=n;++i) {
        int b;
        cin>>b;
        a[b]++;
        if (a[b]==1) {
            ans++;
        }
    }
    cout<<ans<<endl;
    for (int i = 1; i <= 1000; ++i) {
        if (a[i]!=0) {
            cout<<i<<" ";
        }
    }


}


/*

#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int ans;
int main() {
    cin>>n;
    for (int i=0;i<n;++i) {
        int b;
        cin>>b;
        a[b]++;
        if (a[b]==1) {
            ans++;
        }
    }
    cout<<ans<<endl;
    for (int i = 0; i < 1000; ++i) {
        if (a[i]!=0) {
            cout<<i<<" ";
        }
    }


}



*/

#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000];
int max1=0,min1=100;
int main(){
    cin>>n;
    if(n==1){
        cout<<0<<endl;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(max1<a[i]){
            max1=a[i];
        }
        if(min1>a[i]){
            min1=a[i];
        }
        //cout<<a[i]<<"+"<<i<<endl;
    }
    cout<<max1-min1<<endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int n;
int i1;
int a[100000];
int main(){
    cin>>n;
    int n1=n;
    i1=0;
    while(n!=1){
        if(n%2==0){
            n=n/2;
            a[i1]=n;
        }else{
            n=n*3+1;
            a[i1]=n;
        }
        i1++;
    }
    for (int i = i1-1;i>=0; i--) {//不需要n作为上届判断条件的写法
        cout<<a[i]<<' ';
    }
    cout<<n1;
    return 0;
}



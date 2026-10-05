#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
int b[100];
int main(){

    cin>>n;
    //🦖核心区别是 “返回值时机”：i++ 先返回原值再自增，++i 先自增再返回新值；
    //只有在需要使用自增的返回值时（如赋值、打印），才需要区分两者。
    for (int i = 0; i <n ; i++) {
        cin>>a[i];
        //b[i]=0;
    }
    for (int i = 0; i <n ; i++) {
        for (int j = 0; j <i ; j++) {
            if(a[j]<a[i]){
                b[i]+=1;
            }
        }
        cout<<b[i]<<" ";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
float a;
int b;
int main(){
    cin>>a>>b;
    cout<<fixed<<setprecision(3)<<a/b<<endl;
    //cout<<setprecision(3)<<fixed<<a/b<<endl;//fixed 和 setprecision(5) 的顺序不影响最终效果，只要它们在输出浮点数之前被设置就可以。
    cout<<b*2<<endl;
    return 0;
}
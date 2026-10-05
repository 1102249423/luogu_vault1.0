#include <bits/stdc++.h>//🦖
using namespace std;
int min0,max0;

long long juxing;
long long changfangxing=0;
long long zhengfangxing=0;
int main(){
    int n,m;
    cin>>n>>m;
    if (n>=m) {
        min0=m;
        max0=n;
    }else{
        min0=n;
        max0=m;
    }
    for (int i=min0;i>=1;i--) {
        zhengfangxing+=(n+1-i)*(m+1-i);
    }
    for (int i = 0; i <= n-1; ++i) {
        for (int j = 0; j <= m-1; ++j) {
            juxing+=(m-j)*(n-i);
        }
    }
    changfangxing=juxing-zhengfangxing;
    cout<<zhengfangxing<<" "<<changfangxing;
    return 0;

}
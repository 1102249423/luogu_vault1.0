#include <bits/stdc++.h>
using namespace std;
long long a=1,b=1,c=0;
int n;
int main(){
    cin>>n;
    for(int i=3;i<=n;i++){
      c=a+b;
      a=b;
      b=c;

    }
    cout<<c<<".00"<<endl;
    //cout<<s<<endl;
    //cout<<fixed<<setprecision(1)<<p<<endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
double a;
double b;
double c;
double p;
double s;
int main(){
    cin>>a>>b>>c;
    p=((a+b+c))/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    cout<<fixed<<setprecision(1)<<s<<endl;
    //cout<<fixed<<setprecision(1)<<p<<endl;
    return 0;
}
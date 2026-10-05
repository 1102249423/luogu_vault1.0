#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a1[100000+10];
ll b1[100000+10];
ll c1[100000+10];


ll w(ll a,ll b,ll c) {
    if (a<=0||b<=0||c<=0) {
        return 1;
    }
    if (a>20||b>20||c>20) {
        return w(20,20,20);
    }
    if(a<b&&b<c){
        return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    }else{
        return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }
}

int main(){
    int i=1;
    while (cin>>a1[i]>>b1[i]>>c1[i]) {
        if(a1[i] == -1 && b1[i] == -1 && c1[i] == -1) break;
        cout<<"w("<<a1[i]<<", "<<b1[i]<<", "<<c1[i]<<") "<<"= "<<w(a1[i],b1[i],c1[i])<<endl;
        i++;
    }
    return 0;
}
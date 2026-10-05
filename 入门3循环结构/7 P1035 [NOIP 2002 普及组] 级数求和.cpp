#include <bits/stdc++.h>
using namespace std;

int main(){
    double a=1,b=1,s=0;
    b=1/a;
    int k;
    cin>>k;
    while(s<=k){
        s+=b;
        a++;
        b=1/a;
    }
    cout<<a-1<<endl;
    return 0;
}
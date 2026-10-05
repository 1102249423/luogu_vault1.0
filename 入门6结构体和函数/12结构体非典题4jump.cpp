#include<iostream>
#include<cmath>
using namespace std;
int n;
long long s=1;
int main(){
    cin>>n;
    for (int i = 0; i < n-1; ++i) {
        s=(s+1)*2;
    }
    cout<<s;
    return 0;
}









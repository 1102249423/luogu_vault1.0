#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    int run[3000];
    int cnt=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if((i%4==0 && i%100!=0) || (i%400==0)){
            run[cnt]=i;
            cnt++;
        }
    }

    cout<<cnt<<endl;
    for(int j=0;j<cnt;j++){
        cout<<run[j]<<" ";
    }
    return 0;
}
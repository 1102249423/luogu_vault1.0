#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000];
int flag=0;
int flagmax=0;
int main(){
    cin>>n;
    if(n==1){
        cout<<1<<endl;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i+1]-a[i]==1){
            flag++;
        }else{
            flag=0;
        }
        if(flagmax<flag){
            flagmax=flag;
        }
        //cout<<a[i]<<"+"<<i<<endl;
    }
    //cout<<flagmax++<<endl;
    cout<<++flagmax<<endl;
    return 0;
}


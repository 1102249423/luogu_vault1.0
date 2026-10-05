#include <bits/stdc++.h>
using namespace std;
int n,m;
int sum1,sum;
int a[10000];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        sum+=a[i];
    }
    for(int i=0;i<n-m;i++){
        sum1=0;
        for(int j=i;j<i+m;j++){
            sum1+=a[j];
        }
        //cout<<sum1<<endl;
        if(sum1<sum){
            sum=sum1;
        }
    }
    cout<<sum<<endl;
    return 0;
}

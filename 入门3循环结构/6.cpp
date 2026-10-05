#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int i1,i2;
        i1=i;
        while(i1>=10){
            i2=i1%10;
            i1=i1/10;
            if(i2==k){
                sum++;
            }
        }
        if(i1==k){
            sum++;
        }

        //cout<<i<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
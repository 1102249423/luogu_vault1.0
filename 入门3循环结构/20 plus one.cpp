#include <bits/stdc++.h>
using namespace std;
int n;
int X,K;
int sum=0;
int i,j,k;
int j11,k11,flag=0;
int main(){
    cin>>n;
        for(j=100;j>=1;j--){
            for (k = 1; k < 14560; k++) {
                if((j*7+k*21)*52==n){
                    cout<<j<<endl<<k<<endl;
                    return 0;
                }
            }
        }
    return 0;
}
//不用这么多break，一个return0解俊愁🦖

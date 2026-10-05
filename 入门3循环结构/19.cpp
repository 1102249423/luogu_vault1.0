#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int max1=0,min1=10;
int sum1=0;
double sum=0;
int main(){
    cin>>n;
//    if(n==1){
//        cout<<0<<endl;
//    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(max1<a[i]){
            max1=a[i];
        }
        if(min1>a[i]){
            min1=a[i];
        }
        sum1+=a[i];
    }
    sum=(double)(sum1-max1-min1)/(n-2);
    cout<< setprecision(3) <<sum<<endl;
    return 0;
}


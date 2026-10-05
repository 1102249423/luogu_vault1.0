#include <bits/stdc++.h>
using namespace std;
int s1,s2,s3;
int a[1000];
int max1,max2=0;
int main(){
    cin>>s1>>s2>>s3;
    for (int i = 1; i <= s1; ++i) {
        for (int j = 1; j <=s2; ++j) {
            for (int k = 1; k <=s3; ++k) {
                a[i+j+k]++;
            }
        }
    }

    for (int i =999; i >=0 ;i--) {
        if(a[i]>=max1){
            max1=a[i];
            max2=i;
        }
    }
    cout<<max2<<endl;
    return 0;
}


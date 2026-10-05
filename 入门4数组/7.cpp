#include <bits/stdc++.h>
using namespace std;
int n;
int a[7];
int b[7];
int c[7];
int main(){
    cin>>n;
    for (int i = 0; i <7 ; ++i) {
        cin>>a[i];//输入中奖号码
    }
    for (int i1 = 0; i1 < n; ++i1) {//n tickets
        int sum=0;
        for (int i2 = 0; i2 < 7; ++i2) {
            cin>>b[i2];
            for(int i3 = 0; i3 < 7; ++i3){
                if(b[i2]==a[i3]){
                    sum++;//🦖好思路
                }
            }
        }
        c[sum]++;//🦖记录答案
    }

    for (int i5 = 7; i5 >= 1; i5--) {
        cout<<c[i5]<<" ";//🦖output;
    }

    return 0;
}

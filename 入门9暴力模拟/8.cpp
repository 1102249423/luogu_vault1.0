#include <bits/stdc++.h>
using namespace std;
int r,c,k;
const int MAXN = 105;//🦖
char ans[MAXN][MAXN];//🦖
int a1,a2,a3,a4=1;//只有a4等于一批量解压了😅
int cnt=0;
// bool scan0(int m0) {
//     for (int i = 1; i <=m0; ++i) {
//         if (ans[i][j])
//     }
//     return true;
//     return false;
// }
int main(){
    cin>>r>>c>>k;
    for (int i = 1; i <=r; ++i) {
        for (int j = 1; j <=c; ++j) {
            cin>>ans[i][j];
        }
    }
    for (int i = 1; i <=r; ++i) {
        for (int j = 1; j <=c; ++j) {
            a1=1;
            a2=1;
            a3=1;
            a4=1;
            if (ans[i][j]=='.') {
                if(i + k - 1 > r) a1 = 0; // 边界不够，直接不行🦖
                else {
                    for (int l = 0; l <=k-1; ++l) {
                        if (ans[i+l][j]!='.') {
                            a1=0;
                            break;
                        }
                    }
                }
                if(j + k - 1 > c) a3 = 0; // 边界不够，直接不行🦖
                else {
                    for (int l = 0; l <=k-1; ++l) {
                        if (ans[i][j+l]!='.') {
                            a3=0;
                            break;
                        }
                    }
                }

                cnt+=a1;
                //cnt+=a2;
                cnt+=a3;
                //cnt+=a4;

            }
        }
    }
    // 关键！k=1时同一个点横竖各统计一次，除以2去重🦖
    if(k == 1) cnt /= 2;
    cout<<cnt<<endl;
    return 0;
}
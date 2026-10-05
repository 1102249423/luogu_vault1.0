#include <bits/stdc++.h>
using namespace std;
const int kMaxn = 20 + 10;//🦖学习了常量命名规则
int tishu[20+10];
int shijian[60+10];
int dp[114511];
int cnt=0,cnt0=0;
int main(){
    cin>>tishu[1]>>tishu[2]>>tishu[3]>>tishu[4];
    for (int i = 1; i <=4; ++i) {
        cnt=0;
        for (int j = 1; j <=tishu[i]; ++j) {
            cin>>shijian[j];
            cnt+=shijian[j];
        }
        for (int j = 1; j <=tishu[i]; ++j) {
            for(int k=cnt/2;k>=shijian[j];k--) {//k是总的能存放的时间（总时间的一半），要求能存放的时间必须大于当下时间，01背包倒着去找
                dp[k]=max(dp[k],dp[k-shijian[j]]+shijian[j]);//dp[k]存放当前最大价值（只是这个价值等于时间）
            }
        }
        cnt0+=cnt-dp[cnt/2];//累加为另一个脑子(sum-x一定大于x，并且x等于dp【cnt/2】)
        memset(dp,0,sizeof(dp));
    }

    cout<<cnt0;//输出
    return 0;

}



/*
* void dfs(当前物品pos, 统计参数1, 统计参数2,...){
    // 边界1：所有物品遍历完
    if(pos>n){
        统计答案;
        return;
    }
    // 边界2：中途满足条件提前return（按需加）

    // 分支1：不选当前
    dfs(pos+1, 参数不变);
    // 分支2：选当前
    dfs(pos+1, 参数更新);
}
// 调用 dfs(1,初始值1,初始值0...)
 */

#include <bits/stdc++.h>
using namespace std;
const int M=114511;//🦖
int s[M];
int b[M];
int n;

// int cnt_s=1,cnt_b=0;
int ans=0x7ffffff;
void dfs(int step,int cnt_s,int cnt_b){
    if (step>n) {
        if(cnt_s==1&&cnt_b==0)return;//只有走到终点，才需要判断要不要舍弃空集。
        ans=min(abs(cnt_s-cnt_b),ans);
        return;
    }
    dfs(step+1,cnt_s*s[step],cnt_b+b[step]);
    dfs(step+1,cnt_s,cnt_b);
    // for (int i = 1; i <=n; ++i) {
    //     cnt_s*=s[i];
    //     cnt_b+=b[i];
    // }
}
int main(){
    cin>>n;
    for (int i = 1; i <=n; ++i) {
        cin>>s[i]>>b[i];
    }
    dfs(1,1,0);

    cout<<ans;
    return 0;
}


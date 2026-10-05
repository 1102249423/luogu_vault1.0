#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[21][21][21]; //记忆数组，0~20

ll w(ll a,ll b,ll c) {
    if (a<=0||b<=0||c<=0) {
        return 1;
    }
    if (a>20||b>20||c>20) {
        return w(20,20,20);
    }
    if(dp[a][b][c] != -1){ //算过直接返回，不再递归
        return dp[a][b][c];
    }
    ll res;
    if(a<b&&b<c){
        res = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    }else {
        res = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }
    return dp[a][b][c] = res; //保存结果
    //dp[a][b][c] = res;   // 第一步：把计算出来的结果res存入记忆化数组
    //return dp[a][b][c];  // 第二步：返回这个值
    //return dp[a][b][c] = res; 等价于上面两行合并写。
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp)); //标记全部状态未访问
    ll a,b,c;
    while (cin>>a>>b>>c) {
        if(a == -1 && b == -1 && c == -1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
    }//🦖这个循环输入可以学习
    return 0;
}
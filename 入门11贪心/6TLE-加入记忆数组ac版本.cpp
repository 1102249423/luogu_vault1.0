#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a1[100000+10];//🦖浪费内存
ll b1[100000+10];
ll c1[100000+10];
ll dp[21][21][21]; //🦖记忆数组，0~20

ll w(ll a,ll b,ll c) {
    ll res;

    if (a<=0||b<=0||c<=0) {
        return 1;
    }
    if (a>20||b>20||c>20) {
        return w(20,20,20);
    }
    //🦖必须先进行边界判断
    if(dp[a][b][c] != -1){ //🦖算过直接返回，不再递归
        return dp[a][b][c];
    }
    if(a<b&&b<c){
        res = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    }else{
        res = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }

    dp[a][b][c] = res;
    return dp[a][b][c];
}

int main(){
    //🦖加速
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    memset(dp, -1, sizeof(dp)); //标记全部状态未访问
    int i=1;
    while (cin>>a1[i]>>b1[i]>>c1[i]) {
        if(a1[i] == -1 && b1[i] == -1 && c1[i] == -1) break;
        cout<<"w("<<a1[i]<<", "<<b1[i]<<", "<<c1[i]<<") "<<"= "<<w(a1[i],b1[i],c1[i])<<endl;
        i++;
    }
    return 0;
}
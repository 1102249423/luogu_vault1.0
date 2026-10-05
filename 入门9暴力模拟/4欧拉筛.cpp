// 我们只需要判断最多 20 万个随机和，不需要 1~1e8 全部质数。
// 欧拉筛要循环 1 亿个数预处理，光是筛的过程就会超时，做了 99% 无用功。
// 3. 欧拉筛什么时候才必须用？
// 满足下面任意一条才推荐筛法：
// 1题目要求多次查询区间内大量数字（比如输出 1~1e6 所有素数）；
// 2重复质数查询次数上百万次以上；
// 3数值上限不大（比如 MAX≤1e6），数组不会爆内存。
#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[114511];
int ans=0;
//布尔数组，标记某个数是否为素数，1 代表是素数，0 代表不是。数组大小 100000010 表示最多能筛到 1 亿。
bool isPrime[1000000];
//整型数组，按顺序存储筛选出的素数（比如 Prime[1]=2，Prime[2]=3，Prime[3]=5...）。数组大小 6000010 是因为 1 亿以内的素数约有 5761455 个，预留足够空间。
//cnt是质数的计数（同时作为Prime数组的下标）
int Prime[1000000],cnt0=0;
void GetPrime(int n){
    memset(isPrime, 1, sizeof(isPrime));//🦖以“每个数都是素数”为初始状态，逐个删去
    isPrime[1] = 0;//1不是素数
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            Prime[++cnt0]=i;
        }
        for(int j=1;j<=cnt0&& i*Prime[j]<=n;j++){
            isPrime[i*Prime[j]] = 0;//筛选出i*Prime[j]的因子。
            if(i % Prime[j] == 0)//i中也含有Prime[j]这个因子
                break; //保证每个合数只被它的最小质因数筛掉一次，从而实现 O(n) 的线性时间复杂度。
        }
    }
}
void dfs(int pos,int cnt,int sum) {
    if (cnt==k) {
        if (isPrime[sum]==0) {
            ans++;
        }
        return;
    }
    if (pos>n)
        return;
    dfs(pos + 1, cnt, sum);
    dfs(pos + 1, cnt+1, sum+a[pos]);
}


int main(){
    cin>>n>>k;
    for (int i = 1; i <= k; ++i) {
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans<<endl;

    return 0;
}
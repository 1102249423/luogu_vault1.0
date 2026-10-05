#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[25];   // n<=20，开25足够
int ans = 0;

// 试除法判断质数
bool isPrime(int s) {
    if (s < 2) return false;
    for (int i = 2; i * i <= s; i++) {
        if (s % i == 0) return false;
    }
    return true;
}

// DFS：pos当前下标，cnt已选数量，sum当前和
void dfs(int pos, int cnt, int sum) {
    // 选够k个，判断质数
    if (cnt == k) {
        if (isPrime(sum)) ans++;
        return;
    }
    // 已经遍历完所有数字，直接返回
    if (pos > n) return;

    // 分支1：不选当前a[pos]，去下一个🦖递归的核心思路
    dfs(pos + 1, cnt, sum);
    // 分支2：选当前a[pos]，计数+1，和累加🦖递归的核心思路
    dfs(pos + 1, cnt + 1, sum + a[pos]);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
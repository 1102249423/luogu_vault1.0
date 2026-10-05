xian kai hot 100
当然有，而且**全是竞赛里写代码必背、能直接救命的模板**。
我按**最常用 → 次常用**给你整理一套完整清单，全部是 C++ OI / ACM 实战风格，直接复制就能用。

# 一、输入输出类（竞赛最重要）
## 1. 完整版快速读入（支持 int / long long）
```cpp
#include <cstdio>
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

inline long long readll() {
    long long x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
```

## 2. 快速输出（大数据必用）
```cpp
inline void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x); putchar('\n');
}
```

## 3. 关闭同步 cin（懒人版加速）
不想写快读就用这个，速度接近 scanf：
```cpp
ios::sync_with_stdio(false);
cin.tie(0); cout.tie(0);
```

---

# 二、常用宏定义（比赛必写）
```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define rep(i, a, b) for(int i = a; i <= b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
#define lowbit(x) (x & -x)
```

---

# 三、基础数据结构 & 算法模板
## 1. 离散化（处理大值域）
```cpp
vector<int> all;
sort(all.begin(), all.end());
all.erase(unique(all.begin(), all.end()), all.end());

// 获取离散化后的值
int get(int x) {
    return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
}
```

## 2. 二分查找
```cpp
// 最小满足条件的值
int find_min(int l, int r) {
    int ans = r;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}
```

## 3. 前缀和 & 差分
一维前缀和：
```cpp
s[i] = s[i-1] + a[i];
// [l,r] 和：s[r]-s[l-1]
```

差分：
```cpp
d[l] += x; d[r+1] -= x;
// 最后求一遍前缀和
```

二维差分：
```cpp
d[x1][y1] += w;
d[x1][y2+1] -= w;
d[x2+1][y1] -= w;
d[x2+1][y2+1] += w;
```

---

# 四、数论常用（高频）
## 1. 最大公约数 / 最小公倍数
```cpp
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a,b) * b; }
```

## 2. 快速幂
```cpp
ll qpow(ll a, ll b, ll mod) {
    ll res = 1;
    while(b) {
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
```

## 3. 线性筛（质数 + 欧拉函数）
```cpp
const int N = 1e6 + 5;
int pr[N], cnt;
bool vis[N];

void sieve(int n) {
    rep(i, 2, n) {
        if(!vis[i]) pr[++cnt] = i;
        for(int j = 1; j <= cnt && i * pr[j] <= n; j++) {
            vis[i * pr[j]] = 1;
            if(i % pr[j] == 0) break;
        }
    }
}
```

---

# 五、图论常用
## 1. 邻接表建图
```cpp
vector<int> g[N];
void add(int u, int v) {
    g[u].pb(v);
}
```

## 2. DFS / BFS 模板
```cpp
bool vis[N];
void dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) if(!vis[v]) dfs(v);
}

void bfs(int s) {
    queue<int> q; q.push(s); vis[s] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) if(!vis[v]) vis[v] = 1, q.push(v);
    }
}
```

## 3. Dijkstra（最短路）
```cpp
int dis[N];
priority_queue<pii, vector<pii>, greater<pii>> q;

void dijkstra(int s) {
    mem(dis, 0x3f); dis[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if(d > dis[u]) continue;
        for(auto [v, w] : g[u]) {
            if(dis[v] > d + w) {
                dis[v] = d + w;
                q.push({dis[v], v});
            }
        }
    }
}
```

---

# 六、字符串常用
## 1. KMP 匹配
```cpp
int ne[M];
void getnext(string &p) {
    int n = p.size()-1;
    for(int i = 2, j = 0; i <= n; i++) {
        while(j && p[i] != p[j+1]) j = ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }
}

int kmp(string &s, string &p) {
    int n = s.size()-1, m = p.size()-1, cnt = 0;
    for(int i = 1, j = 0; i <= n; i++) {
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if(j == m) cnt++, j = ne[j];
    }
    return cnt;
}
```

## 2. 字符串哈希
```cpp
ull h[N], p[N];
const ull base = 131;
void init(string &s) {
    int n = s.size()-1;
    p[0] = 1;
    rep(i,1,n) h[i] = h[i-1]*base + s[i], p[i] = p[i-1]*base;
}
ull get(int l, int r) {
    return h[r] - h[l-1] * p[r-l+1];
}
```

---

# 七、STL 高频用法（竞赛必熟）
```cpp
vector          // 动态数组
stack / queue   // 栈、队列
priority_queue  // 堆
set / map       // 有序集合、映射
unordered_set/map  // 哈希表
lower_bound/upper_bound  // 二分
__gcd(a,b)      // C++17 内置最大公约数
__builtin_popcount(x)  // 二进制 1 的个数
__builtin_ctz(x)       // 末尾 0 的个数
```

---

# 八、常用小技巧
- 无穷大：`0x3f3f3f3f`
- 取模防负：`(a % mod + mod) % mod`
- 交换：`swap(a,b)`
- 排序：`sort(a+1,a+n+1)`
- 去重：`sort + unique + erase`
- memset 只能赋值 0 / -1 / 0x3f

---

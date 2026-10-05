#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int a[MAXN], n, m, x, y, t = 1;
string name[MAXN];

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> name[i];
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        // 2. 根据方向计算
        if (a[t] == x)
            t -= y;
        else
            t += y;
        //🦖循环调整位置使其在1-n范围内
        //cur = (cur + n + s) % n;异曲同工之妙
        if (t <= 0)
            t += n;
        else if (t > n)
            t -= n;
    }
    cout << name[t] << endl;
    return 0;
}
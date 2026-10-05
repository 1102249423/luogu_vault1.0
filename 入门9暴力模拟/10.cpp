#include <bits/stdc++.h>
using namespace std;

// 0~9所需火柴数量
int stick[] = {6,2,5,5,4,5,6,3,7,6};//🦖

// 计算数字x一共需要几根火柴
int count_stick(int x)
{
    // 特判数字0
    if (x == 0)
        return stick[0];
    int res = 0;
    while (x > 0)
    {
        res += stick[x % 10];
        x /= 10;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    // + 和 = 一共占用4根火柴
    int need = n - 4;
    int ans = 0;

    // 枚举A、B；上限开到1000足够覆盖 n<=24 全部情况
    for (int A = 0; A <= 1000; A++)
    {
        for (int B = 0; B <= 1000; B++)
        {
            int C = A + B;
            if (count_stick(A) + count_stick(B) + count_stick(C) == need)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
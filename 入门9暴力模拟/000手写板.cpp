#include <bits/stdc++.h>
using namespace std;
#define ll long long//🦖学习了define
//🦖C++ 标准中：普通变量不能作为静态数组的长度，必须是编译期常量，所以要用 const。
const int kMaxn = 1e6 + 10;//🦖学习了常量命名规则
const ll kMod = 1e9 + 7;
//n 木棒总根数，ans方案总数，maxa所有木棒最长的长度，a[]：保存每一根木棒的长度，num[x]：桶数组，num[x] = 长度等于x的木棒一共有多少根
ll n, ans, maxa, a[kMaxn], num[kMaxn];

ll C0(ll x, ll k) {
    //求得从n个数中取出k个数的组合
    //此处k=1 / 2，用了特判写法。
    //k = 1 时，C(x, 1) = x;
    //k = 2 时，C(x, 2) = x * (x - 1) / 2;
    return (k == 1ll ? x : x * (x - 1ll) / 2ll) % kMod;//🦖三元运算符等价于if else
}
//完全等价
ll C(ll x, ll k) {
    ll res;
    if(k == 1) res = x;
    else if(k == 2) res = x * (x - 1) / 2;
    //else if(k == 3) res = x * (x - 1) * (x - 2) / 6;
    return res % kMod;
}
int main() {
    cin>>n;
    for (int i = 1; i <= n; ++ i) {
        cin>>a[i];
        maxa = max(a[i], maxa);//🦖
        num[a[i]] ++;//🦖
    }
    //🦖只能%一下大佬了，什么时候才能到这种程度QAQ
    for (int i = 2; i <= maxa; ++ i) { //枚举两根相等的边
        if (num[i] >= 2ll) {
            ll times = C(num[i], 2ll) % kMod; //求出组合数
            for (int j = 1; j <= i / 2; ++ j) { //枚举被合成的边(到i / 2即可)
                if (j != i - j && num[j] >= 1 && num[i - j] >= 1) //用来合成的木棒长度不等
                    ans += times * C(num[j], 1) * C(num[i - j], 1) % kMod;
                if (j == i - j && num[j] >= 2) //用来合成的木棒长度相等
                    ans += times * C(num[j], 2) % kMod;
                ans %= kMod;
            }
        }
    }
    printf("%lld", ans);
    return 0;





}
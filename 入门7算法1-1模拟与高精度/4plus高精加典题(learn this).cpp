#include <bits/stdc++.h>
using namespace std;
//高精加函数返回string
string add(string a,string b){
    string out="";
    //🦖经典写法
    int len=max(a.size(),b.size()),jinwei=0;
    while (a.size() < len) a = '0' + a;
    while (b.size() < len) b = '0' + b;

    for (int i = len - 1; i >= 0; i--)
    {
        int t1 = a[i] - '0', t2 = b[i] - '0';
        int t = t1 + t2 + jinwei;
        jinwei = t / 10;
        t %= 10;
        char ch = t + '0';
        out = ch + out;
    }
    //999+1=‘1’+000
    if (jinwei != 0) return '1' + out;
    return out;
}
signed main()
{
    //C++ 加速三剑客
    //关闭 cin /cout 和 C 语言 scanf /printf 的同步
    ios::sync_with_stdio(0);
    //解开 cin 和 cout 的绑定
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    cout << add(s1, s2);
    return 0;
}
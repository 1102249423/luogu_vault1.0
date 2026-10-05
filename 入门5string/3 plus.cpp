#include<bits/stdc++.h>
using namespace std;
//两种不同的写法而已。
bool prime(int x) {
    if (x < 2) return false;

    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

bool isprime(int n){
    if(n==0) return false;
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

//NT_MIN：表示 C++ 中 int 类型能存储的最小整数（通常是 -2147483648）；
//INT_MAX：表示 C++ 中 int 类型能存储的最大整数（通常是 2147483647）。
string s;
int ma = INT_MIN, mi = INT_MAX;
int sum[1005];

int main() {
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        sum[s[i]]++;//🦖当你把字符（比如 s[i]）放在数组下标位置时，编译器会自动把它转换成对应的 ASCII 码整数，再作为下标使用。
    }

    for (int i = 0; i < s.size(); i++) {
        ma = max(ma, sum[s[i]]);
        mi = min(mi, sum[s[i]]);
    }

    if (prime(ma - mi)) {
        cout << "Lucky Word" << endl << ma - mi;
    } else {
        cout << "No Answer" << endl << 0;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
//布尔数组，标记某个数是否为素数，1 代表是素数，0 代表不是。数组大小 100000010 表示最多能筛到 1 亿。
bool isPrime[100000010];
//整型数组，按顺序存储筛选出的素数（比如 Prime[1]=2，Prime[2]=3，Prime[3]=5...）。数组大小 6000010 是因为 1 亿以内的素数约有 5761455 个，预留足够空间。
//cnt是质数的计数（同时作为Prime数组的下标）
int Prime[6000010],cnt=0;
void GetPrime(int n){
    memset(isPrime, 1, sizeof(isPrime));//🦖以“每个数都是素数”为初始状态，逐个删去
    isPrime[1] = 0;//1不是素数
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            Prime[++cnt]=i;
        }
        for(int j=1;j<=cnt&& i*Prime[j]<=n;j++){
            isPrime[i*Prime[j]] = 0;//筛选出i*Prime[j]的因子。
            if(i % Prime[j] == 0)//i中也含有Prime[j]这个因子
                break; //保证每个合数只被它的最小质因数筛掉一次，从而实现 O(n) 的线性时间复杂度。
            //i=6，isPrime[6]=0（已被筛过），所以不会加入 Prime 数组，
            //6=2×3，2 是 6 的最小质因数；如果继续 j=2（Prime [2]=3），会计算 6×3=18，标记 isPrime [18]=0，但 18 的最小质因数是 2，应该留给 i=9（9=3×3）、j=1（Prime [1]=2）时，计算 9×2=18 来标记 → 避免重复。
        }
    }
}
int main() {
    int n;
    cin >> n;
    GetPrime(n);

    // 🦖（写得好啊）遍历 4~n 所有偶数
    for (int i = 4; i <= n; i += 2) {
        // 找第一个最小的质数 j，使得 i-j 也是质数
        for (int j = 2; j <= i / 2; j++) {
            if (isPrime[j] && isPrime[i - j]) {
                cout << i << "=" << j << "+" << i - j << endl;
                break; // 找到立刻退出，保证最小 j
            }
        }
    }
    return 0;
}